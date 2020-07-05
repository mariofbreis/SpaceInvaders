#include "explosion.h"

Explosion::Explosion(int t, Position p, int particles)
{

	for ( int i=0; i<particles; i++)
		activeParticles.push_back( new Particle(t, p));
}


int Explosion::Update( const float elapsed)
{
	list<Particle*>::iterator it = activeParticles.begin();
	int x = 0;
	while ( it != activeParticles.end() ) {
		x++;
		(*it)->Update(elapsed);
		if ( (*it)->IsAlive() )
			it++;
		else
		{
			deadParticles.push_back( *it);
			it = activeParticles.erase( it);
		}
	}
	return x;
}


void Explosion::Draw() const
{
	list<Particle*>::const_iterator it = activeParticles.begin();
	while ( it != activeParticles.end() ) {
		(*it)->Draw();
		it++;
	}
}