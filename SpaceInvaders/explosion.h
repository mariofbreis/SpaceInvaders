#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "spaceinvaders.h"
#include "particle.h"
#include "position.h"

class Explosion
{
public:
	Explosion(int t, Position p, int particles);
	int Update( const float elapsed);
	void Draw() const;
	const int NoParticles() const { return (int) activeParticles.size(); }
protected:
	list<Particle*> activeParticles, deadParticles;
	bool              respawnParticles;
	static int        Max_Particles;
};

#endif