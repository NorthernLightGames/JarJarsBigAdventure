#pragma once

/*
 * Platforms\Display.h
 * -----------------------
 * Author: Valdemar Melin
 * Created on: 31 dec 2015
 *
 * Declares the Display class.
 */

#include <Platforms.h>
#include <Platforms\Canvas.h>

namespace Platforms {
	class PLAPI Display : public Canvas {
	public:
		virtual ~Display();

	};
}