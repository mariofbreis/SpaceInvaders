#ifndef ALIEN1_H
#define ALIEN1_H

#include "spaceinvaders.h"
#include "alien.h"

class Alien1 : public Alien
{

public:

	Alien1(float r, float g, float b, float x, float y, float z);
	~Alien1();

	void draw();

	//bool wasReached(Point p);
};

#endif