/***************************************************/
/* Nom:	SceneMap.h
/* Description: SceneMap
/* Auteur: BRUNEAU Colin
/***************************************************/
#ifndef __SceneMap_H_
#define __SceneMap_H_

#include "Core\Scene.h"

using namespace crea;

class SceneMap : public Scene
{
	GameManager*	m_pGM;

	// Map
	Entity* m_pEntity3;
	Map* m_pMap;
	MapRenderer* m_pMapRenderer;

public:
	SceneMap();
	virtual ~SceneMap();

	virtual bool onInit();
	virtual bool onUpdate();
	virtual bool onDraw();
	virtual bool onQuit();

};

#endif
