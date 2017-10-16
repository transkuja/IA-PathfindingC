#include "stdafx.h"

#include "Data\GameManager.h"

namespace crea
{
	GameManager::GameManager()
	{
		m_pWindow = nullptr;
	}

	GameManager::~GameManager()
	{
		delete m_pWindow;
	}

	GameManager* GameManager::getSingleton()
	{
		static GameManager instanceUnique;
		return
			&instanceUnique;
	}

	void GameManager::init()
	{
		m_pWindow = new sf::RenderWindow(sf::VideoMode((unsigned int)(640), (unsigned int)(320)), "TD DP");
	}

	void GameManager::update()
	{
		while (m_pWindow->isOpen())
		{
			sf::Event event;
			while (m_pWindow->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					m_pWindow->close();
			}

			// Time

			// Input
			InputManager::getSingleton()->update();

			// Update
			SceneManager::getSingleton()->update();
			EntityManager::getSingleton()->update();

			// Draw
			m_pWindow->clear();

			SceneManager::getSingleton()->draw();
			EntityManager::getSingleton()->draw();

			m_pWindow->display();
		}

	}

	void GameManager::quit()
	{
	}


} // namespace crea
