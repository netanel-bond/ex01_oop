#include <iomanip>
#include "Board.h"
#include "Rectangle.h"
#include "macros.h"

Rectangle::Rectangle(const Vertex& bottomLeft, const Vertex& topRight)
	/*:m_bottomLeft.m_col(bottomLeft.m_col), m_topRight.m_col(topRight.m_col),
	m_bottomLeft.m_row(bottomLeft.m_row), m_topRight.m_row(topRight.m_row)*/
{
	if (!(is_dot_valid(bottomLeft) && is_dot_valid(topRight))
		assign_default_values();
}

bool Rectangle::is_dot_valid(const Vertex& dot)
{
	return (!(dot.m_col > MAX_COL || dot.m_col < 0 ||
				dot.m_row > MAX_ROW || dot.m_row < 0));
}

bool Rectangle::is_dot_valid(double x, double y)
{
	return (!(x > MAX_COL || x < 0 || y > MAX_ROW || y < 0));
}

void Rectangle::assign_default_values()
{
	bottomLeft.m_col = 20;
	bottomLeft.m_row = 10;
	topRight.m_col = 30;
	topRight.m_row = 20;
}

Vertex Rectangle::getBottomLeft() const
{
	return m_bottomLeft;
}

Vertex Rectangle::getTopRight()const
{
	return m_topRight;
}

double Rectangle::getWidth() const
{
	return m_width;
}

double Rectangle::getHeight() const
{
	return m_height;
}