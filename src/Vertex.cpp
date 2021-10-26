#include "Vertex.h"
#include "macros.h"

#include <iostream>
Vertex Vertex::get_center_tri(const Vertex& baseRight, const Vertex& top)const
{

    bool same_col = this->m_col - top.m_col == 0;
    bool same_row = this->m_row - top.m_row == 0;

    //		check if both dots are the same
    if (same_col && same_row)
        return *this;

    Vertex center_dot;

    center_dot.m_col=(this->m_col+baseRight.m_col+top.m_col)/3;
    center_dot.m_row=(this->m_row+baseRight.m_row+top.m_row)/3;

    if (same_col)
        center_dot.m_col = this->m_col;

    else if (same_row)
        center_dot.m_row = this->m_row;

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
void Vertex::scaledValue(const Vertex& centerValue, Vertex& other, const double factor) const
{
    double colDif = centerValue.m_col - this->m_col;
    double rowDif = centerValue.m_row - this->m_row;

    other.m_col = centerValue.m_col - (colDif * factor);
    other.m_row = centerValue.m_row - (rowDif * factor);
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
        newBottomLeft.copy_data(newTopRight, *this, m_topRight);
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

void Vertex::copy_data(const Vertex& topRight, Vertex& m_bottomLeft, Vertex& m_topRight) const
{
    m_bottomLeft.m_col = this->m_col;
    m_bottomLeft.m_row = this->m_row;
    m_topRight.m_row = topRight.m_row;
    m_topRight.m_col = topRight.m_col;
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
