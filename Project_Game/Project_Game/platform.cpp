#include "platform.h"
#include "player.h"

void Platform::init()
{
	platform_brush.fill_opacity = 1.0f;
	platform_brush.outline_opacity = 0.0f;
	platform_brush.texture = state->getFullAssetPath(texture);
}

void Platform::draw()
{
	graphics::drawRect(pos_x + state->global_offset_x, pos_y + state->global_offset_y, width, height, platform_brush);

}

void Platform::update(float dt)
{
	//what if they are moving?
}

Platform::Platform(float x, float y, float w, float h, const std::string& txture):Box(x,y,w,h),texture(txture)
{
}
