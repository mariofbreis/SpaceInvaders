#ifndef MANAGER_H
#define MANAGER_H

#include <vector>

#include "spaceinvaders.h"
#include "bases.h"
#include "aliens.h"
#include "ship.h"
#include "camera.h"
#include "bombs.h"
#include "light.h"
#include "texture.h"
#include "explosion.h"
#include "particle.h"

class Manager
{
	Ship *ship;
	Bases bases;
	Aliens aliens;
	Light *_light;
	int teclado[256];
	//Diferença de tempo entre as callbacks
	int varTempo;
	Camera* _currentCamera; /* camara activa */
	vector<Camera*> _cameras; /* vector que guarda as tres camaras, as camaras tem numeros, como os vectores tem indices */
	GLsizei width, height;
	Bombs *bombs;
	int planofundoTextura;
	Texture texture;
	int pontos;
	int vidas;
	float ratio;
	list<Explosion> explosions;
	int explosionTexture;
	int explosionParticles;
	int largura;

public:

	bool _gameOver;
	bool _restart;

	Manager();
	~Manager();

	void myReshape(GLsizei w, GLsizei h);
	void myDisplay();
	void start();
	void specFunc(int key, int x, int y) {teclado[key] = true;}
	void specUpFunc(int key, int x, int y) {teclado[key] = false;}
	void teclado_verifica();
	void keyboard(unsigned char key, int x, int y);
	void keyboardUp(unsigned char key, int x, int y);
	void drawObjects();
	void idle();
	void drawMap();
	void drawPlanoFundo();
	void saida(GLfloat x, GLfloat y, string text);
	bool gameover() {return _gameOver;}
	bool restart() {return _restart;}
	int getPontos(){return pontos;}
	void setPontos(int p){pontos = p;}
	int getVidas(){return vidas;}
	void setVidas(int v){vidas = v;}
};
//void selectCamera(int key, int x , int y);


#endif