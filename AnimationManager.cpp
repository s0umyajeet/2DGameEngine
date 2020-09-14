#include "AnimationManager.h"
#include "TextureManager.h"

//Constructor
AnimationManager::AnimationManager() {}

void AnimationManager::update()
{
	m_currentSpriteFrame = (SDL_GetTicks() / m_framesPerSecond) % m_spriteFrameCount;
}

void AnimationManager::draw(float x, float y, int spriteWidth, int spriteHeight)
{	
	TextureManager::getInstance().draw_frame(m_textureID, x, y, spriteWidth, spriteHeight, m_currentSpriteFrame, m_currentSpriteRow, m_flip);
}

void AnimationManager::setProps(std::string textureID, int spriteRow, int frameCount, int framesPerSecond, SDL_RendererFlip flip)
{
	m_textureID = textureID;
	m_currentSpriteRow = spriteRow;
	m_spriteFrameCount = frameCount;
	m_framesPerSecond = framesPerSecond;
	m_flip = flip;
}
