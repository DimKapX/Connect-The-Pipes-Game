#pragma once
#include <iostream>
#include "gameobject.h"
#include <vector>
#include <list>

class Level : public GameObject {
protected:
	graphics::Brush brush_background;
	std::vector<GameObject*> static_objects;
public:
	virtual void init() override {};
	virtual void draw() override {};
	virtual void update(float dt) override {};

	void addStaticObject(GameObject* obj) {static_objects.push_back(obj);}

	Level(std::vector<GameObject*> st_objs, const std::string& name = "") :GameObject(name) {
		for(auto gob : st_objs) {
			static_objects.push_back(gob);
		}
	};
	~Level() {
		for (auto gob : static_objects) {
			delete gob;
		}
		static_objects.clear();
	}
};
