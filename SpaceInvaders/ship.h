#ifndef SHIP_H
#define SHIP_H

#include "entity.h"
#include "bombs.h"
#include "spaceinvaders.h"

class Ship : public Entity
{
	//Variavel tempo;
	int tempo;
	Bombs bombs;

public:
	Ship(float r, float g, float b, float x, float y, float z) ;
	~Ship();

	void draw();

	void moveShip(int varTempo,int direction);
	void setTempo(int x) { tempo=x; }

	// Funcao que faz a nave disparar
	void fire();
	list<Position> Ship::returnBombs();

	void removeBomb(Position p);

};

#endif