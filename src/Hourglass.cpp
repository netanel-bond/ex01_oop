//
// Created by Bar Oren on 28/10/2021.
//
#include "Hourglass.h"
#include <iomanip>
#include <iostream>
#include "Utilities.h"
#include "Vertex.h"



Hourglass::Hourglass(const Triangle& upper,const Triangle& lower)

{
    if(upper.getLength() != lower.getLength() &&
        upper.getVertex(2).m_col!=lower.getVertex(2).m_col&&
        upper.getVertex(2).m_row !=lower.getVertex(2).m_row)
    {

    //lower.getVertex(0).assign_default_tri(lower.getVertex(1),lower.getVertex(2)) ;
    }


}
Hourglass :: Hourglass (const Triangle& lower)
{
    Vertex top_left(lower.getVertex(0).m_col,lower.getVertex(0).m_row+2*lower.getHeight()),
           top_right(lower.getVertex(1).m_col,lower.getVertex(1).m_row+2*lower.getHeight());
    if(top_left.isValid()&&top_right.isValid())
    {
        Triangle upper(top_left, top_right, -lower.getHeight());
    }
    else
    {

    }


}

void Hourglass::draw(Board &board) const
{
    m_lower.draw(board);
    m_upper.draw(board);
}
Rectangle Hourglass::getBoundingRectangle() const
{
    Vertex bottom_left(m_lower.getVertex(0).m_col,m_lower.getVertex(0).m_row ),
            top_right(m_upper.getVertex(1).m_col,m_upper.getVertex(1).m_row);
    Rectangle rect(bottom_left,top_right);
    return rect;
}
Vertex  Hourglass :: getCenter() const
{
    return m_upper.getVertex(2);
}
double Hourglass:: getArea()const
{
    return m_lower.getArea()+m_upper.getArea();
}
double Hourglass:: getPerimeter() const
{
    return m_lower.getPerimeter()+m_upper.getPerimeter();
}
double Hourglass::getLength() const {
    return m_length;
}
double Hourglass::getHeight() const {
    return m_height;
}