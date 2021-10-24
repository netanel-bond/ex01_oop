#pragma once

#include "Board.h"

class Rectangle {
public:
//		Constructors
	Rectangle(const Vertex& bottomLeft, const Vertex& topRight);
	Rectangle(const Vertex vertices[2]);
	Rectangle(double x0, double y0, double x1, double y1);
	Rectangle(const Vertex& start, double width, double height);

//		general functions
	void draw(Board& board) const;
	Rectangle getBoundingRectangle() const;
	double getArea() const;
	double getPerimeter() const;
	Vertex getCenter() const;
	bool scale(double factor);
	
//		specific functions
	Vertex getBottomLeft() const;
	Vertex getTopRight() const;

	double getWidth() const;
	double getHeight() const;

	void check_dots(const Vertex& bottomLeft, const Vertex& topRight);

private:
//		helper functions
	void calc_width_height();

//		members
	Vertex m_bottomLeft, m_topRight;
	double m_width, m_height;
};