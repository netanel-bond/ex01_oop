#include <iomanip>
#include "Board.h"
#include "Rectangle.h"

Vertex Rectangle::getBottomLeft() const
{
	return bottomLeft;
}

Vertex Rectangle::getTopRight()const
{
	return topRight;
}