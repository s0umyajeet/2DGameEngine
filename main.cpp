#include <iostream>
#include <string>
#include "SDL.h"
#include "Game.h"

Game* game = NULL;

int main(int argc, char* argv[]) {
	game = new Game();
	bool fullscreen = false;
	
	game->init("Game 1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 480, 480, fullscreen);

	while (game->isRunning()) {
		game->handleEvents();
		game->update();
		game->render();
	} 
	game->clean();
	delete game;
	return 0;
}