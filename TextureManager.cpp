#include <iostream>
#include "TextureManager.h"
#include "SDL_image.h"
#include "Engine.h"

bool TextureManager::load(std::string id, std::string file_name)
{
	SDL_Surface *temp_surface = IMG_Load(file_name.c_str());

	if (temp_surface == NULL) {
		std::cout << "Error loading image on surface(temp_surface)... : " << SDL_GetError() << std::endl;
		return false;
	}

	SDL_Texture* temp_texture = SDL_CreateTextureFromSurface(Engine::getInstance().getRenderer(), temp_surface);

	if (temp_texture == NULL) {
		std::cout << "Texture creation failed(temp_texture)..." << SDL_GetError() << std::endl;
		return false;
	} else {
		_texture_map[id] = temp_texture;
		return true;
	}
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
