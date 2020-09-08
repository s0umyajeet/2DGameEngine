#pragma once
#include "Character.h"

class Warrior : public Character
{
public:
	//Constructor
	Warrior(Properties* props);		

	//I am still keeping these virtual in case I wanna create sub classes of warriors to implement
	//different types of warriors. 
	virtual void draw();
	virtual void update(float dt);
	virtual void clear();
	
public:
	int m_currentRow;		//Current row in the sprite sheet
	int m_currentFrame;		//Current frame in the sprite sheet

	int m_rowCount;		//Number of rows in the sprite sheet for this character
	int m_frameCount;	//number of frames in the sprite sheet for this character

	int m_framesPerSecond;	//For controlling frames per second 
};

