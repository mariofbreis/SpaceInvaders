#ifndef BASE_H
#define BASE_H

#include "spaceinvaders.h"
#include "entity.h"

class Base : public Entity
{
	int nHits;

public:

	Base(float r, float g, float b, float x, float y, float z);
	~Base();
	bool numeroHits();
	void draw();
};

#endif