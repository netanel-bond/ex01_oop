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
	bool is_dot_valid(const Vertex& dot);
	bool is_dot_valid(double x, double y);
	void assign_default_values();
	Vertex m_bottomLeft, m_topRight;
	double width, height;
};