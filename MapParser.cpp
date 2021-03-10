#include "MapParser.h"
#include <sstream>

bool MapParser::load()
{
	return Parse("level_2", "assets/maps/level_2.tmx"); 
} 

GameMap* MapParser::getMap(std::string mapID) 
{
	return gameMapDict[mapID];
}

bool MapParser::Parse(std::string mapID, std::string source)
{
	TiXmlDocument xml;
	xml.LoadFile(source);

	if (xml.Error()) {
		std::cout << "Failed to load the source [" << source << "] " << std::endl;
		return false;
	}

	//if everything is alright
	TiXmlElement* root = xml.RootElement();
	if (root == NULL) {
		std::cout << "Quitting" << std::endl;
		return false;
	}

	int rowCount, colCount, tileSize = 0;
	
	//add xml elements later REMEMBER!!!!!
	root->Attribute("height", &rowCount);
	root->Attribute("width", &colCount);
	root->Attribute("tileWidth", &tileSize);

	//parse all tilesets

	std::vector<Tileset> tileSetVecTemp;

	for (TiXmlElement* e = root->FirstChildElement(); e != NULL; e = (TiXmlElement*)e->NextSibling()) {
		if (e->Value() == std::string("tileset")) {
			tileSetVecTemp.push_back(parseTileset(e));
		}
	}

	GameMap* tempGameMap = new GameMap();
	for (TiXmlElement* e = root->FirstChildElement(); e != NULL; e = (TiXmlElement*)e->NextSibling()) {
		if (e->Value() == std::string("layer")) {
			TileLayer* tempTileLayer = parseTileMap(e, tileSetVecTemp, tileSize, rowCount, colCount);
			tempGameMap->Layers.push_back(tempTileLayer);
		}
	}

	gameMapDict[mapID] = tempGameMap;
	return true;	
}

Tileset MapParser::parseTileset(TiXmlElement* XMLTilesetElem)
{
	Tileset temp;
	
	//add xml elements later REMEMBER!!!!!
	temp.name = XMLTilesetElem->Attribute("name");
	XMLTilesetElem->Attribute("firstgid", &temp.startID);
	XMLTilesetElem->Attribute("tilecount", &temp.tileCount);
	
	for (TiXmlElement* e = XMLTilesetElem->FirstChildElement(); e != NULL; e = (TiXmlElement*)e->NextSibling()) {
		if (e->Value() == std::string("image")) {
			temp.source = e->Attribute("source");
			break;
		}
	}

	temp.endID = (temp.startID + temp.tileCount) - 1;
	XMLTilesetElem->Attribute("columns", &temp.numCols);
	temp.numRows = temp.tileCount / temp.numCols;
	XMLTilesetElem->Attribute("tilewidth", &temp.tileSize);

	return temp;
}

TileLayer* MapParser::parseTileMap(TiXmlElement* XMLTileLayerElem, std::vector<Tileset> tilesets, int tileSize, int numRows, int numCols)
{
	TiXmlElement* data = NULL;
	for (auto x = XMLTileLayerElem->FirstChild(); x != NULL; x = x->NextSibling()) {
		if (x->Value() == std::string("data")) {
			data = (TiXmlElement*) x;
			break;
		}
	}

	//Parse data from tileMap
	std::string map;
	if (data) map = (data->GetText());
	std::stringstream ss(map);
	std::string line;

	std::vector<std::vector<int>>
		tileMap(numRows, std::vector<int>(numCols, 0));
	 
	for (int row = 0; row < numRows; row++) {
		for (int col = 0; col < numCols; col++) {
			getline(ss, line, ',');
			tileMap[row][col] = stoi(line);
		}
	}

	//Complete it after modifying the ctor
	return (new TileLayer(tileSize, numRows, numCols, tileMap, tilesets));
}
