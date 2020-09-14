#include <iostream>
#include "Engine.h"
#include <string>
#include <Windows.h>
#include <SDL_image.h>
#include "TextureManager.h"

Engine::Engine() { 
	_is_running	= true; 
	_window		= NULL;
	_surface	= NULL;
	_texture	= NULL;
	_renderer	= NULL;
}

Engine::~Engine() {}

Engine& Engine::getInstance()
{
	static Engine _engine;
	return _engine;
}

SDL_Renderer* Engine::getRenderer()
{
	return this->_renderer;
}

bool Engine::init(const char* title, int x_pos, int y_pos, int width, int height, bool fullscreen) {
	Uint32 flags = 0;
	time_t curr_time = NULL;
	std::string image_path = "assets/awesome_face.png";

	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		std::cout << "All SDL subsystems initialized successfully... " << std::endl;

		if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) == (1 | 2)) {
			std::cout << "SDL image subsystems initialized successfully..." << std::endl;
		} else {
			std::cout << "SDL image subsystems initialization failed... " << SDL_GetError() << std::endl;
			return false;
		}

		if (_window = SDL_CreateWindow(title, x_pos, y_pos, width, height, flags)) {
			std::cout << "Window created successfully... " << std::endl;
			if (_renderer = SDL_CreateRenderer(_window, -1, 0)) {	
				std::cout << "Renderer created successfully... " << std::endl;
				
				if (TextureManager::getInstance().load("awesome_face", image_path)) {
					std::cout << "Image loading successful..." << std::endl;
				} else {
					std::cout << "Image loading failed..." << std::endl;
				}

			} else {
				std::cout << "Renderer creation failed... " << SDL_GetError() << std::endl;
				return false;
			}
		} else {
			std::cout << "Window creation failed... " << SDL_GetError() << std::endl;
			return false;
		}
	} else {
		std::cout << "Error initializing subsystems... " << SDL_GetError() << std::endl;
		return false;
	}

	std::cout << "Init successful..." << std::endl;
	//Everything initialized successully, start the main loop
	_is_running = true;    
	return true;
}


void Engine::update() 
{
	//int frames = 6;
	//int delay_per_frame = 80;    //ms;
	//int current_frame = (SDL_GetTicks() / delay_per_frame) % frames;

	//_source_rect.x = _source_rect.w * current_frame;
}


void Engine::render()
{
	//clear the renderer
	SDL_RenderClear(_renderer);
	//draw to the screen
	TextureManager::getInstance().draw("awesome_face", 0, 0, 0, 0, SDL_FLIP_NONE);
	//SDL_RenderCopy(_renderer, _texture, &_source_rect, NULL);
	SDL_RenderPresent(_renderer);

}

void Engine::handleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			_is_running = false;
			break;
			default: break;
		}
	}	
}


void Engine::clean()
{
	std::cout << "Cleaning game..." << std::endl;
	SDL_DestroyWindow(_window);
	SDL_DestroyRenderer(_renderer);
	SDL_Quit();
}

void Engine::Quit() {
	std::cout << "Shutting down engine..." << std::endl;
	_is_running = false;
	Engine::clean();
}
