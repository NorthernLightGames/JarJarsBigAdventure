#pragma once

/*
 * Platforms\Level.h
 * -----------------------
 * Author: Valdemar Melin
 * Created on: 31 dec 2015
 *
 * Declares the Level class.
 */

#include <Platforms.h>
#include <Platforms\Map.h>
#include <Platforms\GameMode.h>

namespace Platforms {

	class PLAPI Level {
	public:

		Level(Map* map, GameMode* game_mode);

		virtual ~Level();

		const Map* GetMap();

		const GameMode* GetGameMode();

	private:

		Map* map;

		GameMode* game_mode;
	};

}
