#include "Board.h"
#include "Rectangle.h"

class Square {
public:
//		constructors
	Square(const Vertex& bottomLeft, const Vertex& topRight);
	Square(const Vertex& start, double length);

//		specific functions
	Vertex getBottomLeft();
	Vertex getTopRight();
	double getLength();
	void assign_default_values();


//		general functions
	void draw(Board& board);
	Rectangle getBoundingRectangle();
	double getArea();
	double getPerimeter();
	Vertex getCenter();
	bool scale(double factor);

private:
//		helper functions
	void calc_length();
	bool is_length_valid();


//		members
	Vertex m_bottomLeft, m_topRight;
	double m_length;
};