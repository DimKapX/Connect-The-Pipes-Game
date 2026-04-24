#pragma once
#include "gamestate.h"

class GameObject {
protected:
    GameState* state = nullptr;
	std::string id = "";
    bool active = false;
public:
	GameObject() { state = GameState::getInstance(); }
	GameObject(const std::string& id) : id(id) { state = GameState::getInstance(); }
    ~GameObject() { if (state) delete state; state = nullptr; }

    virtual void init() {};
    virtual void draw() {};
    virtual void update(float dt) {};

    // I don't think the active below is useful. We'll see
    bool isActive() const { return active; }
    void setActive(bool a) { active = a; }
};