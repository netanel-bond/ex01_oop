#include <iomanip>
#include <Board.h>
#include <Vertex.h>
#include <macros.h>
#include <Square.h>

Square::Square(const Vertex& bottomLeft, const Vertex& topRight)
	:m_bottomLeft(bottomLeft), m_topRight(topRight)
{
	check_dots(bottomLeft, topRight);

	calc_length();
}

Square::Square(const Vertex& start, double length)
	:m_bottomLeft(start)
{

	if (length < 0)
	{
		m_bottomLeft.assign_default_quad(m_topRight);
		return;
	}
		
	Vertex topRight(start.m_col + length, start.m_row + length);

	check_dots(m_bottomLeft, m_topRight);

	calc_length();
}

void Square::draw(Board& board) const
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

void Square::check_dots(const Vertex& bottomLeft, const Vertex& topRight)
{
	if (!(bottomLeft.isValid() && topRight.isValid() && bottomLeft.relative_valid_with(topRight)
		&& are_width_height_equal(bottomLeft, topRight)))

		m_bottomLeft.assign_default_quad(m_topRight);
}

Rectangle Square::getBoundingRectangle() const
{
	Rectangle rect(m_bottomLeft, m_topRight);

	return rect;
}

double Square::getArea() const
{
	return m_length * m_length * m_factor * m_factor;
}
double Square::getPerimeter() const
{
	double width = m_topRight.m_col - m_bottomLeft.m_col;
	double height = m_topRight.m_row - m_bottomLeft.m_row;

	if (width == 0)
		return height;
	if (height == 0)
		return width;

	return m_length * 4 * m_factor;
}
Vertex Square::getCenter() const
{
	return m_bottomLeft.getCenter_quad(m_topRight);
}
bool Square::scale(double factor)
{
	bool is_scale_valid =  m_bottomLeft.scale_quad(m_topRight, factor);

	if (is_scale_valid)
		m_factor = factor;

	return is_scale_valid;
}

Vertex Square::getBottomLeft() const
{
	return m_bottomLeft;
}

Vertex Square::getTopRight() const
{
	return m_topRight;
}

double Square::getLength() const
{
	return m_length * m_factor;
}

bool Square::are_width_height_equal(const Vertex& bottomLeft, const Vertex& topRight)
{
	double width = topRight.m_col - bottomLeft.m_col;
	double height = topRight.m_row - bottomLeft.m_row;

	if (width == 0 || height == 0)
		return true;

	return width - height == 0;
}

void Square::calc_length()
{
	m_length = m_topRight.m_col - m_bottomLeft.m_col;
}