#pragma once

/*
 * Platforms\Canvas.h
 * -----------------------
 * Author: Valdemar Melin
 * Created on: 30 dec 2015
 *
 * Declares the Canvas class.
 */

#include <Platforms.h>

namespace Platforms {

	class PLAPI Canvas {
	public:
		virtual ~Canvas();
		virtual void MakeCurrent() = 0;
	private:
		static Canvas* current_canvas;
	};
}

