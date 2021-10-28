//
// Created by Bar Oren on 24/10/2021.
//
#include <iomanip>
#include "Vertex.h"
#include "Triangle.h"
#include "Utilities.h"
#include <iostream>

Vertex Triangle::getCenter() const
{
    return m_v0.get_center_tri(m_v1,m_v2);
}

Triangle::Triangle(const Vertex& v0, const Vertex& v1, double height)
:m_v0(v0),m_v1(v1),m_height(height)
{

    Vertex v2=calc_3rd_v(v0, v1,height);
//add the if to function
    if (!(v0.isValid() && v2.isValid() &&
        doubleEqual(distance(v0, v1),distance(v1, v2) && v0.m_row==v1.m_row &&
        doubleEqual(distance(v0, v1), distance(v0, v2)))))
    {

        m_v0.assign_default_tri(m_v1, m_v2);

    }
        calcTriangleLengh();
        calcTriangleHeight();

    //calc_3rd_v(v0, v1, height);


}
Rectangle Triangle::getBoundingRectangle() const
{
    Vertex bottom_left ,top_right;
    if(m_v0.m_row>m_v2.m_row)
    {
        bottom_left.m_col=m_v0.m_col;
        bottom_left.m_row=m_v2.m_row;
        top_right.m_col=m_v1.m_col;
        top_right.m_row=m_v1.m_row;
    } else {
        bottom_left.m_col = m_v0.m_col;
        bottom_left.m_row = m_v0.m_row;
        top_right.m_col=m_v1.m_col;
        top_right.m_row=m_v2.m_row;
    }


    Rectangle rect(bottom_left, top_right);
    return rect;
}

bool Triangle::scale(double factor)
{
   if (m_v0.scale_tri(m_v1,m_v2, factor)) {

       m_factor = factor;
       calcTriangleLengh();
       return true;
   }
   return false;

}
void Triangle::draw(Board& board) const
{
    board.drawLine(m_v0, m_v1);
    board.drawLine(m_v1,m_v2);
    board.drawLine(m_v2,m_v0);
}

Vertex Triangle::calc_3rd_v(const Vertex &v0, const Vertex &v1,double height)
{

    m_v2.m_col=((v0.m_col - v1.m_col) / 2);
    m_v2.m_row=(v0.m_row + height);//need to extract to function
    return m_v2;
}

Triangle::Triangle(const Vertex vertices[3])
: m_v0(vertices[0]), m_v1(vertices[1]), m_v2(vertices[2])
{
    calcTriangleHeight();

    if (!(vertices[0].isValid() && vertices[1].isValid() && vertices[2].isValid() &&
        vertices[0].m_row==vertices[1].m_row &&
            doubleEqual(distance(vertices[0],vertices[1]),distance(vertices[0],vertices[2])) &&
            doubleEqual(distance(vertices[0],vertices[1]),distance(vertices[1],vertices[2]))))
         m_v0.assign_default_tri(m_v1,m_v2);

    calcTriangleLengh();
    calcTriangleHeight();
    std::cout<< "height" << m_height;

}

double Triangle::getPerimeter() const
{
    if (m_v0.m_col==m_v2.m_col)
        return m_lengh;

    return m_lengh*3;
}


double Triangle::getArea() const
{
    if(m_height<0)
        return (m_lengh*-m_height)/2;
    return (m_lengh*m_height)/2;
}
void Triangle::calcTriangleHeight()
{

         m_height=m_v2.m_row-m_v0.m_row;


}

void Triangle::calcTriangleLengh()
{
    m_lengh= (m_v1.m_col - m_v0.m_col);
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
    //return m_v0;// i dont know what to return by defult.

    return Vertex();
}
