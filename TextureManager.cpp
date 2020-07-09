#include <iostream>
#include "TextureManager.h"
#include "SDL_image.h"
#include "Engine.h"

TextureManager& TextureManager::getInstance()
{
	static TextureManager instance;
	return instance;
}

bool TextureManager::load(std::string id, std::string file_name)
{
	SDL_Surface *temp_surface = IMG_Load(file_name.c_str());

	if (temp_surface == NULL) {
		std::cout << "Error loading image on surface(temp_surface)... : " << SDL_GetError() << std::endl;
		return false;
	}

	SDL_Texture* temp_texture = SDL_CreateTextureFromSurface(Engine::getInstance().getRenderer(), temp_surface);
	SDL_FreeSurface(temp_surface);

	if (temp_texture == NULL) {
		std::cout << "Texture creation failed(temp_texture)..." << SDL_GetError() << std::endl;
		return false;
	} else {
		_texture_map[id] = temp_texture;
		SDL_DestroyTexture(temp_texture);
		return true;
	}
}

void TextureManager::drop(std::string id)
{
	SDL_DestroyTexture(_texture_map[id]);
	_texture_map.erase(id);
	std::cout << "Texture with id: " << id << " removed from texture map successfully..." << std::endl;
}

bool TextureManager::draw(std::string id, SDL_Renderer* _renderer, int x, int y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE)
{
	if (_renderer == NULL) {
		std::cout << "Error empty renderer/renderer pointing to NULL passed...";
		return false;
	}
	else {
		SDL_Rect src_rect = { 0, 0, width, height };
		SDL_Rect dest_rect = { x, y, width, height };

		if (SDL_RenderCopyEx(_renderer, _texture_map[id], &src_rect, &dest_rect, 0, 0, flip) == 0) {
			std::cout << "RenderCopyEx success..." << std::endl;
			return true;

		} else {
			std::cout << "Failure in RenderCopyEx. String id: " << id << " Error: " << SDL_GetError() << std::endl;
			return false;
		}
	}
}

bool TextureManager::draw_frame(std::string id, SDL_Renderer* _renderer, int x, int y, int width, int height, int current_frame, int current_row, SDL_RendererFlip flip)
{
	return false;
}

void TextureManager::clean()
{

}
