#pragma once
#include "Board.h"
#include "Rectangle.h"
#include "Vertex.h"

class Triangle {
public:
//      constructors
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


    //Triangle assign_default_triangle();


//      specific functions
    double getLength() const;
	double getHeight() const;


private:
    void calcTriangleLength();
    void calcTriangleHeight();

    double m_height ,m_length ;
    Vertex m_v0,m_v1,m_v2;

    Vertex calc_3rd_v(const Vertex &v0, const Vertex &v1,double height);
    bool check_triangle(const Vertex &v0, const Vertex &v1, const Vertex &v2) const;

};