#include "Board.h"
#include "Triangle.h"


class Hourglass {
public:
	Hourglass(const Triangle& upper, const Triangle& lower);
	Hourglass(const Triangle& lower);

    //		general functions
    void draw(Board& board) const;
    Rectangle getBoundingRectangle() const;
    double getArea() const;
    double getPerimeter() const;
    Vertex getCenter() const;
    bool scale(double factor);

	double getLength() const;
	double getHeight() const;

private:
    bool check_tris(const Triangle& lower, const Triangle& upper);
    void assign_default();
    void calc_length_height();
    Triangle m_lower, m_upper;
    double m_length , m_height;
};