#include "player.h"
#include "util.h"

Player::Player()
	: Entity(GameState::getInstance()->getCanvasWidth() * 0.5f,
		GameState::getInstance()->getCanvasHeight() * 0.5f,
		1.0f, 1.0f, 100, 100)
{
}

void Player::init()
{	
	hitbox->pos_x = 5.0f;
	hitbox->pos_y = 5.0f;

	state->global_offset_x = (state->getCanvasWidth() / 2.0f) - hitbox->pos_x;
	state->global_offset_y = (state->getCanvasHeight() / 2.0f) - hitbox->pos_y;
	
	entity_brush.fill_opacity = 1.0f;
	entity_brush.outline_opacity = 0.0f;
	SETCOLOR(entity_brush.fill_color,1.0f,0.0f,0.0f);
	
	//Debug brushes
	entity_brush_debug.fill_opacity = 0.8f;
	entity_brush_debug.outline_opacity = 1.0f;
	SETCOLOR(entity_brush_debug.fill_color, 0.0f, 0.0f, 0.2f);
	SETCOLOR(entity_text_debug.fill_color, 0.0f, 0.0f, 0.0f);
}

void Player::draw()
{
	float draw_x = hitbox->pos_x + state->global_offset_x;
	float draw_y = hitbox->pos_y + state->global_offset_y;

	std::string entity_text = "Vel_X: " + std::to_string(draw_x) + " Vel_Y: " + std::to_string(draw_y);
	
	if (state->debug_mode) {
		graphics::drawRect(draw_x, draw_y, 1.0f, 1.0f, entity_brush_debug);
		graphics::drawText(draw_x - 1.2f, draw_y - 0.6f, 0.25f, entity_text, entity_text_debug);
	}
	else
		graphics::drawRect(draw_x, draw_y, 1.0f, 1.0f, entity_brush);
}

/*
#include <iostream>
std::cout << "Velocity X:" << velocity_x << "\n";
*/

void Player::move(float dt)
{
	float delta_time = dt / 1000.0f; // Convert milliseconds to seconds

	float move = 0.0f;
	if (graphics::getKeyState(graphics::SCANCODE_LEFT))
		move -= 1.0f; // Move left
	if (graphics::getKeyState(graphics::SCANCODE_RIGHT))
		move += 1.0f; // Move right

	// X-axis
	velocity_x = std::min(max_velocity,velocity_x + move * accel_horizontal * delta_time); // Accelerate based on input (is for both right (positive) and left (negative) direction)
	velocity_x = std::max(-1 * max_velocity, velocity_x); // Cap the velocity to max_velocity in the left (negative) direction
	velocity_x *= 0.92f; // Apply friction to slow down the player

	if (fabs(velocity_x) < 0.09f) 
		velocity_x = 0.0f; // Stop the player if the velocity is very low to prevent sliding
	hitbox->pos_x += delta_time * velocity_x; // Move based on velocity

	//Y-axis
	if (velocity_y == 0.0f) {
		if(graphics::getKeyState(graphics::SCANCODE_UP))
			velocity_y -= accel_vertical; 
		else
			velocity_y -= 0.0f;
	}
	velocity_y += delta_time * gravity;

	hitbox->pos_y += delta_time * velocity_y; // Move based on velocity
}

void Player::update(float dt)
{
	move(dt);
}
