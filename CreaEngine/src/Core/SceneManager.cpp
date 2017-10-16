#include "stdafx.h"

#include "Data\SceneManager.h"
#include "Tools\State.h"

namespace crea
{
	SceneManager::SceneManager()
	{
		m_pCurrentState = nullptr;
	}

	SceneManager::~SceneManager()
	{
		if (m_pCurrentState)
		{
			m_pCurrentState->onQuit();
			delete m_pCurrentState;
		}
	}

	SceneManager* SceneManager::getSingleton()
	{
		static SceneManager instanceUnique;
		return
			&instanceUnique;
	}
	
	bool SceneManager::update()
	{
		if (m_pCurrentState)
			return m_pCurrentState->onUpdate();
		return false;
	}

	bool SceneManager::draw()
	{
		if (m_pCurrentState)
			return m_pCurrentState->onDraw();
		return false;
	}

	void SceneManager::setState(State* _s)
	{
		if (m_pCurrentState)
		{
			m_pCurrentState->onQuit();
			delete m_pCurrentState;
		}
		m_pCurrentState = _s;
		m_pCurrentState->onInit();
	}


} // namespace crea
