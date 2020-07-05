#ifndef ALIEN_H
#define ALIEN_H

#include "entity.h"
#include "bombs.h"

class Alien : public Entity 
{

public:
	Alien(float r, float g, float b, float x, float y, float z);
	~Alien();

	virtual void draw()=0;
	void move(float distX, float distY);
};

#endif