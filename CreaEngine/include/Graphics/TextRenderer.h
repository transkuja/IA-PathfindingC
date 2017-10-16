/***************************************************/
/* Nom:	TextRenderer.h
/* Description: TextRenderer
/* Auteur: BRUNEAU Colin
/***************************************************/
#ifndef __TextRenderer_H_
#define __TextRenderer_H_

#include "Core\Component.h"

namespace sf
{
	class Text;
}

namespace crea
{

	class CREAENGINE_API TextRenderer : public Component
	{
		Text* m_pText;

	public:
		TextRenderer();
		virtual ~TextRenderer();

		inline void setText(Text* _pText) { m_pText = _pText; }

		virtual bool init();
		virtual bool update();
		virtual bool draw();
		virtual bool quit();

	};

} // namespace crea

#endif
