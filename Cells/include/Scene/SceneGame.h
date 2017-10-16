/***************************************************/
/* Nom:	SceneGame.h
/* Description: SceneGame
/* Auteur: BRUNEAU Colin
/***************************************************/
#ifndef __SceneGame_H_
#define __SceneGame_H_

#include "Core\Scene.h"
using namespace crea;

class SceneGame : public Scene
{
	GameManager*	m_pGM;

	Entity* m_pEntity1;
	Sprite* m_pSprite1;
	SpriteRenderer* m_pSpriteRenderer;

public:
	SceneGame();
	virtual ~SceneGame();

	virtual bool onInit();
	virtual bool onUpdate();
	virtual bool onDraw();
	virtual bool onQuit();

};

#endif
