#pragma once
#include <string>
#include "SDL.h"

class TextureManager
{
public:
	static TextureManager& getInstance();
	bool load(std::string id, std::string fileName);    
	void drop(std::string id);
	bool draw(std::string id, SDL_Renderer* _renderer, int x, int y, int width, int height, SDL_RendererFlip flip);
	bool draw_frame(std::string id, SDL_Renderer* _renderer, int x, int y, int width, int height, int current_frame, int current_row, SDL_RendererFlip flip);
	void clean();

private:
	TextureManager();
	~TextureManager();
	


};

