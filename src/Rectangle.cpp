#include <iomanip>
#include "Board.h"
#include "Rectangle.h"
#include "macros.h"
#include "Vertex.h"

Rectangle::Rectangle(const Vertex& bottomLeft, const Vertex& topRight)
	//:m_bottomLeft.m_col(bottomLeft.m_col), m_topRight.m_col(topRight.m_col),
	//m_bottomLeft.m_row(bottomLeft.m_row), m_topRight.m_row(topRight.m_row)
{
	if (bottomLeft.isValid() && topRight.isValid() && bottomLeft.relative_valid_with(topRight))
		bottomLeft.copy_data(topRight, m_bottomLeft, m_topRight);
	else
		m_bottomLeft.assign_default_quad(m_topRight);

	calc_width_height();
}

Rectangle::Rectangle(const Vertex vertices[2])
{
	if (vertices[0].isValid() && vertices[1].isValid() && vertices[0].relative_valid_with(vertices[1]))
		vertices[0].copy_data(vertices[1], m_bottomLeft, m_topRight);
	else
		m_bottomLeft.assign_default_quad(m_topRight);
	
	calc_width_height();
}


Rectangle::Rectangle(double x0, double y0, double x1, double y1)
{
	m_bottomLeft.m_col = x0;
	m_bottomLeft.m_row = y0;
	m_topRight.m_col = x1;
	m_topRight.m_row = y1;

	if (!(m_bottomLeft.isValid() && m_topRight.isValid() && m_bottomLeft.relative_valid_with(m_topRight)))
		m_bottomLeft.assign_default_quad(m_topRight);

	calc_width_height();
}

Rectangle::Rectangle(const Vertex& start, double width, double height)
{
	if (width < 0 || height < 0)
	{
		m_bottomLeft.assign_default_quad(m_topRight);
		return;
	}

	m_topRight.m_col = start.m_col + width;
	m_topRight.m_row = start.m_row + height;

	if (!(start.isValid() && m_topRight.isValid() && start.relative_valid_with(m_topRight)))
		m_bottomLeft.assign_default_quad(m_topRight);

	calc_width_height();
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
//		check if rectangle is just a line
	if (m_bottomLeft.m_col - m_topRight.m_col == 0)
		return m_height;
	else if (m_bottomLeft.m_row - m_topRight.m_row == 0)
		return m_width;

	return m_width * 2 + m_height * 2;
}

Vertex Rectangle::getCenter() const
{

	bool same_col = m_bottomLeft.m_col - m_topRight.m_col == 0;
	bool same_row = m_bottomLeft.m_row - m_topRight.m_row == 0;

//		check if both dots are the same
	if (same_col && same_row)
		return m_bottomLeft;

	Vertex center_dot;

//		assume rectangle is normal
	center_dot.m_col = m_bottomLeft.m_col + (m_topRight.m_col - m_bottomLeft.m_col) / 2;
	center_dot.m_row = m_bottomLeft.m_row + (m_topRight.m_row - m_bottomLeft.m_row) / 2;

	if (same_col)
		center_dot.m_col = m_bottomLeft.m_col;

	else if (same_row)
		center_dot.m_row = m_bottomLeft.m_row;

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

	const Vertex cpyTopRight = newTopRight;

	if (newBottomLeft.isValid() && newTopRight.isValid() && newBottomLeft.relative_valid_with(newTopRight))
	{
		newBottomLeft.copy_data(newTopRight, m_bottomLeft, m_topRight);
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