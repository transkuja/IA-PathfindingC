#include "stdafx.h"

#include "Graphics\TextRenderer.h"
#include "Core\GameManager.h"
#include <SFML/Graphics.hpp>

namespace crea
{
	TextRenderer::TextRenderer()
	{
		m_pText = nullptr;
	}

	TextRenderer::~TextRenderer()
	{

	}

	bool TextRenderer::init()
	{
		return true;
	}
	
	bool TextRenderer::update()
	{
		return true;
	}
	
	bool TextRenderer::draw()
	{
		if (m_pText)
		{
			crea::GameManager::getSingleton()->getWindow()->draw(*m_pText->m_pText);
		}

		return true;
	}
	
	bool TextRenderer::quit()
	{
		return true;
	}

} // namespace crea
