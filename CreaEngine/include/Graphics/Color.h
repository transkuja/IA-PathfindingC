/***************************************************/
/* Nom:	Color.h
/* Description: Color
/* Auteur: BRUNEAU Colin
/***************************************************/
#ifndef _Color_H
#define _Color_H

namespace sf
{
	class Color;
}
namespace crea
{

	class CREAENGINE_API Color
	{
	public:
		sf::Color* m_pColor;

		Color();

		virtual ~Color();

		void setValues(int _r, int _g, int _b, int _a);
	};

} // namespace crea

#endif // _Color_H