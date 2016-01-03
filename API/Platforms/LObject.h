#pragma once
/*
* Platforms\LObject.h
* -----------------------
* Author: Valdemar Melin
* Created on: 31 dec 2015
*
* Declares the LObject class.
*/

#include <Platforms.h>

namespace Platforms {

	class PLAPI LObject {
	protected:
		const LObject* parent;
		const Level* level;

	public:

		LObject();

		virtual ~LObject();

		void AttachTo(const LObject* parent);

		void Tick(Time time_elapsed);

		void Load();

	protected:
		void registerTick();
	};
}
