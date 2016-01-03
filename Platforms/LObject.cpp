/*
* Implements LObject class.
* See <Platforms\Level.h> for details.
*/

#include "stdafx.h"
#include <Platforms\LObject.h>

Platforms::LObject::LObject()
{

}

Platforms::LObject::~LObject()
{
}

void Platforms::LObject::AttachTo(const LObject * parent)
{

}

void Platforms::LObject::Tick(Time time_elapsed)
{

}

void Platforms::LObject::registerTick()
{
	const LObject* map = this->parent;
	while (map->parent != nullptr)
		map = map->parent;
}
