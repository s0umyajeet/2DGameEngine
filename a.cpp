// SDL_Trial.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SDL.h"
#include <vector>
#include <random>
struct RGB {
    int r;
    int g;
    int b;
} ;
std::vector<RGB>v(1000);
int main(int argc, char* argv[])
{
    srand(0);
    SDL_Renderer* _renderer = NULL;
    SDL_Window*   _window    = NULL;
    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
        std::cout << "Hello World!\n";
        if (_window = SDL_CreateWindow("First Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 640, 0)) {
            std::cout << "Window Created!" << std::endl;

            for (int i = 0; i < 1000; i++) {
                v[i] = { rand() % 255, rand() % 256, rand() % 255 };
            }
            if (_renderer = SDL_CreateRenderer(_window, 1, 0)) {
                std::cout << "Renderer created successfully!" << std::endl;
                for (int i = 0 ; i < 1000 ; i++)
                {
                    SDL_SetRenderDrawColor(_renderer, v[i].r, v[i].g, v[i].b, 1);
                    SDL_RenderClear(_renderer);
                    SDL_RenderPresent(_renderer);
                    SDL_Delay(500);

                }
                //SDL_RenderCopy()
            }
            else {
                std::cout << "Failed to create a renderer " << SDL_GetError() << std::endl;
            }
        }
        else {
            std::cout << "Failed to create a window " << SDL_GetError() << std::endl;
        }
    }
    else std::cout << "Failed to load subsystems" << std::endl;
    
    //int t = 1;
    //while (t) {
    //    
    //    //SDL_RenderClear(_renderer);
    //    SDL_RenderPresent(_renderer);
    //    
    //}
    return 0;
}
        
