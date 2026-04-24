#pragma once
#include "entity.h"	

/*
constexpr EntityConstants PLAYER_CONSTANTS {
	20.0f, 40.0f, 0.0f, 6.0f, 12.0f
};

public:
	Player() : Entity(PLAYER_CONSTANTS) {}
};
*/

class Player : public Entity {
private:
	const float gravity = 10.0f;
	const float accel_vertical = 5.0f;
	const float accel_horizontal = 100.0f;
	const float max_velocity = 3.0f;

	void move(float dt) override;
public:
	Player();

	void init() override;
	void draw() override;
	void update(float dt) override;
};