#pragma once
#include <sgg/graphics.h>
#include "gameobject.h"
#include "box.h"

class Button : public GameObject, public Box {
private:
	graphics::Brush button_brush;
	graphics::Brush button_brush_debug;
public:
	Button(float x, float y, float w, float h);
	
	void update(float dt) override;
	void init() override;
	void draw() override;
};