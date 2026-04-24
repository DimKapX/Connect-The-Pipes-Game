#pragma once
#include "level.h"

class GameLevel : public Level{
private:
	std::list<GameObject*> dynamic_objects;
	void checkCollisions();
public:
	virtual void init() override; //if we create separate levels, we can override this function to initialize the level with specific objects and settings
	void draw() override;
	void update(float dt) override;

	void addDynamicObject(GameObject* obj);

	GameLevel(std::vector<GameObject*> st_objs, std::list<GameObject*> dy_objs, const std::string& name = "");
	~GameLevel();
};