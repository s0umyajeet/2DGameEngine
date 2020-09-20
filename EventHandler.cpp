#include "EventHandler.h"
#include "Engine.h"

EventHandler::EventHandler() {
	_keyStates = NULL;
}

void EventHandler::keyUp()
{
	_keyStates = SDL_GetKeyboardState(NULL);

}

void EventHandler::keyDown()
{
	_keyStates = SDL_GetKeyboardState(NULL);
}

EventHandler& EventHandler::getInstance() {
	static EventHandler instance;
	return instance;
}

void EventHandler::listen()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) { 
		switch (event.type) {
		case SDL_QUIT:
			Engine::getInstance().Quit();
			break;
		case SDL_KEYDOWN:
			keyDown();
			break;
		case SDL_KEYUP:
			keyUp();
			break;
		}
	}
}

bool EventHandler::isKeyDown(SDL_Scancode key)
{
	if (_keyStates != NULL) {
		return _keyStates[key];
	}
	else return false;
}

