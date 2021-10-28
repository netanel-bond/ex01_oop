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

    }


}

double Hourglass::getLength() const {
    return m_length;
}
double Hourglass::getHeight() const {
    return m_height;
}