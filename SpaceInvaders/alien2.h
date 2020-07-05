#ifndef ALIEN2_H
#define ALIEN2_H

#include "spaceinvaders.h"
#include "alien.h"

class Alien2 : public Alien
{

public:

	Alien2(float r, float g, float b, float x, float y, float z);
	~Alien2();

	void draw();

	//bool wasReached(Point p);
};

#endif