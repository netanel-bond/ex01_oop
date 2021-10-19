#include "Board.h"
#include "Triangle.h"


class Hourglass {
public:
	Hourglass(const Triangle& upper, const Triangle& lower);
	Hourglass(const Triangle& lower);

	double getLength() const;
	double getHeight() const;
};