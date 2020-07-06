#pragma once
#include "SDL.h"

class Game {
public:
	Game();
	~Game();
	bool init(const char* title, int x_pos, int y_pos, int width, int height, Uint32 flags);
	void update();
	void render();
	void handleEvents();
	inline bool isRunning() { return this->_is_running; }
	void clean();

private:
	SDL_Window*	_window;
	SDL_Renderer*	_renderer;
	bool		_is_running;

};
