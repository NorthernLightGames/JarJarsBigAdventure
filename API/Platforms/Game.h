#pragma once

/*
 * Platforms\Game.h
 * -----------------------
 * Author: Valdemar Melin
 * Created on: 30 dec 2015
 *
 * Game class header.
 */

#include <Platforms.h>
#include <Platforms/Level.h>

namespace Platforms {

	class PLAPI Game {
	public:

		Game();

		virtual ~Game();

		void Tick(float time_elapsed);

		void Start();

		Level* GetActiveLevel();

	protected:

		Level* setActiveLevel(Level* level);

	private:

		Level* active_level;
	};
}