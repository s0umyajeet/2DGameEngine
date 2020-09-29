#include "MapParser.h"
#include <sstream>

bool MapParser::load()
{
	//add source later
	return Parse("level 1", ""); 
}

GameMap* MapParser::getMaps(std::string mapID) 
{
	return gameMapDict[mapID];
}

bool MapParser::Parse(std::string mapID, std::string source)
{
	TiXmlDocument xml;
	xml.LoadFile(source);

	if (xml.Error()) {
		std::cerr << "Failed to load the source [" << source << "] " << std::endl;
		return false;
	}

	//if everything is alright
	TiXmlElement* root = xml.RootElement();
	int rowCount, colCount, tileSize = 0;
	
	//add xml elements later REMEMBER!!!!!
	root->Attribute("...", &colCount);
	root->Attribute("...", &rowCount);
	root->Attribute("...", &tileSize);

	//parse all tilesets

	std::vector<Tileset> tileSetVecTemp;

	for (auto e = root->FirstChildElement(); e != NULL; e = (TiXmlElement*)e->NextSibling()) {
		if (e->Value() == "tileset") {
			tileSetVecTemp.push_back(parseTileset(e));
		}
	}

	GameMap* tempGameMap = new GameMap();
	for (auto e = root->FirstChildElement(); e != NULL; e = (TiXmlElement*)e->NextSibling()) {
		if (e->Value() == "Layer") {
			TileLayer* tempTileLayer = parseTileMap(e, tileSetVecTemp, tileSize, rowCount, colCount);
			tempGameMap->getLayers().push_back(tempTileLayer);
		}
	}

	gameMapDict[mapID] = tempGameMap;
	return true;	
}

Tileset MapParser::parseTileset(TiXmlElement* XMLTilesetElem)
{
	Tileset temp;
	
	//add xml elements later REMEMBER!!!!!
	temp.name = XMLTilesetElem->Attribute("...");
	XMLTilesetElem->Attribute("...", &temp.startID);
	XMLTilesetElem->Attribute("...", &temp.tileCount);

	temp.endID = (temp.startID + temp.tileCount) - 1;

	XMLTilesetElem->Attribute("...", &temp.numCols);
	temp.numRows = temp.tileCount / temp.numCols;

	XMLTilesetElem->Attribute("...", &temp.tileSize);

	return temp;
}

TileLayer* MapParser::parseTileMap(TiXmlElement* XMLTileLayerElem, std::vector<Tileset> Tilesets, int tileSize, int numRows, int numCols)
{
	TiXmlElement* data;
	for (auto x = XMLTileLayerElem->FirstChild(); x != NULL; x = x->NextSibling()) {
		if (x->Value() == "data") {
			data = (TiXmlElement*) x;
			break;
		}
	}

	//Parse data from tileMap
	std::string map(data->GetText());
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
	return (new TileLayer());
}
