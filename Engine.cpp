#include <iostream>
#include "Engine.h"


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

	if (MapParser::getInstance().load() == false) {
		std::cout << "Error loading map" << std::endl;
		return false;
	}
	

	//test for parallax background

	TextureManager::getInstance().load("BGBack", "assets/Jungle_Pack_2/Background/BGBack.png");
	TextureManager::getInstance().load("BGFront", "assets/Jungle_Pack_2/Background/BGFront.png");
	TextureManager::getInstance().load("CloudsBack", "assets/Jungle_Pack_2/Background/CloudsBack.png");
	TextureManager::getInstance().load("CloudsFront", "assets/Jungle_Pack_2/Background/CloudsFront.png");

	TextureManager::getInstance().load("Layer_0000_9.png", "assets/Layer_0000_9.png");
	TextureManager::getInstance().load("Layer_0001_8.png", "assets/Layer_0001_8.png");
	TextureManager::getInstance().load("Layer_0002_7.png", "assets/Layer_0002_7.png");
	TextureManager::getInstance().load("Layer_0003_6.png", "assets/Layer_0003_6.png");
	TextureManager::getInstance().load("Layer_0004_lights.png", "assets/Layer_0004_lights.png");
	TextureManager::getInstance().load("Layer_0005_5.png", "assets/Layer_0005_5.png");
	TextureManager::getInstance().load("Layer_0006_4.png", "assets/Layer_0006_4.png");
	TextureManager::getInstance().load("Layer_0007_lights.png", "assets/Layer_0007_lights.png");
	TextureManager::getInstance().load("Layer_0008_3.png", "assets/Layer_0008_3.png");
	TextureManager::getInstance().load("Layer_0009_2.png", "assets/Layer_0009_2.png");
	TextureManager::getInstance().load("Layer_0010_1.png", "assets/Layer_0010_1.png");
	TextureManager::getInstance().load("pixel_0.png", "assets/pixel-0.png");
	
	_gameMap = MapParser::getInstance().getMap("level_2");
	std::cout << "Init successful..." << std::endl;
	//Everything initialized successully, start the main loop
	_is_running = true;    
	return true;
}


void Engine::update() 
{
}


void Engine::render()
{
	//clear the renderer
	SDL_RenderClear(_renderer);
	//draw to the screen
	SDL_SetRenderDrawColor(_renderer, 124, 218, 254, 255);
	
	TextureManager::getInstance().draw("awesome_face", 0, 0, 0, 0, SDL_FLIP_NONE);
	TextureManager::getInstance().draw("CloudsBack", 0, 0, 0, 0, SDL_FLIP_NONE);
	TextureManager::getInstance().draw("CloudsFront", 0, 0, 0, 0, SDL_FLIP_NONE);
	TextureManager::getInstance().draw("BGBack", 0, 0, 0, 0, SDL_FLIP_NONE);
	TextureManager::getInstance().draw("BGFront", 0, 0, 0, 0, SDL_FLIP_NONE);

	
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 0);
	/*
	TextureManager::getInstance().draw("Layer_0010_1.png", 0, 0, 0, 0, SDL_FLIP_NONE);
	TextureManager::getInstance().draw("pixel_0.png", 0, 0, 0, 0, SDL_FLIP_NONE);
	TextureManager::getInstance().draw("Layer_0009_2.png", 0, 0, 0, 0, SDL_FLIP_NONE);
	TextureManager::getInstance().draw("Layer_0008_3.png", 0, 0, 0, 0, SDL_FLIP_NONE);
	TextureManager::getInstance().draw("Layer_0007_Lights.ppng", 0, 0, 0, 0, SDL_FLIP_NONE);
	TextureManager::getInstance().draw("Layer_0006_4.png", 0, 0, 0, 0, SDL_FLIP_NONE);
	TextureManager::getInstance().draw("Layer_0005_5.png", 0, 0, 0, 0, SDL_FLIP_NONE);
	TextureManager::getInstance().draw("Layer_0004_Lights.ppng", 0, 0, 0, 0, SDL_FLIP_NONE);
	TextureManager::getInstance().draw("Layer_0003_6.png", 0, 0, 0, 0, SDL_FLIP_NONE);
	TextureManager::getInstance().draw("Layer_0002_7.png", 0, 0, 0, 0, SDL_FLIP_NONE);
	TextureManager::getInstance().draw("Layer_0001_8.png", 0, 0, 0, 0, SDL_FLIP_NONE);
	TextureManager::getInstance().draw("Layer_0000_9.png", 0, 0, 0, 0, SDL_FLIP_NONE);*/
	
	_gameMap->Render();
	SDL_RenderCopy(_renderer, _texture, &_source_rect, NULL);
	SDL_RenderPresent(_renderer);

}

void Engine::handleEvents()
{
	EventHandler::getInstance().listen();
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
