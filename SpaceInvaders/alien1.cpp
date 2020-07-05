#include "Alien1.h"

Alien1::Alien1(float r, float g, float b, float x, float y, float z) : Alien(r, g, b, x, y, z) {}

Alien1::~Alien1(){}


void Alien1::draw()
{
	glPushMatrix(); 

	GLfloat mat_ambient[] = { 0.8, 0.0, 0.0, 1.0 };
	GLfloat mat_diffuse[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat mat_specular[] = { 0.1, 0.0, 0.0, 1.0 };
	GLfloat mat_shine = 0.25*128;

	glMaterialfv (GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv (GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv (GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf (GL_FRONT, GL_SHININESS, mat_shine);

	glTranslatef(_position.getX(),_position.getY(),_position.getZ());
	glRotatef(90, 1, 0, 0);
	glutSolidSphere(0.3, 20, 20);
	glPushMatrix(); 
	glTranslatef(0.2,0.15,0);
	glRotatef(60,0,0,1);
	glScalef(4,1,1);
	glutSolidCube(0.1);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-0.2,0.15,0);
	glRotatef(-60,0,0,1);
	glScalef(4,1,1);
	glutSolidCube(0.1);
	glPopMatrix(); 
	glPopMatrix();
	glPushMatrix(); 
	glTranslatef(_position.getX()-0.1,_position.getY()+0.1,_position.getZ());
	glutSolidSphere(0.05, 20, 20);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(_position.getX()+0.1,_position.getY()+0.1,_position.getZ());
	glutSolidSphere(0.05, 20, 20);
	glPopMatrix();
}