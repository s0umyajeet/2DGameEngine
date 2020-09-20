#pragma once
#include "SDL.h"
#include <vector>

class EventHandler
{
public:
	//returns the singleton instance of the class
	static EventHandler& getInstance();
	//listen to input
	void listen();		
	//key pressed feedback
	bool isKeyDown(SDL_Scancode key);
private:
	//making it a singleton class
	EventHandler();
	void keyUp();
	void keyDown();

	const Uint8 *_keyStates;
	
};

