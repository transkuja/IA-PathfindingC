#include "stdafx.h"

#include "Graphics\Text.h"

#include <SFML/Graphics.hpp>

namespace crea
{
	Text::Text()
	{
		m_pText = new sf::Text;
	}

	Text::~Text()
	{
		delete m_pText;
	}

	void Text::draw()
	{
		GameManager::getSingleton()->getWindow()->draw(*m_pText);
	}

	void Text::setFont(Font* _pFont)
	{
		m_pText->setFont(*_pFont->m_pFont);
	}

	void Text::setColor(Color* _pColor)
	{
		m_pText->setFillColor(*_pColor->m_pColor);
	}

	void Text::setCharacterSize(int _iSize)
	{
		m_pText->setCharacterSize(_iSize);
	}

	void Text::setString(std::string _szString)
	{
		m_pText->setString(_szString);
	}

	void Text::setPosition(float _x, float _y)
	{
		m_pText->setPosition(_x, _y);
	}

} // namespace crea
