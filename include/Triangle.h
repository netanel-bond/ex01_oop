#include "Board.h"

class Triangle {
public:
	Triangle(const Vertex vertices[3]);
	Triangle(const Vertex& v0, const Vertex& v1, double height);
	Vertex getVertex(int index) const;

	double getLength() const;
	double getHeight() const;


};