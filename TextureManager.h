#pragma once
#include <string>
#include "SDL.h"

class TextureManager
{
public:
	static TextureManager& getInstance();
	bool Load(std::string id, std::string fileName);

private:
	TextureManager();
	~TextureManager();
	

};

