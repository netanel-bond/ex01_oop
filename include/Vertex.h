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
    

//      QUAD FUNCTIONS
    void assign_default_quad(Vertex& topRight);
//		delete if manage to succesfully write initiliazinion in constructors
    void copy_data(const Vertex& topRight, Vertex& m_bottomLeft, Vertex& m_topRight) const;
    bool relative_valid_with(const Vertex& topRight) const;
    bool isHigherThan(const Vertex& other) const;
    bool isToTheRightOf(const Vertex& other) const;
    Vertex getCenter_quad(const Vertex& topRight) const;
    void scaledValue(const Vertex& centerValue, Vertex& topRight, const double factor) const;
    bool scale_quad(Vertex& m_topRight, const double factor);
};

std::istream& operator>>(std::istream& istr, Vertex& v);
std::ostream& operator<<(std::ostream& ostr, const Vertex& v);
