#include "bases.h"

Bases::Bases() 
{
	bases = new std::vector<Base*>();
	int i;
	float x, y, z=0;

	for(i=0; i<4; i++)
	{
		x=-6+4*i;
		y=-5;
		bases->push_back(new Base (173/255, 1, 47/255, x, y, z));
	}
}

Bases::~Bases(){}

void Bases::drawBases(){
	for(std::vector<Base*>::iterator it=bases->begin(); it!=bases->end(); it++)
		(*it)->draw();
}

bool Bases::checkHealth(Position p){

	bool hit = false;

	for(std::vector<Base*>::iterator it=bases->begin(); it!=bases->end(); it++){
		if((*it)->checkHealth(p, BASE_SIZE))
		{
			if((*it)->numeroHits())
				bases->erase(it);
			hit = true;
			break;
		}
	}
	return hit;
}