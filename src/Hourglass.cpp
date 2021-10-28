//
// Created by Bar Oren on 28/10/2021.
//
#include "Hourglass.h"
#include <iomanip>
#include <iostream>
#include "Utilities.h"
#include "Vertex.h"



Hourglass::Hourglass(const Triangle& upper, const Triangle& lower)
    :m_upper(upper), m_lower(lower)
    
{
    if(upper.getLength() != lower.getLength() &&
        upper.getVertex(2).m_col!=lower.getVertex(2).m_col&&
        upper.getVertex(2).m_row !=lower.getVertex(2).m_row)
    {
        
    }


}

Hourglass::Hourglass(const Triangle& lower)
    :m_lower(lower)
{
    Vertex top_left(lower.getVertex(0).m_col, lower.getVertex(0).m_row + 2 * lower.getHeight()),
        top_right(lower.getVertex(1).m_col, lower.getVertex(1).m_row + 2 * lower.getHeight());

    if (top_left.isValid() && top_right.isValid())
    {
        Triangle upper(top_left, top_right, -lower.getHeight());
    }
    else
    {

    }
}



void Hourglass::assign_default()
{

    Vertex baseLeftDown(20, 20),
        baseRightDown(30, 20),
        topDown(25, 20 + sqrt(75));

    Vertex dotsDown[] = { baseLeftDown, baseRightDown, topDown };
    Triangle tri_down(dotsDown);

    m_lower = tri_down;

    Vertex baseLeftUp(20, 20 + 2 * sqrt(75)),
            baseRightUp(30, 20 + 2 * sqrt(75)),
            topUp(25, 20 + sqrt(75));

    Vertex dotsUp[] = { baseLeftUp, baseRightUp, topUp };
    Triangle tri_up(dotsUp);

    m_upper = tri_up;

}

double Hourglass::getLength() const {
    return m_length;
}
double Hourglass::getHeight() const {
    return m_height;
}