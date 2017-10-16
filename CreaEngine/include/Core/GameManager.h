/***************************************************/
/* Nom:	GameManager.h
/* Description: GameManager
/* Auteur: BRUNEAU Colin
/***************************************************/
#ifndef __GameManager_H_
#define __GameManager_H_

#include "SceneManager.h"
#include "EntityManager.h"
#include "Data\DataManager.h"
#include "Input\InputManager.h"
#include "Core\Math.h"

namespace sf
{
	class RenderWindow;
}

namespace crea
{

	class CREAENGINE_API GameManager
	{
		GameManager();

		// window
		sf::RenderWindow* m_pWindow;
		IntRect m_rWindowRect;

	public:
		~GameManager();

		static GameManager* getSingleton();

		inline sf::RenderWindow* getWindow() { return m_pWindow; }

		IntRect getWindowRect() { return m_rWindowRect; }

		void setWindowRect(IntRect _rect) {m_rWindowRect = _rect; }

		inline void setScene(Scene* s) { SceneManager::getSingleton()->setScene(s); }

		// Input
		inline bool isKeyPressed(Key _key) { return InputManager::getSingleton()->isKeyPressed(_key); }

		// Data
		inline Font* getFont(string _szName) { return DataManager::getSingleton()->getFont(_szName); }

		inline Texture* getTexture(string _szName) { return DataManager::getSingleton()->getTexture(_szName); }

		inline Color* getColor(string _szName) { return DataManager::getSingleton()->getColor(_szName); }

		inline Sprite* getSprite(string _szName) { return DataManager::getSingleton()->getSprite(_szName); }

		inline Map* getMap(string _szName) { return DataManager::getSingleton()->getMap(_szName); }

		inline MapRenderer* getMapRenderer(string _szName) { return EntityManager::getSingleton()->getMapRenderer(_szName); }

		inline Entity* getEntity(string _szName) { return EntityManager::getSingleton()->getEntity(_szName); }

		inline void addEntity(Entity* _pEntity, Entity* _pParent = nullptr)  { EntityManager::getSingleton()->addEntity(_pEntity, _pParent); }

		inline void clearAllData() { DataManager::getSingleton()->clear(); }

		inline void clearAllEntities()  { EntityManager::getSingleton()->clear(); }

		void init();

		void update();

		void quit();
	};

} // namespace crea

#endif
