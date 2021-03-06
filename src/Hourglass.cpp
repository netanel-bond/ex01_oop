//
// Created by Bar Oren on 28/10/2021.
//
#include "Hourglass.h"
#include <iomanip>
#include <iostream>
#include <cmath>
#include "Utilities.h"
#include "Vertex.h"



//------------------------------
// constructor
Hourglass::Hourglass(const Triangle& upper, const Triangle& lower)
    :m_upper(upper), m_lower(lower)
{
    if(check_tris(m_lower, m_upper))
        assign_default();

    calc_length_height();
}
//------------------------------
// constructor
Hourglass::Hourglass(const Triangle& lower)
    :m_lower(lower), m_upper(lower)
{
    m_height = m_lower.getHeight() * 2;
    Vertex baseLeftUp(m_lower.getVertex(0).m_col,
                      m_lower.getVertex(0).m_row + int(m_height));
    Vertex baseRightUp(m_lower.getVertex(1).m_col,
                       m_lower.getVertex(1).m_row + int(m_height));

    if (!(baseLeftUp.isValid() && baseRightUp.isValid()))
    {// if not valid assign defualt
        assign_default();
        return;
    }
        
    Vertex dotsUp[] = { baseLeftUp, baseRightUp, m_lower.getVertex(2) };

    Triangle newUp(dotsUp);

    m_upper = newUp;

    if (check_tris(m_lower, m_upper))
        assign_default();

    calc_length_height();
}
//------------------------------
bool Hourglass::check_tris(const Triangle& lower, const Triangle& upper)
{
    return (upper.getLength() != lower.getLength() &&
        upper.getVertex(2).m_col != lower.getVertex(2).m_col &&
        upper.getVertex(2).m_row != lower.getVertex(2).m_row &&
                                                    m_upper.getHeight() > -1);
}


//------------------------------
//the function assinging the default values for th hourglass
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

    calc_length_height();
}
//---------------------------------
//scaleing the hourglass
bool Hourglass::scale(double factor)
{
    Vertex v0=m_lower.getVertex(0),v1=m_lower.getVertex(1),
                v2=m_lower.getVertex(2),
           v0up=m_upper.getVertex(0), v1up=m_upper.getVertex(1),
                v2up=m_upper.getVertex(2);

    bool is_scale_valid = v0.scale_tri(v1,v2,v2,factor) &&
                          v0up.scale_tri(v1up,v2up,v2up,factor);
    Vertex  dotsDown[] = { v0, v1, v2 },
            dotsUp[]={v0up,v1up,v2up};
    if (is_scale_valid)
    {
        Triangle newUp(dotsUp), newDown(dotsDown);
        m_upper=newUp;
        m_lower=newDown;
        calc_length_height();

        return true;
    }
        
    return false;
}
//------------------------------
void Hourglass::calc_length_height()
{
    m_length = m_lower.getLength();
    m_height = m_lower.getHeight() * 2;
}
//------------------------------
void Hourglass::draw(Board &board) const
{
    m_upper.draw(board);
    m_lower.draw(board);

}
//------------------------------
Rectangle Hourglass::getBoundingRectangle() const
{
    Vertex bottom_left(m_lower.getVertex(0).m_col,m_lower.getVertex(0).m_row ),
            top_right(m_upper.getVertex(1).m_col,m_upper.getVertex(1).m_row);
    Rectangle rect(bottom_left,top_right);
    return rect;
}
//------------------------------
Vertex  Hourglass :: getCenter() const
{
    return m_upper.getVertex(2);
}
//------------------------------
double Hourglass:: getArea()const
{
    return m_lower.getArea()+m_upper.getArea();
}
//------------------------------
double Hourglass:: getPerimeter() const
{
    return m_lower.getPerimeter()+m_upper.getPerimeter();
}
//------------------------------
double Hourglass::getLength() const {
    return m_length;
}
//------------------------------
double Hourglass::getHeight() const {
    return m_height;
}