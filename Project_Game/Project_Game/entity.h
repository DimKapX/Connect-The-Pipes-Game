#pragma once
#include "gameobject.h"
#include "box.h"


struct EntityConstants {
	float gravity;
	float accel_vertical;
	float accel_horizontal;
	float max_velocity;
};

class Entity : public GameObject{
protected:	

	//const EntityConstants constants;
	Box* hitbox;
	int health;
	int max_health;

	graphics::Brush entity_brush;

	graphics::Brush entity_brush_debug;
	graphics::Brush entity_text_debug;

	virtual void move(float dt) {}
public:

	/*
	explicit Entity(const EntityConstants& c)
        : constants(c) {}
	*/

	float velocity_x = 0.0f;
	float velocity_y = 0.0f;

	int getHealth() const{ return health; }
	void setHealth(int h) { health = h; }
	int getMaxHealth() const { return max_health; }
	int setMaxHealth(int mh) { max_health = mh; }

	Box* getHitbox() { return hitbox; }

	Entity(float position_x, float position_y, float width, float height, int mh, int h) 
					:hitbox(new Box(position_x, position_y, width, height)), max_health(mh), health(h) {}
};