#ifndef ALIENS_H
#define ALIENS_H

#include "spaceinvaders.h"
#include "Alien1.h"
#include "Alien2.h"
#include "Alien3.h"

class Aliens
{
	Bombs bombsAliens;

	std::vector<Alien1> alien1Lista1;
	std::vector<Alien1> alien1Lista2;
	std::vector<Alien2> alien2Lista1;
	std::vector<Alien2> alien2Lista2;
	std::vector<Alien3> alien3Lista1;
	std::vector<Alien3> alien3Lista2;
	float speed;
	int direction;
	int moves;
	int tempo;

public:

	Aliens();
	~Aliens();

	void drawAliens();
	void addAliens();
	void removeAliens();
	void moveAliens(int varTempo);
	void fireAliens();
	void moveBombs(int tempo);
	bool Aliens::checkHealth(Position p);
	list<Position> returnBombs();
	list<Alien*> *getAliens();
	void Aliens::removeBombs(Position p);
};

#endif