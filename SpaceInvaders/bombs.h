#ifndef BOMBS_H
#define BOMBS_H

#include "spaceinvaders.h"
#include "position.h"

class Bombs
{
	list<Position> bombs;
	int velocidade;
	double _x;
	double _y;
	double _z;
	double _r;
	double _g;
	double _b;

public:

	Bombs();

	void setVelocidade(int v) { velocidade=v; }
	void bomb(Position p);
	void moveBombs(int varTempo, int direction);
	void clear();
	void drawBombs();
	void drawBombsShip();
	list<Position> returnBombs();
	void removeBomb(Position p);
};

#endif