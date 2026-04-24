#include "button.h"
#include <iostream>
#define SETCOLOR(c, r, b ,g) {c[0]=r; c[1]=g; c[2]=b;}

Button::Button(float x, float y, float w, float h): Box(x, y, w, h)
{
}

void Button::init()
{
	SETCOLOR(button_brush.fill_color, 0.0f, 0.8f, 1.0f);
	SETCOLOR(button_brush_debug.fill_color, 0.3f, 0.2f, 5.0f);
}

void Button::draw()
{
	button_brush.outline_opacity = 0.0f;
	graphics::drawRect(pos_x, pos_y, width, height,button_brush);
}

void Button::update(float dt)
{
	float mx = graphics::windowToCanvasX(state->mouse.cur_pos_x);
	float my = graphics::windowToCanvasY(state->mouse.cur_pos_y);
	/*
		if (contains(mx, my) && state->mouse.button_left_down) {
		setActive(true);
		button_brush.fill_opacity = 0.7f;
	}
	else {
		setActive(false);
		button_brush.fill_opacity = 1.0f;
	}
	*/

		
}