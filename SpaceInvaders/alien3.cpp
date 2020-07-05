#include "Alien3.h"

Alien3::Alien3(float r, float g, float b, float x, float y, float z) : Alien(r, g, b, x, y, z) {}

Alien3::~Alien3(){}


void Alien3::draw()
{

	glPushMatrix(); 

	GLfloat mat_ambient[] = { 0.0, 0.0, 0.8, 1.0 };
	GLfloat mat_diffuse[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat mat_specular[] = { 0.0, 0.0, 0.1, 1.0 };
	GLfloat mat_shine = 0.25*128;

	glMaterialfv (GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv (GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv (GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf (GL_FRONT, GL_SHININESS, mat_shine);

	glTranslatef(_position.getX(),_position.getY(),_position.getZ());
	glRotatef(90, 1, 0, 0);
	glScalef(1,0.6,1);
	glutSolidSphere(0.3, 20, 20);
	glPushMatrix(); 
	glTranslatef(0.2,0,0);
	glRotatef(-80,0,0,1);
	glScalef(5.5,0.8,1);
	glutSolidSphere(0.1,10,10);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-0.2,0,0);
	glRotatef(80,0,0,1);
	glScalef(5.5,0.8,1);
	glutSolidSphere(0.1,10,10);
	glPopMatrix(); 
	glPopMatrix();
	glPushMatrix(); 
	glColor3f(1.0,1.0,1.0);
	glTranslatef(_position.getX()-0.1,_position.getY()+0.05,_position.getZ());
	glutSolidCube(0.1);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(_position.getX()+0.1,_position.getY()+0.05,_position.getZ());
	glutSolidCube(0.1);
	glPopMatrix();
}