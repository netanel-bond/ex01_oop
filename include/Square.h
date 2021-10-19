#include "Board.h"
#include "Rectangle.h"

class Square {
public:
	Square(const Vertex& bottomLeft, const Vertex& topRight);
	Square(const Vertex& start, double length);

	Vertex getBottomLeft();
	Vertex getTopRight();
	double getLength();

	//shared functions
	void draw(Board& board);
	Rectangle getBoundingRectangle();
	double getArea();
	double getPerimeter();
	double getCenter();
	bool scale(double factor);



};