/*
 * Implements Level class.
 * See <Platforms\Level.h> for details.
 */

#include "stdafx.h"
#include <Platforms\Level.h>

namespace Platforms {
	Level::Level(Map * map, GameMode * game_mode)
	{

	}

	Level::~Level()
	{
	}

	const Map * Platforms::Level::GetMap()
	{
		return map;
	}

	const GameMode * Platforms::Level::GetGameMode()
	{
		return game_mode;
	}
}