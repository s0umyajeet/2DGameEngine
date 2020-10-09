#include <iostream>
#include "TextureManager.h"
#include "SDL_image.h"
#include "Engine.h"

TextureManager& TextureManager::getInstance()
{
	static TextureManager instance;
	return instance;
}

TextureManager::TextureManager() {}
TextureManager::~TextureManager() {}

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
		//SDL_DestroyTexture(temp_texture);
		return true;
	}
}

void TextureManager::drop(std::string id)
{
	SDL_DestroyTexture(_texture_map[id]);
	_texture_map.erase(id);
	std::cout << "Texture with id: " << id << " removed from texture map successfully..." << std::endl;
}

bool TextureManager::draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE)
{
	if (Engine::getInstance().getRenderer() == NULL) {
		std::cout << "Error empty renderer/renderer pointing to NULL passed...";
		return false;
	} else {
 
		SDL_Rect src_rect = { 0, 0, width, height };
		SDL_Rect dest_rect = { x, y, width, height };

		if (width == 0 && height == 0) {
			if (SDL_RenderCopyEx(Engine::getInstance().getRenderer(), _texture_map[id], NULL, NULL, 0, 0, flip) == 0) {
				std::cout << "RenderCopyEx success..." << std::endl;
				return true;
			} else {
				std::cout << "RenderCopyEx failed... String id: " << id << " Error: " << SDL_GetError() << std::endl;
			}
		} else {
			if (SDL_RenderCopyEx(Engine::getInstance().getRenderer(), _texture_map[id], &src_rect, &dest_rect, 0, 0, flip) >= 0) {
				std::cout << "RenderCopyEx success..." << std::endl;
				return true;
			}
			else {
				std::cout << "Failure in RenderCopyEx() String id: " << id << " Error: " << SDL_GetError() << std::endl;
				TextureManager::util_show_texture_map();
				return false;
			}
		}
	}
}

bool TextureManager::draw_frame(std::string id, int x, int y, int width, int height, int current_frame, int current_row, SDL_RendererFlip flip)
{
	SDL_Rect src_rect;
	SDL_Rect dest_rect;

	src_rect = { width * current_frame, height * (current_row - 1), width, height };
	dest_rect = { x, y, width, height };
	

	SDL_RenderCopyEx(Engine::getInstance().getRenderer(), _texture_map[id], &src_rect, &dest_rect, 0, 0, flip);
	return false;
}

bool TextureManager::draw_tile(std::string id, int x, int y, int tilesize, int current_frame, int current_row, SDL_RendererFlip flip)
{
	SDL_Rect dstRect = { x, y, tilesize, tilesize };
	SDL_Rect srcRect = { tilesize * current_frame, tilesize * (current_row - 1), tilesize, tilesize };
	SDL_RenderCopyEx(Engine::getInstance().getRenderer(), _texture_map[id], &srcRect, &dstRect, 0, NULL, flip);
	return false;
}

void TextureManager::util_show_texture_map()
{
	for (auto itr = _texture_map.begin(); itr != _texture_map.end(); itr++) {
		std::cout << itr->first << " " << itr->second << std::endl;
	}
}

void TextureManager::clean()
{
	for (auto itr = _texture_map.begin(); itr != _texture_map.end(); itr++) {
		SDL_DestroyTexture(itr->second);
	}
	_texture_map.clear();
	std::cout << "Texture map cleared successfully..." << std::endl;
}
