#ifndef BASES_H
#define BASES_H

#include "spaceinvaders.h"
#include "base.h"

class Bases
{
	std::vector<Base*> *bases;

public:
	bool hit;
	Bases();
	~Bases();

	void drawBases();
	bool checkHealth(Position p);
};

#endif