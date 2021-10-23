#include <iomanip>
#include "Board.h"
#include "Rectangle.h"
#include "macros.h"
#include "Vertex.h"

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

	calc_width_height();
}

Rectangle::Rectangle(const Vertex vertices[2])
{
	if (!are_dots_valid(vertices[0], vertices[1]))
	{
		assign_default_values();
		return;
	}

	copy_data(vertices[0], vertices[1]);

	calc_width_height();
}

Rectangle::Rectangle(double x0, double y0, double x1, double y1)
{
	m_bottomLeft.m_col = x0;
	m_bottomLeft.m_row = y0;
	m_topRight.m_col = x1;
	m_topRight.m_row = y1;

	if (!are_dots_valid(m_bottomLeft, m_topRight))
		assign_default_values();

	calc_width_height();
}

Rectangle::Rectangle(const Vertex& start, double width, double height)
{
	if (width < 0 || height < 0)
	{
		assign_default_values();
		return;
	}

	m_topRight.m_col = start.m_col + width;
	m_topRight.m_row = start.m_row + height;

	if (!are_dots_valid(start, m_topRight))
		assign_default_values();

	calc_width_height();
}

void Rectangle::copy_data(const Vertex& bottomLeft, const Vertex& topRight)
{
	m_bottomLeft.m_col = bottomLeft.m_col;
	m_bottomLeft.m_row = bottomLeft.m_row;
	m_topRight.m_row = topRight.m_row;
	m_topRight.m_col = topRight.m_col;

	calc_width_height();
}

bool Rectangle::are_dots_valid(const Vertex& bottomLeft, const Vertex& topRight)
{

	bool within_border = bottomLeft.isValid() && topRight.isValid();

	bool valid_relativity = topRight.isToTheRightOf(bottomLeft) &&
							topRight.isHigherThan(bottomLeft);

	return within_border && valid_relativity;
}

void Rectangle::assign_default_values()
{
	m_bottomLeft.m_col = 20;
	m_bottomLeft.m_row = 10;
	m_topRight.m_col = 30;
	m_topRight.m_row = 20;
}

void Rectangle::calc_width_height()
{
	m_width = m_topRight.m_col - m_bottomLeft.m_col;

	m_height = m_topRight.m_row - m_bottomLeft.m_row;
}

void Rectangle::draw(Board& board) const
{
	Vertex topLeft, bottomRight;

	topLeft.m_col = m_bottomLeft.m_col;
	topLeft.m_row = m_topRight.m_row;

	bottomRight.m_col = m_topRight.m_col;
	bottomRight.m_row = m_bottomLeft.m_row;

	board.drawLine(m_bottomLeft, bottomRight);
	board.drawLine(m_bottomLeft, topLeft);
	board.drawLine(m_topRight, bottomRight);
	board.drawLine(m_topRight, topLeft);
}

Rectangle Rectangle::getBoundingRectangle() const
{
	Rectangle rect(m_bottomLeft, m_topRight);

	return rect;
}

double Rectangle::getArea() const
{
	return m_width * m_height;
}

double Rectangle::getPerimeter() const
{
	return m_width * 2 + m_height * 2;
}

Vertex Rectangle::getCenter() const
{
	Vertex center_dot;

	center_dot.m_col = (m_topRight.m_col - m_bottomLeft.m_col) / 2;
	center_dot.m_row = (m_topRight.m_row - m_bottomLeft.m_row) / 2;

	return center_dot;
}

bool Rectangle::scale(double factor)
{
	if (factor <= 0)
		return false;

	Vertex centerDot = getCenter();

	Vertex newBottomLeft, newTopRight;

	m_bottomLeft.scaledValue(centerDot, newBottomLeft, factor);
	m_topRight.scaledValue(centerDot, newTopRight, factor);

	if (are_dots_valid(newBottomLeft, newTopRight))
	{
		copy_data(newBottomLeft, newTopRight);
		return true;
	}
		
	return false;
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