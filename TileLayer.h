#pragma once
#include "Layer.h"
#include <string>
#include <vector>

//We use tilesets to draw each layer
struct Tileset {
	//each element of the Tileset will be 
	//later accessed based on its ID
	//each tile in the tileset has its ID
	//which is nothing but its position 
	//in the 2D matrix of tileset

	//we need to know the start and end of 
	//these IDs because the next layer's 
	//start will be the previous layer's 
	//start + 1

	int startID;
	int endID;
	int numRows;
	int numCols;
	int tileCount;		//total number of tiles in the tileset
	int tileSize;		//size of one tile in the tileset 
				//(usually 32x32)
	std::string name;
	std::string source;

};


class TileLayer : public Layer
{
public:
	virtual void Render();
	virtual void Update();
private:
	//number of rows and columns in the layer
	int numRows;
	int numCols;

	//size of tile in this layer
	int tileSize;

	//vector containing all Tilesets
	//shift to Tileset struct ???
	std::vector<Tileset> TilesetVec;

	//TileMap for this layer
	//Each layer in a scene has its 
	//different TileMap
	std::vector<std::vector<int>> TileMap;
};

