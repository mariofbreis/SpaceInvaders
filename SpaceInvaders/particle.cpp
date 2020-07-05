#include "particle.h"


int explosionTexture;

Particle::Particle(int t, Position p)
{
	life = 1.0f;

	explosionTexture = t;

	x = p.getX();
	y = p.getY();
	z = p.getZ()+cos(2*frand())/2;

	double v = 0.2*frand();
	double phi = frand()*PI;
	double theta = 2.0*frand()*PI;

	vx = (v+0.2) * cos(theta) * sin(phi);
	vy = (v+0.2) * sin(theta) * sin(phi);
	vz = v * cos(phi);
	ax =  0.01f; /* just a little wind */
	ay =  0.00f;
	az =  -0.15f; /* gravity pull */

	/* yelowish colour to be multiplied by the texture grey tone */
	r = 0.882f;
	g = 0.552f;
	b = 0.211f;
}



const bool Particle::Update(const float elapsedTime)
{
	if ( z > -2 )
	{
		float delta = elapsedTime * .00378;
		x += (vx * delta);
		y += (vy * delta);
		z += (vz * delta);
		vx += (ax * delta);
		vy += (ay * delta);
		vz += (az * delta);
		return true;
	}
	life = 0;
	return false;
}


void Particle::Draw() const
{
	glPushMatrix();
	glTranslatef( x, y, z);
	glColor4f( r, g, b, life);
	glPushMatrix();
	glutSolidCube(0.050);
	glPopMatrix();
	glPopMatrix();
}
