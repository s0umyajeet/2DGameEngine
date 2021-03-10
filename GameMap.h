#pragma once

#include "Layer.h"
#include <vector>

class GameMap {
public:
	GameMap() = default;
	virtual void Render() { for (auto &x : Layers) x->Render(); }
	virtual void Update() { for (auto &x : Layers) x->Update(); }
	//inline std::vector<Layer*> getLayers() { return this->Layers; }

public:
	std::vector<Layer*> Layers;
};
