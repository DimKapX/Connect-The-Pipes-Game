#include <iostream>
#include "sgg/graphics.h"
#include "gamestate.h"
#include <string>

#define SETCOLOR(c, r, b ,g) {c[0]=r; c[1]=g; c[2]=b;}

void init() {
	GameState::getInstance()->init();
}

void draw() {
	GameState::getInstance()->draw();
}

void update(float dt) {
	GameState::getInstance()->update(dt);
}


int main(int argc, char** argv) {
	
	graphics::createWindow(1200, 900, "Window.exe");

	init();

	graphics::setDrawFunction(draw); //that way we can draw the element draw()
	graphics::setUpdateFunction(update);

	graphics::setCanvasSize(GameState::getInstance()->getCanvasWidth(), GameState::getInstance()->getCanvasHeight());
	graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);
	//graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_STRETCH);

	graphics::startMessageLoop();

	return 0;
}