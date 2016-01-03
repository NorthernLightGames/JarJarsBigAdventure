#pragma once

/*
* Platforms\Window.h
* -----------------------
* Author: Valdemar Melin
* Created on: 31 dec 2015
*
* Declares the Window class.
*/

#include <Platforms.h>
#include <Platforms\Display.h>

namespace Platforms {

	struct WindowFormat {

	};

	class Window : public Display {
	public:
		Window(const WindowFormat& format);
		virtual ~Window();
	};
}