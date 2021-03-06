#include "Warrior.h"
#include "TextureManager.h"
#include "Engine.h"

Warrior::Warrior(Properties* props) 
	: Character(props)
{
	m_currentFrame = 0;
	m_currentRow = 1;

	m_frameCount = 6;
	m_rowCount = 1;
	
	m_framesPerSecond = 80;
}

void Warrior::draw()
{
	TextureManager::getInstance().draw_frame(m_textureID, m_transform->m_X, m_transform->m_Y, m_width, m_height, m_currentRow, m_currentFrame, SDL_FLIP_NONE);
}

void Warrior::update(float dt)
{
	m_currentFrame = (SDL_GetTicks() / m_framesPerSecond) % m_frameCount;
}


void Warrior::clear()
{
	TextureManager::getInstance().clean();
}
