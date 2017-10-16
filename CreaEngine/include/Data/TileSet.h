/***************************************************/
/* Nom:	TileSet.h
/* Description: TileSet
/* Auteur: BRUNEAU Colin
/***************************************************/
#ifndef __TileSet_H_
#define __TileSet_H_

#include <vector>
#include "Core\Math.h"

namespace crea
{
	class CREAENGINE_API Terrain
	{
	public:
		string m_szName;
		short m_nTile;
	};
	
	class CREAENGINE_API VectorTerrain : public vector<Terrain*> {};

	class CREAENGINE_API TileSet
	{

	public:
		short m_nColumns;
		short m_nFirstgid;
		short m_nImageheight;
		short m_nImagewidth;
		short m_nMargin;
		string m_szName;
		short m_nSpacing;
		short m_nTilecount;
		short m_nTileheight;
		short m_nTilewidth;
		string m_szTransparentcolor;
		Sprite* m_pSprite;

		VectorTerrain m_Terrains;

		TileSet();

		~TileSet();
		
		IntRect getTextureRect(int _iTileId)
		{
			int i = _iTileId - m_nFirstgid;
			return IntRect(
				(i % m_nColumns) * (m_nTilewidth + m_nMargin) + m_nMargin, // 1st margin
				(i / m_nColumns) * (m_nTileheight + m_nSpacing) + m_nSpacing, // 1st spacing 
				m_nTilewidth,
				m_nTileheight);
		}
	};

} // namespace crea

#endif
