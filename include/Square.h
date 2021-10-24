#pragma once

#include "Board.h"
#include "Rectangle.h"

class Square {
public:
//		constructors
	Square(const Vertex& bottomLeft, const Vertex& topRight);
	Square(const Vertex& start, double length);

//		specific functions
	Vertex getBottomLeft() const;
	Vertex getTopRight()const ;
	double getLength() const;
	void check_dots(const Vertex& bottomLeft, const Vertex& topRight);

//		general functions
	void draw(Board& board) const;
	Rectangle getBoundingRectangle() const;
	double getArea() const;
	double getPerimeter() const;
	Vertex getCenter() const;
	bool scale(double factor);

private:
//		helper functions
	void calc_length();
	bool are_width_height_equal(const Vertex& bottomLeft, const Vertex& topRight);


//		members
	Vertex m_bottomLeft, m_topRight;
	double m_length, m_factor = 1;
};