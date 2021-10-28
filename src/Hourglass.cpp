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
        upper.getHeight()!=-lower.getHeight())
    {

    }


}

double Hourglass::getLength() const {
    return m_length;
}
double Hourglass::getHeight() const {
    return m_height;
}