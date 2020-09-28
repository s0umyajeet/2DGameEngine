#pragma once

#include "Layer.h"
#include <vector>

class GameMap {
public:
	GameMap() = default;
	void Render() { for (auto x : Layers) x->Render(); }
	void Update() { for (auto x : Layers) x->Update;   }
	inline std::vector<Layer*> getLayers() { return this->Layers; }

private:
	std::vector<Layer*> Layers;
};
