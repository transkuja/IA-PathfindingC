#include "stdafx.h"

#include "Graphics\SpriteRenderer.h"
#include "Core\GameManager.h"
#include <SFML/Graphics.hpp>

namespace crea
{
	SpriteRenderer::SpriteRenderer()
	{
		m_pSprite = nullptr;
	}

	SpriteRenderer::~SpriteRenderer()
	{

	}

	bool SpriteRenderer::init()
	{
		return true;
	}
	
	bool SpriteRenderer::update()
	{
		return true;
	}
	
	bool SpriteRenderer::draw()
	{
		if (m_pSprite)
		{
			crea::GameManager::getSingleton()->getWindow()->draw(*m_pSprite->m_pSprite);
		}

		return true;
	}
	
	bool SpriteRenderer::quit()
	{
		return true;
	}

} // namespace crea
