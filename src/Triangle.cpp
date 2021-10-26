//
// Created by Bar Oren on 24/10/2021.
//
#include <iomanip>
#include "Vertex.h"
#include "Triangle.h"
#include "Utilities.h"


Vertex Triangle::getCenter() const
{
    return m_v0.get_center_tri(m_v1,m_v2);
}
Triangle::Triangle(const Vertex& v0, const Vertex& v1, double height)
:m_v0(v0),m_v2(v1),m_height(height)
{
    calc_3rd_v(v0, v1, height);

    if (v0.isValid() && v1.isValid() &&
        doubleEqual(distance(v0, v1), distance(v1, m_v2) && v0.relative_valid_with(v1) &&
        doubleEqual(distance(v1, m_v2), distance(v0, m_v2))))
    {
        m_v0.copy_data(v0, m_v1, m_v2);
    } else
        m_v0.assign_default_quad(m_v1);


}
Rectangle Triangle::getBoundingRectangle() const
{
    Vertex bottomLeft;

    Rectangle rect(m_v0,m_v2);
}

bool Triangle::scale(double factor)
{
    return m_v2.scale_quad(m_v0, factor);

}
void Triangle::draw(Board& board) const
{
    board.drawLine(m_v0, m_v1);
    board.drawLine(m_v1,m_v2);
    board.drawLine(m_v2,m_v0);
}

void Triangle::calc_3rd_v(const Vertex &v0, const Vertex &v1, double height) {
    m_v2.m_col=((v0.m_col - v1.m_col) / 2);
    m_v2.m_row=(v0.m_row + height);//need to extract to function

}

Triangle::Triangle(const Vertex vertices[3])
{
    if (vertices[0].isValid() && vertices[1].isValid() && vertices[2].isValid() &&
        vertices[2].relative_valid_with(vertices[1]))
        vertices[0].copy_data(m_v0, m_v1, m_v2);
    else
        m_v0.assign_default_quad(m_v1);
}
double Triangle::getPerimeter() const
{
    return m_lengh*3;
}
//Vertex Triangle::getCenter() const
//{
//
//}

double Triangle::getArea() const
{
    return (m_lengh*m_height)/2;
}
void Triangle::calcTriangleHeight()
{
    m_height=m_v1.m_row-m_v0.m_row;
}

void Triangle::calcTriangleLengh()
{
    m_lengh= m_v2.m_col - m_v0.m_col;
}
double Triangle::getHeight() const
{
    return m_height;
}
double Triangle::getLength() const
{
    return m_lengh;
}

Vertex Triangle::getVertex(int index) const {
    switch (index) {
        case 0:
            return m_v0;
            break;
        case 1:
            return m_v1;
            break;
        case 2:
            return m_v2;
            break;
    }
    return m_v0;// i dont know what to return by defult.

}
