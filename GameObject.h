#pragma once
#include "IObject.h"
#include "Transform.h"
#include "TextureManager.h"
#include "SDL.h"
#include <string>

//for easy management of GameObject properties
class Properties {
public:
	//Constructor
	Properties(std::string textureID, int width, int height, int X, int Y, SDL_RendererFlip flip)
		: m_textureID(textureID), m_width(width), m_height(height), m_X(X), m_Y(Y), m_flip(flip) {}
public:
	std::string m_textureID;
	int m_width;
	int m_height;
	int m_X;
	int m_Y;
	SDL_RendererFlip m_flip;
};

//All game objects will inherit from the IObject interface
class GameObject : public IObject
{
public:
	//Constructor
	GameObject(Properties* props)
		: m_textureID(props->m_textureID), m_width(props->m_width), m_height(props->m_height), 
		m_flip(props->m_flip) 
	{
		m_transform = new Transform(props->m_X, props->m_Y);
	}

	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clear() = 0;

protected:
	std::string m_textureID;
	int m_width;
	int m_height;
	Transform* m_transform;
	SDL_RendererFlip m_flip;
};

