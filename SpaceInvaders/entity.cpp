#include "entity.h"

Entity::Entity(float r, float g, float b, float x, float y, float z) : _color(r, g, b), _position(x, y, z) {}

Entity::~Entity() {}

bool Entity::checkHealth(Position p, float size)
{
	float posX = _position.getX();
	float posY = _position.getY();
	float posZ = _position.getZ();

	float intersection = pow((posX - p.getX()), 2) + pow((posY - p.getY()), 2) + pow((posZ - p.getZ()), 2);

	if(intersection < pow((size+TAMANHO_BALA),2))
	{
		return true;
	}

	return false; 
}

