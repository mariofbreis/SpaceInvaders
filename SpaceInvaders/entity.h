#ifndef ENTITY_H
#define ENTITY_H

#include "spaceinvaders.h"
#include "color.h"
#include "position.h"

class Entity
{
protected:
	Color _color;
	Position _position;

public:
	Entity();
	Entity(float r, float g, float b, float x, float y, float z);
	~Entity();

	Color getColor() {return _color;}
	Position getPosition() {return _position;}

	void setColor(Color color) {_color=color;}
	void setPosition(Position position) {_position=position;}
	bool checkHealth(Position p, float size);
	virtual void draw()=0;

};

#endif