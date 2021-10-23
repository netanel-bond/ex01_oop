#include <iomanip>
#include <Board.h>
#include <Vertex.h>
#include <macros.h>
#include <Square.h>
#include <Rectangle.h>

Square::Square(const Vertex& bottomLeft, const Vertex& topRight)
{
	
	if (bottomLeft.isValid() && topRight.isValid() && bottomLeft.relative_valid_with(topRight))
		bottomLeft.copy_data(topRight, m_bottomLeft, m_topRight);
	else
		m_bottomLeft.assign_default_quad(m_topRight);

	calc_length();
}

Square::Square(const Vertex& start, double length)
{

	Vertex topRight;
	topRight.m_col = start.m_col + length;
	topRight.m_row = start.m_row + length;

	if (start.isValid() && length >= 0)
		start.copy_data(topRight, m_bottomLeft, m_topRight);
	else
		m_bottomLeft.assign_default_quad(m_topRight);

	calc_length();
}

Vertex Square::getBottomLeft()
{
	return m_bottomLeft;
}

void Square::draw(Board& board)
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

Rectangle Square::getBoundingRectangle()
{
	Rectangle rect(m_bottomLeft, m_topRight);

	return rect;
}

double Square::getArea()
{
	return m_length * m_length;
}
double Square::getPerimeter()
{
	return m_length * 2;
}
Vertex Square::getCenter()
{

}
bool scale(double factor);

Vertex Square::getTopRight()
{
	return m_topRight;
}
double Square::getLength()
{
	return m_length;
}

void Square::assign_default_values()
{
	m_bottomLeft.m_col = 20;
	m_bottomLeft.m_row = 10;
	m_topRight.m_col = 30;
	m_topRight.m_row = 20;

	m_length = m_topRight.m_row - m_bottomLeft.m_row;
}

bool Square::is_length_valid()
{
	double width = m_topRight.m_col - m_bottomLeft.m_col;
	double height = m_topRight.m_row - m_bottomLeft.m_row;

	return width - height == 0;
}

void Square::calc_length()
{
	m_length = m_topRight.m_col - m_bottomLeft.m_col;
}