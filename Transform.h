#pragma once
#include "Vector2D.h"

class Transform {
public:
	float x;
	float y;

	//Constructor
	Transform(float X = 0, float Y = 0) : x(X), y(Y) {}

	//Translate in X
	void translateX(float x) { this->x += x; }
	//Translate in Y
	void translateY(float y) { this->y += y; }
	//Tranlate in X, Y
	void translate(Vector2D v) { this->x += v.x, this->y += v.y; }

	//Show transformation
	void printTransform() {
		std::cout << "(" << x << "i + " << y << "j)" << std::endl;
	}
};

