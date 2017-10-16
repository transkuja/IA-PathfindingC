/***************************************************/
/* Nom:	MapRenderer.h
/* Description: MapRenderer
/* Auteur: BRUNEAU Colin
/***************************************************/
#ifndef __MapRenderer_H_
#define __MapRenderer_H_

#include "Core\Component.h"

namespace crea
{
	class Map;

	class CREAENGINE_API MapRenderer : public Component
	{
		Map* m_pMap;

	public:
		MapRenderer();
		virtual ~MapRenderer();

		inline void setMap(Map* _pMap) { m_pMap = _pMap; }

		virtual bool init();
		virtual bool update();
		virtual bool draw();
		virtual bool quit();

	};

} // namespace crea

#endif
