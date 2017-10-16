#include "stdafx.h"

#include "Graphics\Texture.h"

#include <SFML/Graphics.hpp>

namespace crea
{
	Texture::Texture()
	{
		m_pTexture = new sf::Texture;
	}

	Texture::~Texture()
	{
		delete m_pTexture;
	}	
	
	bool Texture::loadFromFile(std::string _file)
	{
		return m_pTexture->loadFromFile(_file);
	}

} // namespace crea
