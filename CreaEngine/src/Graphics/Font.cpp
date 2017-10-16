#include "stdafx.h"

#include "Graphics\Font.h"

#include <SFML/Graphics.hpp>

namespace crea
{

	Font::Font()
	{
		m_pFont = new sf::Font;
	}
	Font::~Font()
	{
		delete m_pFont;
	}
	bool Font::loadFromFile(std::string _file)
	{
		return m_pFont->loadFromFile(_file);
	}

} // namespace crea
