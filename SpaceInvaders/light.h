#ifndef LIGHT_H
#define LIGHT_H


class Light
{

	/*GLfloat ambient[4] = { 0.0, 0.0, 0.0, 1.0};
	//Igual para todas as luzes
	GLfloat diffuse[4] = { 1.0, 1.0, 1.0, 1.0};
	GLfloat specular[4] = { 0.5, 0.5, 0.5, 1.0};
	//Foco1
	GLfloat position1[4] = { 0.0 , 0.0 , -5.0 , 0.0};*/

public:
	//Light(float amb[], float diff[], float spec[], float pos[]);
	Light();
	~Light();

	void iluminate();
};

#endif