#include "Board.h"

class Square {
public:
	Square(const Vertex& bottomLeft, const Vertex& topRight);
	Square(const Vertex& start, double length);

	Vertex getBottomLeft();
	Vertex getTopRight();
	double getLength();
};