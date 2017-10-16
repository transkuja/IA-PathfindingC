/***************************************************/
/* Nom:	SpriteRenderer.h
/* Description: SpriteRenderer
/* Auteur: BRUNEAU Colin
/***************************************************/
#ifndef __SpriteRenderer_H_
#define __SpriteRenderer_H_

#include "Core\Component.h"
#include "Core\Math.h"

namespace sf
{
	class Sprite;
}

namespace crea
{

	class CREAENGINE_API SpriteRenderer : public Component
	{
		Sprite* m_pSprite;
		IntRect* m_pTextureRect;

	public:
		SpriteRenderer();
		virtual ~SpriteRenderer();

		inline void setSprite(Sprite* _pSprite) { m_pSprite = _pSprite; }
		void setTextureRect(IntRect* _pTextureRect) { m_pTextureRect = new IntRect(*_pTextureRect); }

		virtual bool init();
		virtual bool update();
		virtual bool draw();
		virtual bool quit();

	};

} // namespace crea

#endif
