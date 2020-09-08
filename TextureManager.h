#pragma once
#include <string>
#include "SDL.h"
#include <map>

class TextureManager {
public:
	static TextureManager& getInstance();
	bool load(std::string id, std::string fileName);  
	void drop(std::string id);
	bool draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip);
	bool draw_frame(std::string id, int x, int y, int width, int height, int current_frame, int current_row, SDL_RendererFlip flip);
	void util_show_texture_map();
	void clean();

private:
	TextureManager();
	~TextureManager();
	
	std::map <std::string, SDL_Texture*> _texture_map;

};

