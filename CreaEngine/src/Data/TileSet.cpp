#include "stdafx.h"

#include "Data\TileSet.h"

namespace crea
{
	TileSet::TileSet()
	{
	}

	TileSet::~TileSet()
	{
		VectorTerrain::iterator it = m_Terrains.begin();
		while (it != m_Terrains.end()) {
			delete (*it);
			it = m_Terrains.erase(it);
		}
	}
	
}