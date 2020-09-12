#pragma once
#include <string>
#include "SDL.h"

//This class will manage animation for each object that would be drawn on the screen
class AnimationManager
{
public:
	AnimationManager();

	void update();
	void draw(float x, float y, int spriteWidth, int spriteHeight);
	void setProps(std::string textureID, int spriteRow, int frameCount, int framesPerSecond, SDL_RendererFlip flip = SDL_FLIP_NONE);
public:
	int m_currentSpriteRow;		//current row in the sprite sheet
	int m_currentSpriteFrame;	//current frame in the sprite sheet
	int m_spriteFrameCount;		//total number of frames in the sprite sheet
	int m_framesPerSecond;		//frames per second
	std::string m_textureID;	//texture ID
	SDL_RendererFlip m_flip;	//flip
};

