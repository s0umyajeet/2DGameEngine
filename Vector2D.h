#pragma once
#include <iostream>

class Vector2D {
public:
	float x;
	float y;

	//constructor
	Vector2D(int X, int Y) : x(X), y(Y) {}	
	
	//+ operator overload
	inline Vector2D operator+(const Vector2D& v) {
		return Vector2D(v.x + this->x, v.y + this->y);
	}

	//-operator overload
	inline Vector2D operator-(const Vector2D& v) {
		return Vector2D(v.x - this->x, v.y - this->y);
	}

	void printVector() {
		std::cout << "(" << x << "i + " << y << "j)" << std::endl;
	}
};

