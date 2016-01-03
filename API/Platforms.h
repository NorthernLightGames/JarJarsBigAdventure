#pragma once

/*
 * Platforms.h
 * -----------------------
 * Author: Valdemar Melin
 * Created on: 29 dec 2015
 * 
 * This is the main API header file. It includes the core features for the engine.
 */

/*
 *
 * Code style:
 * 
 * Classes and Structs: Name: PascalCase
 *   Public methods and members: PascalCase
 *   Protected methods and members: camelCase
 *   Private methods and members: snake_case
 *   Exception: mathematical objects uses only snake case.
 *
 * Namespaces: PascalCase
 *
 * Functions: PascalCase
 *   Function parameters: camelCase
 *
 * Global vars: PascalCase with underscore prefix, ex: _Engine 
 *
 * Blocks: new line is allowed but not preferred.
 *
 */

#ifdef PLATFORMS_BUILD
#define PLAPI __declspec(dllexport)
#else
#define PLAPI __declspec(dllimport)
#endif

#define _out_

namespace Platforms {
	typedef unsigned char byte;

	struct byte_buffer {
		const int size;
		byte buffer[];
	};
}

// Basic IO system and data sructures

#include <Platforms\Buffer.h>
#include <Platforms\Array.h>
#include <Platforms\IO.h>

// Mathematics and data types.

#include <cmath>
#include <Platforms\Matrix.h>
#include <Platforms\Types.h>

// Core engine classes

#include <Platforms\Engine.h>
#include <Platforms\Game.h>