#include "stdafx.h"

#include "Data\Map.h"
#include "Data\Node.h"
#include "json\json.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include "Graphics\Sprite.h"

namespace crea
{
	Map::Map()
	{
		m_nWidth = 0;
		m_nHeight = 0;
		m_nTileWidth = 0;
		m_nTileHeight = 0;
		m_bIsGrid8 = false;
		m_pTerrainTileSet = nullptr;
		m_pGM = crea::GameManager::getSingleton();
	}

	Map::~Map()
	{
		clear();
		m_nWidth = 0;
		m_nHeight = 0;
	}

	bool Map::loadFromFileJSON(string& _filename)
	{
		Json::Value root;
		std::ifstream mapStream(_filename, std::ifstream::binary);

		if (mapStream.fail())
		{
			cerr << "Can't open map file: " << _filename << endl;
			return false;
		}

		setName(_filename);

		// Parse file
		mapStream >> root;

		int version = root.get("version", 0).asInt();
		if (version != 1)
		{
			cerr << "Can't parse map if version != 1" << endl;
			return false;
		}

		cout << root.get("width", 10).asInt();
		cout << root.get("height", 10).asInt();
		int iWidth = root.get("width", 10).asInt();
		int iHeight = root.get("height", 10).asInt();
		// Create all nodes
		setSize(iWidth, iHeight);

		m_nTileWidth = root.get("tilewidth", 10).asInt();
		m_nTileHeight = root.get("tileheight", 10).asInt();
		
		// To be completed...
		// Load Layers
		Json::Value layers = root["layers"];

		int i = 0;
		int j = 0;
		for (Json::Value dataValue : layers[0]["data"])
		{
			m_Grid[i][j]->setTileTerrainId(dataValue.asInt());
			i++;
			if (i >= iWidth)
			{
				j++;
				i = i % iWidth;
			}
		}

		// Load Tilesets
		Json::Value tilesets = root["tilesets"][0];

		m_pTerrainTileSet = new TileSet();
		m_pTerrainTileSet->m_nColumns = tilesets["columns"].asInt();
		m_pTerrainTileSet->m_nFirstgid = tilesets["firstgid"].asInt();

		string str = tilesets["image"].asString();
		size_t last = str.find_last_of('/');
		str = str.substr(last + 1);
		m_pTerrainTileSet->m_pSprite = m_pGM->getSprite(str);
		m_pTerrainTileSet->m_pSprite->setTexture(m_pGM->getTexture(str));

		m_pTerrainTileSet->m_nImageheight = tilesets["imageheight"].asInt();
		m_pTerrainTileSet->m_nImagewidth = tilesets["imagewidth"].asInt();
		m_pTerrainTileSet->m_nMargin = tilesets["margin"].asInt();
		m_pTerrainTileSet->m_szName = tilesets["name"].asString();
		m_pTerrainTileSet->m_nSpacing = tilesets["spacing"].asInt();
		m_pTerrainTileSet->m_nTilecount = tilesets["tilecount"].asInt();
		m_pTerrainTileSet->m_nTileheight = tilesets["tileheight"].asInt();
		m_pTerrainTileSet->m_nTilewidth = tilesets["tilewidth"].asInt();

		// Load Terrains
		for (int i = 0; i < 4; i++)
		{		
			Terrain* terrain = new Terrain();
			terrain->m_nTile = tilesets["terrains"][i]["tile"].asInt();
			terrain->m_szName = tilesets["terrains"][i]["name"].asString();
			m_pTerrainTileSet->m_Terrains.push_back(terrain);
		}

		m_TileSet.push_back(m_pTerrainTileSet);

		return true;
	}

	void Map::setSize(short _nWidth, short _nHeight)
	{
		clear();
		m_nWidth = _nWidth;
		m_nHeight = _nHeight;
		m_Grid = new Node**[m_nWidth];
		for (short i = 0; i < m_nWidth; i++)
		{
			m_Grid[i] = new Node*[m_nHeight];
			for (short j = 0; j < m_nHeight; j++)
			{
				m_Grid[i][j] = new Node(i, j);
			}
		}

		// Set Neighbors
		for (short i = 0; i < m_nWidth; i++)
		{
			for (short j = 0; j < m_nHeight; j++)
			{
				if (j != 0)
				{
					m_Grid[i][j]->addChild(m_Grid[i][j - 1]); // top node
				}
				if (m_bIsGrid8 && j != 0 && i != m_nWidth - 1)
				{
					m_Grid[i][j]->addChild(m_Grid[i + 1][j - 1]); // top-right node
				}
				if (i != m_nWidth - 1)
				{
					m_Grid[i][j]->addChild(m_Grid[i + 1][j]); // right node
				}
				if (m_bIsGrid8 && i != m_nWidth - 1 && j != m_nHeight - 1)
				{
					m_Grid[i][j]->addChild(m_Grid[i + 1][j + 1]); // bottom-right node
				}
				if (j != m_nHeight - 1)
				{
					m_Grid[i][j]->addChild(m_Grid[i][j + 1]); // bottom node
				}
				if (m_bIsGrid8 && i != 0 && j != m_nHeight - 1)
				{
					m_Grid[i][j]->addChild(m_Grid[i - 1][j + 1]); // bottom-left node
				}
				if (i != 0)
				{
					m_Grid[i][j]->addChild(m_Grid[i - 1][j]); // left node
				}
				if (m_bIsGrid8 && i != 0 && j != 0)
				{
					m_Grid[i][j]->addChild(m_Grid[i - 1][j - 1]); // top-left node
				}
			}
		}

	}

