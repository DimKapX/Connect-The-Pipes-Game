#pragma once
#include "gameobject.h"
#include "box.h"

class Platform : public GameObject, public Box {
	graphics::Brush platform_brush;
	graphics::Brush platform_brush_debug;
	std::string texture;
public:
	void init() override;
	void draw() override;
	void update(float dt) override;
	
	Platform(float x, float y, float w, float h, const std::string& txture);
};