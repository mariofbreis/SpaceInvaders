#include "alien.h"

Alien::Alien(float r, float g, float b, float x, float y, float z) : Entity(r, g, b, x, y, z) {}

Alien::~Alien() {}

void Alien::move(float distX, float distY) 
{
	float x=_position.getX()+distX;
	float y=_position.getY()+distY;

	_position.setX(x);
	_position.setY(y);

}
