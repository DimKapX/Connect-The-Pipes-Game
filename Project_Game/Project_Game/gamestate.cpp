#include "gamestate.h"
#include "gamelevel.h"
#include "platform.h"
#include "player.h"
#include <chrono>
#include <thread>
#include <iostream>

#define LEFT_PLATFORM "Tile_14.png" 
#define MIDDLE_PLATFORM_1 "Tile_15.png" 
#define MIDDLE_PLATFORM_2 "Tile_16.png" 
#define RIGHT_PLATFORM "Tile_17.png" 

#define PLATFORM_WIDTH 0.8f
#define PLATFORM_HEIGHT 0.8f

GameState* GameState::unique_instance = nullptr;

GameState::GameState()
{
}

GameState::~GameState()
{
	for(auto& level : levels) {
		if (level) {
			delete level;
			level = nullptr;
		}
	}
	levels.clear();

	if (player) {
		delete player;
		player = nullptr;
	}
}

void GameState::init()
{
	graphics::setFont(getFullAssetPath("fonts/PixelPurl.ttf"));

	std::vector<GameObject*> static_objects;
	std::list<GameObject*> dynamic_objects;

	static_objects.push_back(new Platform(2.2f,7.8f,PLATFORM_WIDTH,PLATFORM_HEIGHT,LEFT_PLATFORM));

	int i;
	for(i = 0; i < 30; i++) {
		static_objects.push_back(new Platform(3.0f + i * 0.8f, 7.0f, PLATFORM_WIDTH, PLATFORM_HEIGHT, MIDDLE_PLATFORM_1));
	}
	i = 9;
	static_objects.push_back(new Platform(i * 0.8f * 4, 7.8f, PLATFORM_WIDTH, PLATFORM_HEIGHT, RIGHT_PLATFORM));
	levels.push_back(new GameLevel(static_objects,dynamic_objects));

	if (!levels.empty()) {
		current_level = 0;                     
		levels[current_level]->init();
	}
	else {
		current_level = -1;
	}

	player = new Player();
	player->init();
	
	graphics::preloadBitmaps(getAssetDir());
}

void GameState::draw()
{
	if (current_level < 0 || current_level >= static_cast<int>(levels.size()))
		return;

	levels[current_level]->draw();

	player->draw();
}

void GameState::update(float dt)
{
	if (dt > 500)
		return;

	float sleep_time = std::max(0.0f, 17.0f - dt);

	std::this_thread::sleep_for(std::chrono::duration<float, std::milli>(sleep_time));

	if (current_level < 0 || current_level >= static_cast<int>(levels.size()))
		return;

	levels[current_level]->update(dt);
	player->update(dt);
	
	graphics::getMouseState(mouse);
	debug_mode = graphics::getKeyState(graphics::SCANCODE_F1);
	
}

Player* GameState::getPlayer() const
{
	return player;
}

GameState* GameState::getInstance()
{
	if (unique_instance == nullptr)
		unique_instance = new GameState();

	return unique_instance;
}

float GameState::getCanvasWidth()
{
	return canvas_width;
}

float GameState::getCanvasHeight()
{
	return canvas_height;
}

std::string GameState::getAssetDir()
{
	return asset_path;
}

std::string GameState::getFullAssetPath(const std::string& path)
{
	return asset_path + path;
}
