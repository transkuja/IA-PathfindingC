/***************************************************/
/* Nom:	Sprite.h
/* Description: Sprite
/* Auteur: BRUNEAU Colin
/***************************************************/
#ifndef _Sprite_H
#define _Sprite_H

namespace sf
{
	class Sprite;
}
namespace crea
{

	class CREAENGINE_API Sprite
	{
	public:
		sf::Sprite* m_pSprite;

		Sprite();

		~Sprite();

		virtual void draw();

		virtual void setTexture(Texture* _pTexture);

		virtual void setPosition(float _x, float _y);

		virtual void setTextureRect(int _x, int _y, int _w, int _h);

		virtual void setScale(float _x, float _y);

		virtual void setOrigin(float _x, float _y);
	};

} // namespace crea

#endif // _Sprite_H