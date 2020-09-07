#pragma once
#include "Vector2D.h"

class Transform {
public:
	float m_X;
	float m_Y;

	//Constructor
	Transform(float X = 0, float Y = 0) : m_X(X), m_Y(Y) {}

	//Translate in X
	void translateX(float x) { this->m_X += x; }
	//Translate in Y
	void translateY(float y) { this->m_Y += y; }
	//Tranlate in X, Y
	void translate(Vector2D v) { this->m_X += v.x, this->m_Y += v.y; }

	//Show transformation
	void printTransform() {
		std::cout << "(" << m_X << "i + " << m_Y << "j)" << std::endl;
	}
};

