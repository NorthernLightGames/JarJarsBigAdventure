
/*
 * Implements Engine class.
 * See <Platforms\Engine.h> for details.
 */

#include "stdafx.h"
#include <Platforms\Engine.h>

namespace Platforms {

	const Engine* _Engine; // The global _Engine variable
	Engine* _m_Engine; // Mutable copy of _Engine


	/*
 	 * Creates the Engine and assigns the global _Engine to it.
	 * 
	 */
	const Engine * Engine::CreateEngine(Game* game)
	{
		if (_Engine) {
			// Later, there should be an error report here.
			return nullptr;
		}
		_m_Engine = new Engine(game);
		_Engine = _m_Engine;
		return _Engine;
	}
	/*
	 * Destroys the Engine.
	 */
	void Engine::DestroyEngine()
	{
		delete _m_Engine;
		_m_Engine = nullptr;
		_Engine = nullptr;
		return;
	}
	/*
	 * Engine constructor.
	 */
	Engine::Engine(Game* g):game(g) 
	{
		start_game();
	}

	/*
	 * Updating method.
 	 */
	void Engine::execute_tick(float time_elapsed)
	{
		game->Tick(time_elapsed);
	}

	/*
	 * Starts the game.
	 */
	void Engine::start_game()
	{
		game->Start();
	}

	/*
	 * Engine destructor.
	 */
	Engine::~Engine() {
		delete game;
	}

	/*
	 * Creates a window display. If the format is not supported it returns null.
	 */
	Window * Engine::NewWindow(const WindowFormat & wF) const
	{
		return nullptr;
	}

	const Game * Engine::GetGame() const
	{
		return game;
	}
}