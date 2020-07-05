#include "alien2.h"

Alien2::Alien2(float r, float g, float b, float x, float y, float z) : Alien(r, g, b, x, y, z) {}

Alien2::~Alien2(){}

void Alien2::draw()
{


	glPushMatrix(); 
	GLfloat mat_ambient[] = { 0.0, 0.8, 0.0, 1.0 };
	GLfloat mat_diffuse[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat mat_specular[] = { 0.0, 0.1, 0.0, 1.0 };
	GLfloat mat_shine = 0.25*128;

	glMaterialfv (GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv (GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv (GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf (GL_FRONT, GL_SHININESS, mat_shine);

	glTranslatef(_position.getX(),_position.getY(),_position.getZ());
	glRotatef(90, 1, 0, 0);
	glutSolidCube(0.6);
	glPushMatrix(); 
	glTranslatef(-0.15,-0.3,0);
	glRotatef(90,1,0,0);
	glutSolidCone(0.15,0.3,15,15);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.15,-0.3,0);
	glRotatef(90,1,0,0);
	glutSolidCone(0.15,0.3,15,15);
	glPopMatrix(); 
	glPopMatrix();
	glPushMatrix(); 
	glColor3f(1.0,1.0,1.0);
	glTranslatef(_position.getX()-0.1,_position.getY()+0.1,_position.getZ());
	glutSolidSphere(0.05, 20, 20);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(_position.getX()+0.1,_position.getY()+0.1,_position.getZ());
	glutSolidSphere(0.05, 20, 20);
	glPopMatrix();
}