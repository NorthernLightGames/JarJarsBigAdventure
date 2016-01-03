#pragma once

/*
 * Engine.h
 * -----------------------
 * Author: Valdemar Melin
 * 30 dec 2015
 *
 * Declares the Engine class.
 *
 */

#include <Platforms.h>
#include <Platforms\Game.h>
#include <Platforms\Window.h>

namespace Platforms {

	/*
	 *
	 */
	class PLAPI Engine final {
	public:
		/*
		 * Wrapper for Engine constructor, which purpose is to prevent multiple instances of 
		 * Engine to exist simultaneously. 
		 */
		static const Engine* CreateEngine(Game* game);

		static void DestroyEngine();

	private:
		/*
		 *
		 * Constructor method. 
		 * Performs initialization of engine.
		 * There should only exist one 
		 */
		Engine(Game* game);

		/*
		 *
		 * Updates the game. 
		 */
		void execute_tick(float time_elapsed);

		/*
		 *
		 * Executes after the Engine is initialized.
		 * Calls the Start() method in <game>
		 */
		void start_game();

	public:
		/*
		 * Destructor.
		 * Destroys the Engine.
		 */
		~Engine();

		/*
		 * Creates a new Window described by <windowDescriptor>.
		 * See Window.h, Canvas.h
		 */
		Window* NewWindow(const WindowFormat& windowDescriptor) const;

		/*
		 * Returns the Game object.
		 * See Game.h
		 */
		const Game* GetGame() const;

	private:
		Game* game;
	};

	extern const PLAPI Engine* _Engine;
}