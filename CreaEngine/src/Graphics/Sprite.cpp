#include "stdafx.h"

#include "Graphics\Sprite.h"

#include <SFML/Graphics.hpp>

namespace crea
{

	Sprite::Sprite()
	{
		m_pSprite = new sf::Sprite;
	}

	Sprite::~Sprite()
	{
		delete m_pSprite;
	}

	void Sprite::draw()
	{
		GameManager::getSingleton()->getWindow()->draw(*m_pSprite);
	}

	void Sprite::setTexture(Texture* _pTexture)
	{
		m_pSprite->setTexture(*_pTexture->m_pTexture);
	}

	void Sprite::setPosition(float _x, float _y)
	{
		m_pSprite->setPosition(_x, _y);
	}

	void Sprite::setTextureRect(int _x, int _y, int _w, int _h)
	{
		m_pSprite->setTextureRect(sf::IntRect(_x, _y, _w, _h));
	}

	void Sprite::setScale(float _x, float _y)
	{
		m_pSprite->setScale(_x, _y);
	}

	void Sprite::setOrigin(float _x, float _y)
	{
		m_pSprite->setOrigin(_x, _y);
	}

} // namespace crea
