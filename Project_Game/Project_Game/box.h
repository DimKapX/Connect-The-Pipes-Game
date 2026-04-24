#pragma once
#include <cmath>
struct Box {
	float pos_x = 0.0f;
	float pos_y = 0.0f;
	float width = 0.5f;
	float height = 0.5f;

	Box() {}
	Box(float x, float y, float w, float h) : pos_x(x), pos_y(y), width(w), height(h) {}

	bool intersect(const Box& other) const {
		return (fabs(pos_x - other.pos_x) * 2.0f < (width + other.width)) &&
			(fabs(pos_y - other.pos_y) * 2.0f < (height + other.height));
	}

	float intersectDown(const Box& other) const {
		if (fabs(pos_x - other.pos_x) * 2.0f >= (width + other.width) || pos_y > other.pos_y)
			return 0.0f;
		return std::fmin(0.0f, other.pos_y - (other.height / 2.0f) - pos_y - (height / 2.0f));
	}

	float intersectSideways(const Box& other) const {
		if (fabs(pos_y - other.pos_y) * 2.0f >= (width + other.width))
			return 0.0f;
		if (pos_x < other.pos_x)
			return std::fmin(0.0f, other.pos_x - (other.width / 2.0f) - pos_x - (width / 2.0f));
		else
			return std::fmax(0.0f, other.pos_x + (other.width / 2.0f) - pos_x + (width / 2.0f));
	}

	//To Do: contains(x,y)
};