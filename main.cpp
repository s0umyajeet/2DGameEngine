#include <iostream>
#include <string>
#include "SDL.h"
#include "Engine.h"
#include "Timer.h"


int main(int argc, char* argv[]) {
	bool fullscreen = false;
	
	Engine::getInstance().init("Game 1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 960, 640, fullscreen);

	while (Engine::getInstance().isRunning()) 
	{
		Engine::getInstance().handleEvents();
		Engine::getInstance().update();
		Engine::getInstance().render();
		Timer::getInstance().Tick();
	} 

	Engine::getInstance().clean();
	
	return 0;
}



