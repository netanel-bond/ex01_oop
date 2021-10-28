#include "Vertex.h"
#include "macros.h"
#include "Triangle.h"
#include <iostream>
#include <cmath>

Vertex Vertex::get_center_tri(const Vertex& baseRight, const Vertex& top)const
{
    Vertex center_dot;

    center_dot.m_col=(this->m_col+baseRight.m_col+top.m_col)/3;
    center_dot.m_row=(this->m_row+baseRight.m_row+top.m_row)/3;

    return center_dot;
}
Vertex Vertex::getCenter_quad(const Vertex& topRight) const
{
    bool same_col = this->m_col - topRight.m_col == 0;
    bool same_row = this->m_row - topRight.m_row == 0;

    //		check if both dots are the same
    if (same_col && same_row)
        return *this;

    Vertex center_dot;

    //		assume rectangle is normal
    center_dot.m_col = this->m_col + (topRight.m_col - this->m_col) / 2;
    center_dot.m_row = this->m_row + (topRight.m_row - this->m_row) / 2;

    if (same_col)
        center_dot.m_col = this->m_col;

    else if (same_row)
        center_dot.m_row = this->m_row;

    return center_dot;
}

//  this - the old dot
//  other - the new dot
void Vertex::scaledValue(const Vertex &center_dot, Vertex &new_dot, const double factor) const
{
    double colDif = center_dot.m_col - this->m_col;
    double rowDif = center_dot.m_row - this->m_row;

    new_dot.m_col = center_dot.m_col - (colDif * factor);
    new_dot.m_row = center_dot.m_row - (rowDif * factor);
}

bool Vertex::scale_tri(Vertex& m_v1 , Vertex& m_v2,const Vertex& center_dot, const double factor)
{
    if (factor <=0)
        return false;


    Vertex new_base_left, new_top,new_base_right;

    this->scaledValue(center_dot,new_base_left,factor);
    m_v1.scaledValue(center_dot,new_base_right,factor);
    m_v2.scaledValue(center_dot,new_top,factor);
    if( new_base_left.isValid() && new_base_right.isValid() && new_top.isValid())
    {
        *this=new_base_left;
        m_v1=new_base_right;
        m_v2=new_top;
        return true;

    }

    return false;
}

bool Vertex::scale_quad(Vertex& m_topRight, const double factor)
{
    if (factor <= 0)
        return false;

    Vertex centerDot = this->getCenter_quad(m_topRight);

    Vertex newBottomLeft, newTopRight;

    this->scaledValue(centerDot, newBottomLeft, factor);
    m_topRight.scaledValue(centerDot, newTopRight, factor);

    if (newBottomLeft.isValid() && newTopRight.isValid() && newBottomLeft.relative_valid_with(newTopRight))
    {

        *this = newBottomLeft;
        m_topRight = newTopRight;
        return true;
    }

    return false;
}

//  check if rectangle/square are valid
//  this - bottom left, other - top right
bool Vertex::relative_valid_with(const Vertex& topRight) const
{
    return !(this->isToTheRightOf(topRight) ||
                    this->isHigherThan(topRight));
}


void Vertex::assign_default_tri(  Vertex &rightBase,  Vertex &top) {
    this->m_col=20;
    this->m_row= 20;
    rightBase.m_col=30;
    rightBase.m_row=20;
    top.m_col=25;
    top.m_row=20+sqrt(75);
}



void Vertex::assign_default_quad(Vertex& topRight)
{
    this->m_col = 20;
    this->m_row = 10;
    topRight.m_col = 30;
    topRight.m_row = 20;
}

bool Vertex::isHigherThan(const Vertex& other) const
{
    return m_row > other.m_row;
}

bool Vertex::isToTheRightOf(const Vertex& other) const
{
    return m_col > other.m_col;
}

bool Vertex::isValid() const
{
    return m_col >= 0 && m_col <= MAX_COL && m_row >= 0 && m_row <= MAX_ROW;
}

std::istream& operator>>(std::istream& istr, Vertex& v)
{
    return istr >> v.m_col >> v.m_row;
}

std::ostream& operator<<(std::ostream& ostr, const Vertex& v)
{
    return ostr << "(" << v.m_col << ", " << v.m_row << ")";
}
