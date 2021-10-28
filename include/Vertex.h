#pragma once

#include <iosfwd>

struct Vertex
{
    double m_col = 0; // x
    double m_row = 0; // y

    Vertex() = default;
    Vertex(double col, double row) : m_col(col), m_row(row) {}

//      general functions
    bool isValid() const;
    bool isHigherThan(const Vertex& other) const;
    bool isToTheRightOf(const Vertex& other) const;
    
    //CHANGE TO GENERAL
    void copy_data(const Vertex& topRight, Vertex& m_bottomLeft, Vertex& m_topRight) const;
    void scaledValue(const Vertex& centerValue, Vertex& topRight, const double factor) const;

//      QUAD FUNCTIONS
    void assign_default_quad(Vertex& topRight);
    bool relative_valid_with(const Vertex& topRight) const;
    Vertex getCenter_quad(const Vertex& topRight) const;
    bool scale_quad(Vertex& m_topRight, const double factor);

 //     TRIANGLE FUNCTIONS
    void  assign_default_tri(Vertex& rightBase, Vertex& top);
    Vertex get_center_tri(const Vertex& baseRight, const Vertex& top) const;
    bool scale_tri(Vertex& m_v1 , Vertex& m_v2,const double factor);

// Hourglass functions

    void assign_default_hourglass()

};

std::istream& operator>>(std::istream& istr, Vertex& v);
std::ostream& operator<<(std::ostream& ostr, const Vertex& v);
