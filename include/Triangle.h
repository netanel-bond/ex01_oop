#include "Board.h"
#include "Rectangle.h"
#include "Vertex.h"

class Triangle {
public:
	Triangle(const Vertex vertices[3]);
	Triangle(const Vertex& v0, const Vertex& v1, double height);
	Vertex getVertex(int index) const;

    //		general functions
    void draw(Board& board) const;
    Rectangle getBoundingRectangle() const;
    double getArea() const;
    double getPerimeter() const;
    Vertex getCenter() const;
    bool scale(double factor);


    Triangle assign_default_triangle();



    double getLength() const;
	double getHeight() const;

private:
    void calcTriangleLengh();
    void calcTriangleHeight();

    double m_height ,m_lengh ,m_factor=1;
    Vertex m_v0,m_v1,m_v2;

    Vertex calc_3rd_v(const Vertex &v0, const Vertex &v1,double height);
};