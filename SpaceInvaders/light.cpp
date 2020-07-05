#include "light.h"
#include "spaceinvaders.h"

//Light::Light(float ambr, float ambr, float ambg, float diff[], float spec[], float pos[]) : ambient(amb), diffuse(diff), specular(spec), position(pos){


//}
Light::Light(){}

Light::~Light(){}

void Light::iluminate(){

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT_MODEL_AMBIENT);
	glEnable(GL_LIGHT0);

	GLfloat ambient[] = { 0.6, 0.6, 0.6	, 1.0};
	//Igual para todas as luzes
	GLfloat diffuse[] = { 0.1, 0.5, 0.5, 0.5};
	GLfloat specular[] = { 1.0, 1, 0.5, 1.0};
	//Foco1
	GLfloat position1[] = { 1.0 , 1.0 , 0.0 , 0.0};

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);

	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT0, GL_POSITION, position1);

}

