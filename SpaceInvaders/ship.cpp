#include "ship.h"

Ship::Ship(float r, float g, float b, float x, float y, float z) : Entity(r, g, b, x, y, z) {
}

Ship::~Ship(){}

void Ship::draw()
{
	float posX = _position.getX();
	float posY = _position.getY();
	float posZ = _position.getZ();

	glPushMatrix();

	GLfloat ambient1[] = { 0.8, 0.8, 0.8, 1.0};
	//Igual para todas as luzes
	GLfloat diffuse1[] = { 1.0, 1.0, 1.0, 1.0};
	GLfloat specular1[] = { 1.0, 1.0, 1.0, 1.0};
	//Foco1
	GLfloat position1[] = { posX , posY - 2, posZ-0.5, 1.0};
	GLfloat direction1[] = { 0.0, 1.0, 0.0 , 0.0};


	glLightfv(GL_LIGHT1, GL_AMBIENT, ambient1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, specular1);
	glLightfv(GL_LIGHT1, GL_POSITION, position1);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, direction1);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 12);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 40);


	GLfloat mat_ambient[] = { 0.25, 0.25, 0.25, 1.0 };
	GLfloat mat_diffuse[] = { 0.4, 0.4, 0.4, 1.0 };
	GLfloat mat_specular[] = { 0.774597, 0.774597, 0.774597, 1.0 };
	GLfloat mat_shine = 0.6*128;

	glMaterialfv (GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv (GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv (GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf (GL_FRONT, GL_SHININESS, mat_shine);



	glPushMatrix();
	//paralelipipedo deitado
	glBegin(GL_QUADS);//face de frente
	glNormal3f(0, 0, 1);
	glVertex3f(posX-0.7, posY+0.25, posZ+0.25);
	glVertex3f(posX+0.7, posY+0.25, posZ+0.25);
	glVertex3f(posX+0.7, posY-0.25, posZ+0.25);
	glVertex3f(posX-0.7, posY-0.25, posZ+0.25);
	glEnd();

	glBegin(GL_QUADS); //face de tras
	glNormal3f(0, 0, -1);
	glVertex3f(posX-0.7, posY+0.25, posZ-0.25);
	glVertex3f(posX+0.7, posY+0.25, posZ-0.25);
	glVertex3f(posX+0.7, posY-0.25, posZ-0.25);
	glVertex3f(posX-0.7, posY-0.25, posZ-0.25);
	glEnd();

	glBegin(GL_QUADS);//face lateral direita
	glNormal3f(1, 0, 0);
	glVertex3f(posX+0.7, posY+0.25, posZ+0.25);
	glVertex3f(posX+0.7, posY+0.25, posZ-0.25);
	glVertex3f(posX+0.7, posY-0.25, posZ-0.25);
	glVertex3f(posX+0.7, posY-0.25, posZ+0.25);
	glEnd();

	glBegin(GL_QUADS);//face lateral esquerda
	glNormal3f(-1, 0, 0);
	glVertex3f(posX-0.7, posY+0.25, posZ+0.25);
	glVertex3f(posX-0.7, posY+0.25, posZ-0.25);
	glVertex3f(posX-0.7, posY-0.25, posZ-0.25);
	glVertex3f(posX-0.7, posY-0.25, posZ+0.25);
	glEnd();

	glBegin(GL_QUADS);//face de cima
	glNormal3f(0, 1, 0);
	glVertex3f(posX-0.7, posY+0.25, posZ+0.25);
	glVertex3f(posX+0.7, posY+0.25, posZ+0.25);
	glVertex3f(posX+0.7, posY-0.25, posZ+0.25);
	glVertex3f(posX-0.7, posY-0.25, posZ+0.25);
	glEnd();

	glBegin(GL_QUADS);//face de baixo
	glNormal3f(0, -1, 0);
	glVertex3f(posX-0.7, posY-0.25, posZ+0.25);
	glVertex3f(posX+0.7, posY-0.25, posZ+0.25);
	glVertex3f(posX+0.7, posY-0.25, posZ-0.25);
	glVertex3f(posX-0.7, posY-0.25, posZ-0.25);
	glEnd();

	//paralelipipedo do centro
	glBegin(GL_QUADS);//face de frente
	glNormal3f(0, 0, 1);
	glVertex3f(posX-0.13, posY+0.25, posZ+0.25);
	glVertex3f(posX+0.13, posY+0.25, posZ+0.25);
	glVertex3f(posX+0.13, posY+0.7, posZ+0.25);
	glVertex3f(posX-0.13, posY+0.7, posZ+0.25);
	glEnd();

	glBegin(GL_QUADS);//face de tras
	glNormal3f(0, 0, -1);
	glVertex3f(posX-0.13, posY+0.25, posZ-0.25);
	glVertex3f(posX+0.13, posY+0.25, posZ-0.25);
	glVertex3f(posX+0.13, posY+0.7, posZ-0.25);
	glVertex3f(posX-0.13, posY+0.7, posZ-0.25);
	glEnd();

	glBegin(GL_QUADS);//face lateral direita
	glNormal3f(1, 0, 0);
	glVertex3f(posX+0.13, posY+0.25, posZ+0.25);
	glVertex3f(posX+0.13, posY+0.25, posZ-0.25);
	glVertex3f(posX+0.13, posY+0.7, posZ-0.25);
	glVertex3f(posX+0.13, posY+0.7, posZ+0.25);
	glEnd();

	glBegin(GL_QUADS);//face lateral esquerda
	glNormal3f(-1, 0, 0);
	glVertex3f(posX-0.13, posY+0.25, posZ+0.25);
	glVertex3f(posX-0.13, posY+0.25, posZ-0.25);
	glVertex3f(posX-0.13, posY+0.7, posZ-0.25);
	glVertex3f(posX-0.13, posY+0.7, posZ+0.25);
	glEnd();

	glBegin(GL_QUADS);//face de cima
	glNormal3f(0, 1, 0);
	glVertex3f(posX-0.13, posY+0.7, posZ-0.25);
	glVertex3f(posX+0.13, posY+0.7, posZ-0.25);
	glVertex3f(posX+0.13, posY+0.7, posZ+0.25);
	glVertex3f(posX-0.13, posY+0.7, posZ+0.25);
	glEnd();

	glBegin(GL_QUADS);//face de baixo
	glNormal3f(0, -1, 0);
	glVertex3f(posX-0.13, posY+0.25, posZ+0.25);
	glVertex3f(posX+0.13, posY+0.25, posZ+0.25);
	glVertex3f(posX+0.13, posY+0.25, posZ-0.25);
	glVertex3f(posX-0.13, posY+0.25, posZ-0.25);
	glEnd();

	//paralelepipedo esquerdo
	glBegin(GL_QUADS);//face de frente
	glNormal3f(0, 0, 1);
	glVertex3f(posX-0.83, posY-0.4, posZ+0.25);
	glVertex3f(posX-0.57, posY-0.4, posZ+0.25);
	glVertex3f(posX-0.57, posY+0.4, posZ+0.25);
	glVertex3f(posX-0.83, posY+0.4, posZ+0.25);
	glEnd();

	glBegin(GL_QUADS);//face de tras
	glNormal3f(0, 0, -1);
	glVertex3f(posX-0.83, posY-0.4, posZ-0.25);
	glVertex3f(posX-0.57, posY-0.4, posZ-0.25);
	glVertex3f(posX-0.57, posY+0.4, posZ-0.25);
	glVertex3f(posX-0.83, posY+0.4, posZ-0.25);
	glEnd();

	glBegin(GL_QUADS);//face lateral direita
	glNormal3f(1, 0, 0);
	glVertex3f(posX-0.57, posY-0.4, posZ+0.25);
	glVertex3f(posX-0.57, posY-0.4, posZ-0.25);
	glVertex3f(posX-0.57, posY+0.4, posZ-0.25);
	glVertex3f(posX-0.57, posY+0.4, posZ+0.25);
	glEnd();

	glBegin(GL_QUADS);//face lateral esquerda
	glNormal3f(-1, 0, 0);
	glVertex3f(posX-0.83, posY-0.4, posZ+0.25);
	glVertex3f(posX-0.83, posY-0.4, posZ-0.25);
	glVertex3f(posX-0.83, posY+0.4, posZ-0.25);
	glVertex3f(posX-0.83, posY+0.4, posZ+0.25);
	glEnd();

	glBegin(GL_QUADS);//face de cima
	glNormal3f(0, 1, 0);
	glVertex3f(posX-0.83, posY+0.4, posZ-0.25);
	glVertex3f(posX-0.57, posY+0.4, posZ-0.25);
	glVertex3f(posX-0.57, posY+0.4, posZ+0.25);
	glVertex3f(posX-0.83, posY+0.4, posZ+0.25);
	glEnd();
	glBegin(GL_QUADS);//face de baixo
	glNormal3f(0, -1, 0);
	glVertex3f(posX-0.83, posY+0.4, posZ-0.25);
	glVertex3f(posX-0.57, posY+0.4, posZ-0.25);
	glVertex3f(posX-0.57, posY+0.4, posZ+0.25);
	glVertex3f(posX-0.83, posY+0.4, posZ+0.25);
	glEnd();

	//paralelepipedo direito
	glBegin(GL_QUADS);//face de frente
	glNormal3f(0, 0, 1);
	glVertex3f(posX+0.83, posY-0.4, posZ+0.25);
	glVertex3f(posX+0.57, posY-0.4, posZ+0.25);
	glVertex3f(posX+0.57, posY+0.4, posZ+0.25);
	glVertex3f(posX+0.83, posY+0.4, posZ+0.25);
	glEnd();

	glBegin(GL_QUADS);//face de tras
	glNormal3f(0, 0, -1);
	glVertex3f(posX+0.83, posY-0.4, posZ-0.25);
	glVertex3f(posX+0.57, posY-0.4, posZ-0.25);
	glVertex3f(posX+0.57, posY+0.4, posZ-0.25);
	glVertex3f(posX+0.83, posY+0.4, posZ-0.25);
	glEnd();

	glBegin(GL_QUADS);//face lateral direita
	glNormal3f(1, 0, 0);
	glVertex3f(posX+0.57, posY-0.4, posZ+0.25);
	glVertex3f(posX+0.57, posY-0.4, posZ-0.25);
	glVertex3f(posX+0.57, posY+0.4, posZ-0.25);
	glVertex3f(posX+0.57, posY+0.4, posZ+0.25);
	glEnd();

	glBegin(GL_QUADS);//face lateral esquerda
	glNormal3f(-1, 0, 0);
	glVertex3f(posX+0.83, posY-0.4, posZ+0.25);
	glVertex3f(posX+0.83, posY-0.4, posZ-0.25);
	glVertex3f(posX+0.83, posY+0.4, posZ-0.25);
	glVertex3f(posX+0.83, posY+0.4, posZ+0.25);
	glEnd();

	glBegin(GL_QUADS);//face de cima
	glNormal3f(0, 1, 0);
	glVertex3f(posX+0.83, posY+0.4, posZ-0.25);
	glVertex3f(posX+0.57, posY+0.4, posZ-0.25);
	glVertex3f(posX+0.57, posY+0.4, posZ+0.25);
	glVertex3f(posX+0.83, posY+0.4, posZ+0.25);
	glEnd();

	glBegin(GL_QUADS);//face de baixo
	glNormal3f(0, -1, 0);
	glVertex3f(posX+0.83, posY+0.4, posZ-0.25);
	glVertex3f(posX+0.57, posY+0.4, posZ-0.25);
	glVertex3f(posX+0.57, posY+0.4, posZ+0.25);
	glVertex3f(posX+0.83, posY+0.4, posZ+0.25);
	glEnd();

	glBegin(GL_QUADS);//face de baixo
	glNormal3f(0, -1, 0);
	glVertex3f(posX+0.83, posY+0.4, posZ-0.25);
	glVertex3f(posX+0.57, posY+0.4, posZ-0.25);
	glVertex3f(posX+0.57, posY+0.4, posZ+0.25);
	glVertex3f(posX+0.83, posY+0.4, posZ+0.25);
	glEnd();

	//piramide
	glBegin(GL_TRIANGLES);//face de cima
	glNormal3f(0, 0, 1);
	glVertex3f(posX-0.13, posY+0.7, posZ+0.25);
	glVertex3f(posX+0.13, posY+0.7, posZ+0.25);
	glVertex3f(posX, posY+1, posZ+0.25);
	glEnd();

	glBegin(GL_TRIANGLES);//face de baixo
	glNormal3f(0, 0, -1);
	glVertex3f(posX-0.13, posY+0.7, posZ-0.25);
	glVertex3f(posX+0.13, posY+0.7, posZ-0.25);
	glVertex3f(posX, posY+1, posZ-0.25);
	glEnd();

	glBegin(GL_QUADS);//face do lado direito
	glNormal3f(0.15, 0.065, 0);
	glVertex3f(posX+0.13, posY+0.7, posZ+0.25);
	glVertex3f(posX+0.13, posY+0.7, posZ-0.25);
	glVertex3f(posX, posY+1, posZ-0.25);
	glVertex3f(posX, posY+1, posZ+0.25);
	glEnd();

	glBegin(GL_QUADS);//face do lado esquerdo
	glNormal3f(-0.15, 0.065, 0);
	glVertex3f(posX-0.13, posY+0.7, posZ+0.25);
	glVertex3f(posX-0.13, posY+0.7, posZ-0.25);
	glVertex3f(posX, posY+1, posZ-0.25);
	glVertex3f(posX, posY+1, posZ+0.25);
	glEnd();

	glBegin(GL_QUADS);//base
	glNormal3f(0, -1, 0);
	glVertex3f(posX+0.13, posY+0.7, posZ+0.25);
	glVertex3f(posX+0.13, posY+0.7, posZ-0.25);
	glVertex3f(posX-0.13, posY+0.7, posZ-0.25);
	glVertex3f(posX-0.13, posY+0.7, posZ+0.25);
	glEnd();

	glPopMatrix();
	glPopMatrix();
	bombs.moveBombs(tempo, 1);
	bombs.drawBombsShip();
}

void Ship::moveShip(int varTempo,int direction)
{

	float dist = direction*SHIP_SPEED*varTempo;
	float newPos = _position.getX() + dist;

	//Condicao para verificar se a nave passou o limite do jogo
	if(newPos < MAX_GAME_POSITION && newPos > -MAX_GAME_POSITION)
		_position.setX(newPos);
}

//Dispara a partir da posicao da nave
void Ship::fire(){

	bombs.bomb(_position);
}


list<Position> Ship::returnBombs(){
	return bombs.returnBombs();
}

void Ship::removeBomb(Position p){
	bombs.removeBomb(p);
}

