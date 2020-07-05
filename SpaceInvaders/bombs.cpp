#include "bombs.h"

Bombs::Bombs() {
	velocidade = 1;
}

void Bombs::bomb(Position p)
{
	bombs.push_back(p);
}

//Apaga os tiros
void Bombs::clear()
{
	bombs.clear();
}


//Movimento das balas
void Bombs::moveBombs(int varTempo, int direction)
{
	list<Position>::iterator iter;

	iter=bombs.begin();
	while(iter!=bombs.end())
	{
		_x = iter->getX();
		_y = iter->getY();

		if(iter->getY() >= MAX_GAME_POSITION || iter->getY() < -MAX_GAME_POSITION)
		{
			iter = bombs.erase(iter);
		}
		else
		{
			iter->setY(iter->getY() + direction * (varTempo*SHOT_SPEED));
			iter++;
		}
	}
}

// Desenha os tiros dos aliens 
void Bombs::drawBombs()
{
	list<Position>::iterator iter;
	for(iter=bombs.begin(); iter!=bombs.end(); ++iter)
	{
		glPushMatrix();

		GLfloat mat_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
		GLfloat mat_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
		GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
		GLfloat mat_shine = 10.0;

		glMaterialfv (GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv (GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv (GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialf (GL_FRONT, GL_SHININESS, mat_shine);

		glTranslatef (iter->getX(), iter->getY(), iter->getZ());
		glScalef(2, 3, 2);
		//glutSolidCube(1);
		glutSolidSphere(TAMANHO_BALA,5,5);

		glPopMatrix();
	}
}

// Desenha os tiros da nave
void Bombs::drawBombsShip()
{

	list<Position>::iterator iter;
	for(iter=bombs.begin(); iter!=bombs.end(); ++iter)
	{
		glPushMatrix();

		GLfloat mat_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
		GLfloat mat_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
		GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
		GLfloat mat_shine = 10.0;

		glMaterialfv (GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv (GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv (GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialf (GL_FRONT, GL_SHININESS, mat_shine);

		glTranslatef (iter->getX(), iter->getY() + 0.8, iter->getZ());
		glScalef(2, 3, 2);
		//glutSolidCube(1);
		glutSolidSphere(TAMANHO_BALA,5,5);

		glPopMatrix();
	}
}

list<Position> Bombs::returnBombs(){
	return bombs;
}

void Bombs::removeBomb(Position p){
	for(list<Position>::iterator it=bombs.begin(); it!=bombs.end(); ++it){
		if((*it).getX() == p.getX() && (*it).getY() == p.getY() && (*it).getZ() == p.getZ()){
			it = bombs.erase(it);
			return;
		}
	}
}