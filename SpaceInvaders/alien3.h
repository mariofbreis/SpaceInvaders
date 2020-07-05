#ifndef ALIEN3_H
#define ALIEN3_H

#include "alien.h"

class Alien3 : public Alien
{

public:

	Alien3(float r, float g, float b, float x, float y, float z);
	~Alien3();

	void draw();

	//bool wasReached(Point p);
};

#endif