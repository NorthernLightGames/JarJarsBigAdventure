#pragma once

/*
* Platforms\Types.h
* -----------------------
* Author: Valdemar Melin
* Created on: 2 dec 2016
*
* Common data types.
*/

#include <Platforms.h>
#include <Platforms\Matrix.h>
#include <cmath>

namespace Platforms {

	typedef scalar Time;

	typedef vector2 Point2;
	typedef vector2 Velocity2;
	typedef vector2 Acceleration2;
	typedef vector2 Scale2;
	typedef vector2 Rotation2;

	typedef vector3 Point3, Point;
	typedef vector3 Velocity3, Velocity;
	typedef vector3 Acceleration3, Acceleration;
	typedef vector3 Scale3, Scale;
	typedef vector3 Rotation3, Rotation;

	typedef vector3 Normal;

}