#include <iomanip>
#include "Board.h"
#include "Rectangle.h"
#include "macros.h"
#include "Vertex.h"

//------------------------------
Rectangle::Rectangle(const Vertex& bottomLeft, const Vertex& topRight)
	:m_bottomLeft(bottomLeft), m_topRight(topRight)
{
	check_dots(bottomLeft, topRight);

	calc_width_height();
}
//------------------------------
Rectangle::Rectangle(const Vertex vertices[2])
	:Rectangle(vertices[0], vertices[1]) {}

//------------------------------
Rectangle::Rectangle(double x0, double y0, double x1, double y1)
{
	m_bottomLeft.m_col = x0;
	m_bottomLeft.m_row = y0;
	m_topRight.m_col = x1;
	m_topRight.m_row = y1;

	check_dots(m_bottomLeft, m_topRight);

	calc_width_height();
}
//------------------------------
Rectangle::Rectangle(const Vertex& start, double width, double height)
	:m_bottomLeft(start), m_width(width), m_height(height)
{
	if (width < 0 || height < 0)
	{
		m_bottomLeft.assign_default_quad(m_topRight);
		return;
	}

	m_topRight.m_col = start.m_col + width;
	m_topRight.m_row = start.m_row + height;

	check_dots(m_bottomLeft, m_topRight);

	calc_width_height();
}
//------------------------------
void Rectangle::check_dots(const Vertex& bottomLeft, const Vertex& topRight)
{
	if (!(bottomLeft.isValid() && topRight.isValid() && bottomLeft.relative_valid_with(topRight)))

		m_bottomLeft.assign_default_quad(m_topRight);
}
//------------------------------
void Rectangle::calc_width_height()
{
	m_width = m_topRight.m_col - m_bottomLeft.m_col;

	m_height = m_topRight.m_row - m_bottomLeft.m_row;
}
//------------------------------
void Rectangle::draw(Board& board) const
{

	Vertex topLeft(m_bottomLeft.m_col, m_topRight.m_row);
	Vertex bottomRight(m_topRight.m_col, m_bottomLeft.m_row);

	board.drawLine(m_bottomLeft, bottomRight);
	board.drawLine(m_bottomLeft, topLeft);
	board.drawLine(m_topRight, bottomRight);
	board.drawLine(m_topRight, topLeft);
}

//------------------------------
Rectangle Rectangle::getBoundingRectangle() const
{
	Rectangle rect(m_bottomLeft, m_topRight);

	return rect;
}
//------------------------------
double Rectangle::getArea() const
{
	return m_width * m_height;
}
//------------------------------
double Rectangle::getPerimeter() const
{
//		check if rectangle is just a line
	if (m_bottomLeft.m_col - m_topRight.m_col == 0)
		return m_height;
	else if (m_bottomLeft.m_row - m_topRight.m_row == 0)
		return m_width;

	return (m_width * 2 + m_height * 2);
}
//------------------------------
Vertex Rectangle::getCenter() const
{
	return m_bottomLeft.getCenter_quad(m_topRight);
}
//------------------------------
bool Rectangle::scale(double factor)
{
	bool is_scale_valid =  m_bottomLeft.scale_quad(m_topRight, factor);

	if (is_scale_valid)
		calc_width_height();

	return is_scale_valid;
}
//------------------------------
Vertex Rectangle::getBottomLeft() const
{
	return m_bottomLeft;
}
//------------------------------
Vertex Rectangle::getTopRight()const
{
	return m_topRight;
}
//------------------------------
double Rectangle::getWidth() const
{
	return m_width;
}
//------------------------------
double Rectangle::getHeight() const
{
	return m_height;
}