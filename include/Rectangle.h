#pragma once

#include "Board.h"

class Rectangle {
public:
	Rectangle(const Vertex& bottomLeft, const Vertex& topRight);
	Rectangle(const Vertex vertices[2]);
	Rectangle(double x0, double y0, double x1, double y1);
	Rectangle(const Vertex& start, double width, double height);
	
	Vertex getBottomLeft() const;
	Vertex getTopRight() const;

	double getWidth() const;
	double getHeight() const;

private:
	bool are_dots_valid(const Vertex& bottomLeft, const Vertex& topRight);
	void assign_default_values();
//		delete if manage to succesfully write initiliazinion in constructors
	void copy_data(const Vertex& bottomLeft, const Vertex& topRight);

	Vertex m_bottomLeft, m_topRight;
	double m_width, m_height;
};