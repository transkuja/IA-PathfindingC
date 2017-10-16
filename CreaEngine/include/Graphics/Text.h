/***************************************************/
/* Nom:	Text.h
/* Description: Text
/* Auteur: BRUNEAU Colin
/***************************************************/
#ifndef _Text_H
#define _Text_H

#include "Font.h"
#include "Color.h"

namespace sf
{
	class Text;
}
namespace crea
{

	class CREAENGINE_API Text
	{
	public:
		sf::Text* m_pText;

		Text();

		virtual ~Text();

		virtual void draw();

		virtual void setFont(Font* _pFont);

		virtual void setColor(Color* _pColor);

		virtual void setCharacterSize(int _iSize);

		virtual void setString(std::string _szString);

		virtual void setPosition(float _x, float _y);

	};

} // namespace crea

#endif // _Text_H