#include <iomanip>
#include "Board.h"
#include "Rectangle.h"
#include "macros.h"

Rectangle::Rectangle(const Vertex& bottomLeft, const Vertex& topRight)
	//:m_bottomLeft.m_col(bottomLeft.m_col), m_topRight.m_col(topRight.m_col),
	//m_bottomLeft.m_row(bottomLeft.m_row), m_topRight.m_row(topRight.m_row)
{

	if (!are_dots_valid(bottomLeft, topRight))
	{
		assign_default_values();
		return;
	}
		
	copy_data(bottomLeft, topRight);
}

Rectangle::Rectangle(const Vertex vertices[2])
{
	if (!are_dots_valid(&vertices[0], &vertices[1]))
	{
		assign_default_values();
		return;
	}

	copy_data(&vertices[0], &vertices[1]);
}

Rectangle::Rectangle(double x0, double y0, double x1, double y1)
{
	m_bottomLeft.m_col = x0;
	m_bottomLeft.m_row = y0;
	m_topRight.m_col = x1;
	m_topRight.m_row = y1;

	if (!are_dots_valid(const Vertex& m_bottomLeft, const Vertex& m_topRight))
		assign_default_values();
}

Rectangle::Rectangle(const Vertex& start, double width, double height)
{
	if (start width < 0 || height < 0)
	{
		assign_default_values;
		return;
	}

	m_topRight.m_col = start.m_col + width;
	m_topRight.m_row = start.m_row + height;

	if (!are_dots_valid(start, &m_topRight))
		assign_default_values();
}

void Rectangle::copy_data(const Vertex& bottomLeft, const Vertex& topRight)
{
	m_bottomLeft.m_col = bottomLeft.m_col;
	m_bottomLeft.m_row = bottomLeft.m_row;
	m_topRight.m_row = topRight.m_col;
	m_topRight.m_col = topRight.m_row;
}


bool Rectangle::are_dots_valid(const Vertex& bottomLeft, const Vertex& topRight)
{

	bool within_border = bottomLeft.isValid() && topRight.isValid;

	bool valid_relativity = topRight.isToTheRightOf(&bottomLeft) &&
							topRight.isHigherThan(&bottomLeft);

	return within_border && valid_relativity;
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