#include "base.h"

Base::Base(float r, float g, float b, float x, float y, float z) : Entity(r, g, b, x, y, z), nHits(0){}

Base::~Base(){}

void Base::draw()
{
	glPushMatrix();


	if(nHits == 0){

		GLfloat mat_ambient[] = { 0.0, 0.6, 0.0, 1.0 };
		GLfloat mat_diffuse[] = { 0.0, 0.6, 0.0, 1.0 };
		GLfloat mat_specular[] = { 0.0, 0.6, 0.0, 1.0 };
		GLfloat mat_shine = 10.0;

		glMaterialfv (GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv (GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv (GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialf (GL_FRONT, GL_SHININESS, mat_shine);

	}

	if(nHits == 1){

		GLfloat mat_ambient[] = { 0.0, 0.4, 0.0, 1.0 };
		GLfloat mat_diffuse[] = { 0.0, 0.4, 0.0, 1.0 };
		GLfloat mat_specular[] = { 0.0, 0.4, 0.0, 1.0 };
		GLfloat mat_shine = 10.0;

		glMaterialfv (GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv (GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv (GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialf (GL_FRONT, GL_SHININESS, mat_shine);

	}

	if(nHits == 2){

		GLfloat mat_ambient[] = { 0.0, 0.2, 0.0, 1.0 };
		GLfloat mat_diffuse[] = { 0.0, 0.2, 0.0, 1.0 };
		GLfloat mat_specular[] = { 0.0, 0.2, 0.0, 1.0 };
		GLfloat mat_shine = 10.0;

		glMaterialfv (GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv (GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv (GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialf (GL_FRONT, GL_SHININESS, mat_shine);

	}


	if(nHits == 3){

		GLfloat mat_ambient[] = { 0.0, 0.15, 0.0, 1.0 };
		GLfloat mat_diffuse[] = { 0.0, 0.15, 0.0, 1.0 };
		GLfloat mat_specular[] = { 0.0, 0.15, 0.0, 1.0 };
		GLfloat mat_shine = 10.0;

		glMaterialfv (GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv (GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv (GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialf (GL_FRONT, GL_SHININESS, mat_shine);

	}


	glTranslatef(_position.getX(),_position.getY(),_position.getZ());
	glPushMatrix();
	glScalef(TAMANHO_BASE,TAMANHO_BASE/2,TAMANHO_BASE/2);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-TAMANHO_BASE*0.5+TAMANHO_BASE*0.125,0,-TAMANHO_BASE/2);
	glScalef(TAMANHO_BASE/4,TAMANHO_BASE/2,TAMANHO_BASE/2);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(TAMANHO_BASE*0.5-TAMANHO_BASE*0.125,0,-TAMANHO_BASE/2);
	glScalef(TAMANHO_BASE/4,TAMANHO_BASE/2,TAMANHO_BASE/2);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();

}

bool Base::numeroHits()
{
	if(nHits==3)
		return true;
	nHits++;
	return false;
}
