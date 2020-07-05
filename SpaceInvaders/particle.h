#ifndef PARTICLE_H
#define PARTICLE_H

#include "spaceinvaders.h"
#include "position.h"

#define frand()			((float)rand()/RAND_MAX)


class Particle {
	float	life;		// life
	float	fade;		// fade
	float	 r,  g,  b; // colour
	float    x,  y,  z; // position
	float   vx, vy, vz; // speed
	float   ax, ay, az; // aceleration

public:
	Particle(int t, Position p);
	Particle( const Particle & another) { *this = another; }
	const Particle & operator = ( const Particle & another);
	const bool Update( const float elapsedTime);
	void       Draw() const;
	const bool IsAlive() const { return life>0.f; }
	const bool IsDead()  const { return life<=0.0f; } 

	static unsigned int LoadTexture( const string & textureBitmapFilename);

};


#endif