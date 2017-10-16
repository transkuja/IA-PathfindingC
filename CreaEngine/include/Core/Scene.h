/***************************************************/
/* Nom:	Scene.h
/* Description: Scene
/* Auteur: BRUNEAU Colin
/***************************************************/
#ifndef __Scene_H_
#define __Scene_H_

namespace crea
{

	class CREAENGINE_API Scene
	{

	public:
		Scene();
		virtual ~Scene();

		virtual bool onInit() = 0;
		virtual bool onUpdate() = 0;
		virtual bool onDraw() = 0;
		virtual bool onQuit() = 0;

	};

} // namespace crea

#endif
