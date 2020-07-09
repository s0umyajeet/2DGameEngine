#include "TextureManager.h"

bool TextureManager::load(std::string id, std::string fileName)
{
	return false;
}

void TextureManager::drop(std::string id)
{
}

bool TextureManager::draw(std::string id, SDL_Renderer* _renderer, int x, int y, int width, int height, SDL_RendererFlip flip)
{
	return false;
}

bool TextureManager::draw_frame(std::string id, SDL_Renderer* _renderer, int x, int y, int width, int height, int current_frame, int current_row, SDL_RendererFlip flip)
{
	return false;
}

void TextureManager::clean()
{
}
