//
// Created by Bar Oren on 24/10/2021.
//
#include <iomanip>
#include "Vertex.h"
#include "Triangle.h"
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

}
