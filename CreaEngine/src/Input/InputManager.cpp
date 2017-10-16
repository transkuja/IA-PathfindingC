#include "stdafx.h"

#include "Input\InputManager.h"

#include <SFML/Graphics.hpp>

namespace crea
{
	InputManager::InputManager()
	{

	}

	InputManager::~InputManager()
	{

	}

	InputManager* InputManager::getSingleton()
	{
		static InputManager instanceUnique;
		return
			&instanceUnique;
	}

	bool InputManager::update()
	{
		return true;
	}

	bool InputManager::isKeyPressed(Key _key)
	{
		return sf::Keyboard::isKeyPressed((sf::Keyboard::Key)_key);
	}
} // namespace crea
