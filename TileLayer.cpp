#include "TileLayer.h"
#include "TextureManager.h"
#include <iostream>

TileLayer::TileLayer(int tileSize, int numRows, int numCols, 
	std::vector<std::vector<int>> tilemap, std::vector<Tileset> tilesets) 
	: TilesetVec(tilesets) 
{
	this->numRows = numRows;
	this->numCols = numCols;
	this->TileMap = tilemap;

	for (auto i = 0; i < TilesetVec.size(); i++) {
		TextureManager::getInstance().load(
			TilesetVec[i].name, TilesetVec[i].source
		);
	}
}

void TileLayer::Render()
{
	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j < numCols; j++) {
			int tileID = TileMap[i][j];
			
			//render nothing
			if (tileID == 0) continue;
			
			int index = 0;
			if (TilesetVec.size() > 1) {
				for (int k = 1; k < TilesetVec.size(); k++) {
					if (tileID >= TilesetVec[k].startID &&
						tileID < TilesetVec[k].endID) {
						//index found
						index = k;

						tileID = tileID + TilesetVec[k].tileCount - TilesetVec[k].endID;
						//todo: simplify formula
						//check if this works!?
						//tileID -= TilesetVec[k].startID;
						break;
					}
				}
			}

			Tileset ts = TilesetVec[index];
			//pinpointing the tile in the tileset
			int tileInRow = tileID / ts.numCols;
			int tileInCol = tileID - tileInRow * ts.numCols - 1;

			//corner case of last col
			if (tileID % ts.numCols == 0) {
				tileInRow--;
				tileInCol = ts.numCols - 1;
			}

			TextureManager::getInstance().draw_tile(ts.name,
				j * (ts.tileSize), i * (ts.tileSize), ts.tileSize, tileInRow, tileInCol, SDL_FLIP_NONE);
		}
	}
}

void TileLayer::Update()
{
}
