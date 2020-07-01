#include <iostream>
#include "SDL.h"

int main(int argc, char* argv[]) {
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		std::cout << "All subsystems initialized successfully..." << std::endl;
	} else {
		std::cout << "Error initializing subsystems..." << std::endl;
		std::cout << "Error: " << SDL_GetError() << std::endl;
	}
	return 0;
}