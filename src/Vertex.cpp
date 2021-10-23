#include "Vertex.h"
#include "macros.h"

#include <iostream>

void Vertex::scaledValue(const Vertex& centerValue, Vertex& other, const double factor)
{
    double colDif = centerValue.m_col - this->m_col;
    double rowDif = centerValue.m_row - this->m_row;

    other.m_col = centerValue.m_col - (colDif * factor);
    other.m_row = centerValue.m_row - (rowDif * factor);
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
