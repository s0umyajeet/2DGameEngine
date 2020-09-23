#include "Timer.h"
#include "SDL.h"

Timer::Timer() {}

void Timer::Tick() {
	_dt = (SDL_GetTicks() - _prevTime) * (TARGET_FPS / 10000.f);

	if (_dt > TARGET_DT) {
		_dt = TARGET_DT;
	}

	_prevTime = SDL_GetTicks();
}

Timer& Timer::getInstance() {
	static Timer instance;
	return instance;
}