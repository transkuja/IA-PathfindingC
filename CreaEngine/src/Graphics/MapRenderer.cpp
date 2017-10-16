#include "stdafx.h"

#include "Graphics\MapRenderer.h"
#include "Core\GameManager.h"
#include "Data\Map.h"

namespace crea
{
	MapRenderer::MapRenderer()
	{
		m_pMap = nullptr;
	}

	MapRenderer::~MapRenderer()
	{

	}

	bool MapRenderer::init()
	{
		return true;
	}
	
	bool MapRenderer::update()
	{
		return true;
	}
	
	bool MapRenderer::draw()
	{
		if (m_pMap)
		{
			m_pMap->draw();
		}

		return true;
	}
	
	bool MapRenderer::quit()
	{
		return true;
	}

} // namespace crea
