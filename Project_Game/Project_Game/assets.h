#pragma once
#include <sgg/graphics.h>
#include <vector>

//get the SETCOLORS IN HERE!!
enum class SpriteID {
	PLAYER_RUNNING,
	PLAYER_JUMPING,
	PLATFORM,
	ENEMY,
};

struct Sprite {
	std::vector<std::string> frames; //each brush corresponds to a png in the motion
};

Sprite getSprite(SpriteID id) {
	Sprite sprite = {};

	switch (id) {
	case SpriteID::PLAYER_RUNNING:
	{

		for (int i = 0; i < 8; i++) {
			sprite.frames.push_back("assets\\m_character/M_Run_" + std::to_string(i));
		}
		break;
	}
}