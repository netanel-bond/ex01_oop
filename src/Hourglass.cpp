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

    lower.getVertex(0).assign_default_tri(lower.getVertex(1),lower.getVertex(2)) ;




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

double Hourglass::getLength() const {
    return m_length;
}
double Hourglass::getHeight() const {
    return m_height;
}