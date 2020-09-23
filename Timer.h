#pragma once
constexpr auto TARGET_FPS = 60;
constexpr auto TARGET_DT = 1.5f;

class Timer
{
public:	
	//get the singleton instance 
	static Timer& getInstance();
		
	void Tick();

	inline float getDeltaTime() { return this->_dt; }

private:
	//constructor private for singleton
	Timer();
	float _dt;	//delta time
	float _prevTime;
};

