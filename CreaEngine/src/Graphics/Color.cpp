#include "stdafx.h"

#include "Graphics\Color.h"

#include <SFML/Graphics.hpp>

namespace crea
{

	Color::Color()
	{
		m_pColor = new sf::Color;
	}

	Color::~Color()
	{
		delete m_pColor;
	}

	void Color::setValues(int _r, int _g, int _b, int _a)
	{
		m_pColor->r = _r;
		m_pColor->g = _g;
		m_pColor->b = _b;
		m_pColor->a = _a;
	}

} // namespace crea
