#include"button.h"
#include "gamelevel.h"
#include "platform.h"
#include "player.h"
#include <iostream>

void GameLevel::init()
{
	brush_background.outline_opacity = 0.0f;

	brush_background.texture = state->getFullAssetPath("game_level.png");

	for (auto& gob : static_objects)
		if (gob)
			gob->init();

	for (auto& gob : dynamic_objects)
		if (gob)
			gob->init();
}

void GameLevel::draw()
{
	float w = state->getCanvasWidth();
	float h = state->getCanvasHeight();

	float offset_x = state->global_offset_x / 2.0f + w / 2.0f;
	float offset_y = state->global_offset_y / 2.0f + h / 2.0f;

	graphics::drawRect(offset_x, offset_y, 2.0f * w, 2.0f * h, brush_background);

	if (state->getPlayer()) // Check if the player exists before trying to draw it 
		//(state->getPlayer()->isActive())
		state->getPlayer()->draw();

	for (auto& gob : static_objects) {
		if (gob) {
			gob->draw();
		}
	}

	for (auto& gob : dynamic_objects) {
		if (gob) {
			gob->draw();
		}
	}
}

void GameLevel::checkCollisions()
{
	float& pos_x = state->getPlayer()->getHitbox()->pos_x;
	float& velocity_x = state->getPlayer()->velocity_x;
	float& pos_y = state->getPlayer()->getHitbox()->pos_y;
	float& velocity_y = state->getPlayer()->velocity_y;

	for (GameObject* gob: static_objects) {
		float offset = 0.0f;
		if (!gob) // Check if the pointer is null before trying to use it
			continue; // Skip this iteration if gob is null
		Platform* platform = dynamic_cast<Platform*>(gob);
		if (platform) {	
			//std::cout << "Checking collision with platform" << "\n";
			if (offset = state->getPlayer()->getHitbox()->intersectDown(*platform)) {
				pos_y += offset;
				velocity_y = 0.0f;
				break;
			}
		}
	}

	for (GameObject* gob : static_objects) {
		float offset = 0.0f;
		if (!gob) // Check if the pointer is null before trying to use it
			continue; // Skip this iteration if gob is null
		Platform* platform = dynamic_cast<Platform*>(gob);
		if (platform) {
			//std::cout << "Checking collision with platform" << "\n";
			if (offset = state->getPlayer()->getHitbox()->intersectSideways(*platform)) {
				pos_x += offset;
				velocity_x = 0.0f;
				break;
			}
		}
	}
}

void GameLevel::update(float dt)
{
	if (state->mouse.button_left_down) {
		state->global_offset_x = (state->getCanvasWidth() / 2.0f) - state->getPlayer()->getHitbox()->pos_x;
		state->global_offset_y = (state->getCanvasHeight() / 2.0f) - state->getPlayer()->getHitbox()->pos_y;
	}
	
	if (!state->getPlayer())
		return;

	state->getPlayer()->update(dt);
	
	checkCollisions();

	for (auto& gob : static_objects)
		if (gob)
			gob->update(dt);

	for (auto& gob : dynamic_objects) {
		if (gob) {
			gob->update(dt);
		}
	}
}

void GameLevel::addDynamicObject(GameObject* obj)
{
	 dynamic_objects.push_back(obj); 
}

GameLevel::GameLevel(std::vector<GameObject*> st_objs, std::list<GameObject*> dy_objs, const std::string& name):Level(st_objs, name)
{
	for (auto gob : st_objs) {
		static_objects.push_back(gob);
	}
}

GameLevel::~GameLevel()
{
	for (auto gob : dynamic_objects) {
		delete gob;
	}
	dynamic_objects.clear();
}
