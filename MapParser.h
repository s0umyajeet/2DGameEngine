#pragma once

#include <tinyxml.h>
#include <map>

#include <string>
#include "GameMap.h"
#include "TileLayer.h"

class MapParser
{

public:
	static MapParser& getInstance() {
		static MapParser instance;
		return instance;
	}

	bool load();
	GameMap* getMaps(std::string mapID);

private:
	//parse master function
	bool Parse(std::string mapID, std::string source);
	
	//Parse the tilesets
	Tileset parseTileset(TiXmlElement* XMLTilesetElem);
	
	//Parse Tile layers (layers of the map)
	//We return TileLayer* because it is going to be
	//stored in a vector<Layer*> (GameMap.h)
	TileLayer* parseTileMap(TiXmlElement* XMLTileLayerElem, 
				std::vector<Tileset> Tilesets,
		                int tileSize, int numRows, int numCols);

private:
	//singleton
	MapParser();

	//move to GameMap class ???
	std::map<std::string, GameMap*> gameMapDict;

};

