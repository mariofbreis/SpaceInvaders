#include "position.h"
Position::Position() {};

Position::Position(float x, float y, float z) : _x(x), _y(y), _z(z) {}

Position::~Position() {}

void Position::setXYZ(float x, float y, float z) 
{
	_x=x;
	_y=y;
	_z=z;
}


bool operator==(Position &p1, Position &p2) {
	return (p1.getX() == p2.getX() && p1.getY() == p2.getY() && p1.getZ() == p2.getZ());
}