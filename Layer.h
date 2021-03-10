#pragma once

//Layer abstraction
class Layer {
public:
	virtual void Render() = 0;
	virtual void Update() = 0;
};