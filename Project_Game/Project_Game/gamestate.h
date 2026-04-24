#pragma once
#include <sgg/graphics.h>
#include <vector>
#include <string>

class GameState {
private:
	const std::string asset_path = "assets\\";
	
	float canvas_width = 10.0f;
	float canvas_height = 8.0f;

	static GameState* unique_instance;

	GameState();

	class Player* player = nullptr;
	std::vector<class Level*> levels;
	int current_level = 0;

public:
	bool debug_mode;
	graphics::MouseState mouse;
	float global_offset_x = 0.0f;
	float global_offset_y = 0.0f;

	void init();
	void draw();
	void update(float dt);

	static GameState* getInstance();
	~GameState();

	class Player* getPlayer() const;

	float getCanvasWidth();
	float getCanvasHeight();
	std::string getAssetDir();
	std::string getFullAssetPath(const std::string& path);
};