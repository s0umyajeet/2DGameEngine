#pragma once
#include "GameObject.h"
#include <string>

class Character : public GameObject {
public:
	//Constructor
	Character(Properties* props) : GameObject(props) {}
	virtual void draw() = 0;
	virtual void update(float dt) = 0;
	virtual void clear() = 0;
public:
	std::string m_name;
};