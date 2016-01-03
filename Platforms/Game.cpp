
/*
 * Implements Game class.
 * See <Platforms\Game.h> for details.
 */

#include "stdafx.h"
#include <Platforms\Game.h>

namespace Platforms {

	Game::Game()
	{

	}

	Game::~Game()
	{

	}

	void Game::Tick(float time_elapsed)
	{
		
	}

	void Game::Start()
	{

	}

	Level * Game::GetActiveLevel()
	{
		return nullptr;
	}

	Level * Game::setActiveLevel(Level * level)
	{
		Level* tmp = GetActiveLevel();
		return tmp;
	}

}