#include "stdafx.h"

#include "Scene\SceneMap.h"
#include "Scene\SceneMenu.h"
#include "Scene\SceneGame.h"


SceneMap::SceneMap()
{

}

SceneMap::~SceneMap()
{

}
	
bool SceneMap::onInit()
{
	m_pGM = GameManager::getSingleton();

	// Load Map
	m_pEntity3 = m_pGM->getEntity("map1");
	m_pGM->addEntity(m_pEntity3);
	m_pMap = m_pGM->getMap("map4.json"); // map loaded after entity added to display map first (order in tree matters)
	m_pMapRenderer = m_pGM->getMapRenderer("MapRenderer1");
	m_pMapRenderer->setMap(m_pMap);
	m_pEntity3->addComponent(m_pMapRenderer);

	return true;
}

bool SceneMap::onUpdate()
{
	if (m_pGM->isKeyPressed(Key::Num1))
	{
		m_pGM->setScene(new SceneMenu());
		return true;
	}
	if (m_pGM->isKeyPressed(Key::Num2))
	{
		m_pGM->setScene(new SceneGame());
		return true;
	}

	return true;
}

bool SceneMap::onDraw()
{
	return true;
}

bool SceneMap::onQuit()
{
	m_pGM->clearAllData();
	m_pGM->clearAllEntities();

	return true;
}

