#pragma once
#include "SDL.h"
#include <string>
#include <Windows.h>
#include <SDL_image.h>
#include "TextureManager.h"
#include "EventHandler.h"
 
class Engine {
public:
	static Engine& getInstance();
	SDL_Renderer* getRenderer();
	bool init(const char* title, int x_pos, int y_pos, int width, int height, bool fullscreen);
	void update();
	void render();
	void handleEvents();
	inline bool isRunning() { return this->_is_running; }
	void clean();
	void Quit();

private:
	Engine();
	~Engine();
	
	SDL_Window*	_window;
	SDL_Surface*	_surface;
	SDL_Texture*	_texture;
	SDL_Renderer*	_renderer;
	SDL_Rect        _source_rect;
	SDL_Rect        _dest_rect;
	bool		_is_running;

};
