/***************************************************/
/* Nom:	Map.h
/* Description: Map
/* Auteur: BRUNEAU Colin
/***************************************************/
#ifndef __Map_H_
#define __Map_H_

#include <vector>
#include "TileSet.h"

namespace crea
{
	class Node;

	class CREAENGINE_API Map
	{
		crea::GameManager*	m_pGM;

		// Name
		string m_szName;

		// Dimensions
		short m_nWidth;
		short m_nHeight;
		short m_nTileWidth;
		short m_nTileHeight;

		// Tilesets
		vector<TileSet*> m_TileSet;
		TileSet* m_pTerrainTileSet;

		// Nodes
		Node* **m_Grid;	// Allocation dynamique
		bool m_bIsGrid8;
		
	public:

		Map();

		~Map();

		bool loadFromFileJSON(string& _filename);

		inline void setName(string& _szName) { m_szName = _szName; }

		void setSize(short _nWidth, short _nHeight);

		void setNode(short _i, short _j, Node* _pNode) { m_Grid[_i][_j] = _pNode; }

		Node* getNode(short _i, short _j) { return m_Grid[_i][_j]; }

		TileSet* getTileSet(short _gid);

		Node* getNodeAtPosition(Vector2f _v);

		Vector2f getNodePositionFromPixels(Vector2f _v);

		Vector2f getPixelsFromNodePosition(Vector2f _v);
		
		bool update();

		bool draw();

		void clear();
	};

} // namespace crea

#endif
