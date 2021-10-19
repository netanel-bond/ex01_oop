#include "Board.h"

class Rectangle {
public:
	Rectangle(const Vertex& bottomLeft, const Vertex& topRight);
	Rectangle(const Vertex vertices[2]);
	Rectangle(double x0, double y0, double x1, double y1);
	
	Vertex getBottomLeft() const;
	Vertex getTopRight() const;

	double getWidth() const;
	double getHeight() const;

private:
	Vertex bottomLeft, topRight;
};