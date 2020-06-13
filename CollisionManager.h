#pragma once

#include <cmath>
#include "Lab3/Rectangle.h"
#include "Ring.h"

static class CollisionManager
{
public:
	static bool IsCollision(Rectangle& first, Rectangle& second);
	static bool IsCollision(Ring& first, Ring& second);
};