	TileSet* Map::getTileSet(short _gid)
	{
		TileSet* pTileSet = nullptr;
		for (short i = 0; i < (short) m_TileSet.size(); i++)
		{
			pTileSet = m_TileSet[i];
			if (_gid >= pTileSet->m_nFirstgid && _gid < pTileSet->m_nFirstgid + pTileSet->m_nTilecount)
			{
				return pTileSet;
			}
		}
		return pTileSet;
	}

	Node* Map::getNodeAtPosition(Vector2f _v) 
	{ 
		int i = (int)_v.getX() / m_nTileWidth;
		int j = (int)_v.getY() / m_nTileHeight;
		if (i >= 0 && i < m_nWidth && j >= 0 && j < m_nHeight)
			return m_Grid[i][j];
		else
			return nullptr;
	}

	Vector2f Map::getNodePositionFromPixels(Vector2f _v)
	{
		int i = (int)_v.getX() / m_nTileWidth;
		int j = (int)_v.getY() / m_nTileHeight;
		if (i >= 0 && i < m_nWidth && j >= 0 && j < m_nHeight)
			return Vector2f((float)i, (float)j);
		else
			return Vector2f(0.f, 0.f);
	}

	Vector2f Map::getPixelsFromNodePosition(Vector2f _v)
	{
		int i = (int)_v.getX() * m_nTileWidth;
		int j = (int)_v.getY() * m_nTileHeight;
		return Vector2f((float)i, (float)j);
	}

	bool Map::update()
	{
		for (short i = 0; i < m_nWidth; i++)
		{
			for (short j = 0; j < m_nHeight; j++)
			{
				m_Grid[i][j]->update();
			}
		}
		return true;
	}

	bool Map::draw()
	{
		int tileid = 0, w = 0, h = 0, x = 0, y = 0;

		// Camera/Window restriction
		IntRect r = m_pGM->getWindowRect();
		int iMin = (int)r.getLeft() / m_nTileWidth;
		int iMax = (int)(r.getLeft() + r.getWidth()) / m_nTileWidth;
		int jMin = (int)r.getTop() / m_nTileHeight;
		int jMax = (int)(r.getTop()+r.getHeight()) / m_nTileHeight;

		// Draw map only if a Tileset is loaded
		TileSet* pTileSet = m_pTerrainTileSet;
		if (!m_pTerrainTileSet)
			return false;

		for (short i = iMin; i <= iMax; i++)
		{
			Node** line = m_Grid[i];
			for (short j = jMin; j <= jMax; j++)
			{
				Node* pNode = line[j];
				tileid = pNode->getTileTerrainId();
				
				// Draw each tile by setting the right rectangle in the Tileset's sprite
				IntRect iRect = pTileSet->getTextureRect(tileid);
				pTileSet->m_pSprite->setTextureRect(iRect.getLeft(), iRect.getTop(), iRect.getWidth(), iRect.getHeight());
				pTileSet->m_pSprite->setPosition((float)i*pTileSet->m_nTilewidth, (float)j*pTileSet->m_nTileheight);
				pTileSet->m_pSprite->draw();
			}
		}

		return true;
	}

	void Map::clear()
	{
		// Grid
		for (short i = 0; i < m_nWidth; i++)
		{
			for (short j = 0; j < m_nHeight; j++)
			{
				delete m_Grid[i][j];
			}
			delete[] m_Grid[i];
		}
		delete[] m_Grid;

		// Tilesets
		TileSet* pTileSet = nullptr;
		for (short i = 0; i < (short)m_TileSet.size(); i++)
		{
			pTileSet = m_TileSet[i];
			delete pTileSet;
		}
		m_TileSet.clear();
		m_pTerrainTileSet = nullptr;
	}
} // namespace crea
