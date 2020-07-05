#include "Aliens.h"

Aliens::Aliens()
{
	speed = 0.002; //velocidade do movimento dos aliens
	int i;
	float x;
	float y1, y2, y3;
	float z=0;
	moves=1;
	direction=1;
	srand(1); //inicialização da funçao rand
	tempo= time(NULL); //inicializaçao de tempo com o tempo do sistema operativo

	for(i=0; i<9; i++)
	{
		x=-8+2*i;
		y1=8;
		y2=6;
		y3=3.7;
		Alien1 a11(1, 0.2, 0.2, x, y1, z);
		Alien1 a12(1, 0.2, 0.2, x, y1-1, z);
		Alien2 a21(0, 1, 0, x, y2, z);
		Alien2 a22(0, 1, 0, x, y2-1, z);
		Alien3 a31(0, 0.3, 1, x, y3, z);
		Alien3 a32(0, 0.3, 1, x, y3-1, z);
		alien1Lista1.push_back(a11);
		alien1Lista2.push_back(a12);
		alien2Lista1.push_back(a21);
		alien2Lista2.push_back(a22);
		alien3Lista1.push_back(a31);
		alien3Lista2.push_back(a32);
	}
}

Aliens::~Aliens(){}

void Aliens::drawAliens()
{

	for(std::vector<Alien1>::iterator it=alien1Lista1.begin(); it!=alien1Lista1.end(); it++) 
	{
		it->draw();
	}

	for(std::vector<Alien1>::iterator it = alien1Lista2.begin();it !=alien1Lista2.end(); it++) 
	{
		it->draw();
	}

	for(std::vector<Alien2>::iterator it = alien2Lista1.begin();it !=alien2Lista1.end(); it++) 
	{
		it->draw();
	}

	for(std::vector<Alien2>::iterator it = alien2Lista2.begin();it !=alien2Lista2.end(); it++) 
	{
		it->draw();
	}

	for(std::vector<Alien3>::iterator it = alien3Lista1.begin();it !=alien3Lista1.end(); it++) 
	{
		it->draw();
	}

	for(std::vector<Alien3>::iterator it = alien3Lista2.begin();it !=alien3Lista2.end(); it++) 
	{
		it->draw();
	}
	bombsAliens.drawBombs();
}

void Aliens::removeBombs(Position p)
{
	bombsAliens.removeBomb(p);
}

void Aliens::addAliens()
{
	//implementar	
}

void Aliens::removeAliens()
{
	//implementar
}
void Aliens::moveAliens(int varTempo){
	float dist;
	float y = 0.0;
	std::vector<Position> posAliens; //vector que contem as posiçoes do aliens da ponta de cada lista
	Position leftAlienPos;
	Position rightAlienPos;
	float disMaisLeft;
	float disMaisRight;

	if(alien1Lista1.size() > 0)
	{
		posAliens.push_back(alien1Lista1.front().getPosition());
		posAliens.push_back(alien1Lista1.back().getPosition());
	}

	if(alien1Lista2.size() > 0)
	{
		posAliens.push_back(alien1Lista2.front().getPosition());
		posAliens.push_back(alien1Lista2.back().getPosition());
	}

	if(alien2Lista1.size() > 0)
	{
		posAliens.push_back(alien2Lista1.front().getPosition());
		posAliens.push_back(alien2Lista1.back().getPosition());
	}

	if(alien2Lista2.size() > 0)
	{
		posAliens.push_back(alien2Lista2.front().getPosition());
		posAliens.push_back(alien2Lista2.back().getPosition());
	}

	if(alien3Lista1.size() > 0)
	{
		posAliens.push_back(alien3Lista1.front().getPosition());
		posAliens.push_back(alien3Lista1.back().getPosition());
	}

	if(alien3Lista2.size() > 0)
	{
		posAliens.push_back(alien3Lista2.front().getPosition());
		posAliens.push_back(alien3Lista2.back().getPosition());
	}

	if(posAliens.size()>0)
	{
		leftAlienPos=posAliens[0];
		rightAlienPos=posAliens[1];


		//ciclo que percorre o vector e encontra a posiçao mais a esquerda e a posiçao mais a direita
		for(std::vector<Position>::iterator it=posAliens.begin(); it != posAliens.end(); it++)
		{
			if( it->getX() < leftAlienPos.getX())
				leftAlienPos=*it;
			else if(it->getX() > rightAlienPos.getX())
				rightAlienPos=*it;
		}

		//a partir daqui nao houve mais alterações
		dist = direction*speed*varTempo;

		disMaisLeft = leftAlienPos.getX() + dist;
		disMaisRight = rightAlienPos.getX() + dist;

		if(disMaisLeft < -MAX_SP_POSITION)
		{
			// Aliens movem-se para a linha de baixo
			direction=-1*direction; //inverte o sentido
			if(moves == 1){
				y=-0.3; //Speed Vertical
				moves=1;
			}
			else{
				moves++;
			}
			dist = -MAX_SP_POSITION - leftAlienPos.getX();
		}
		else if(disMaisRight > MAX_SP_POSITION)
		{
			// Aliens movem-se para a linha de baixo
			direction=-1*direction;//inverte o sentido
			if(moves == 1){
				y=-0.3; //Speed Vertical
				moves=1;
			}
			else {
				moves++;
			}
			dist = MAX_SP_POSITION - rightAlienPos.getX();
		}

		for(std::vector<Alien1>::iterator it=alien1Lista1.begin(); it!=alien1Lista1.end(); it++) 
		{
			it->move(dist, y);
		}

		for(std::vector<Alien1>::iterator it = alien1Lista2.begin();it !=alien1Lista2.end(); it++) 
		{
			it->move(dist, y);
		}

		for(std::vector<Alien2>::iterator it = alien2Lista1.begin();it !=alien2Lista1.end(); it++) 
		{
			it->move(dist, y);
		}

		for(std::vector<Alien2>::iterator it = alien2Lista2.begin();it !=alien2Lista2.end(); it++) 
		{
			it->move(dist, y);
		}

		for(std::vector<Alien3>::iterator it = alien3Lista1.begin();it !=alien3Lista1.end(); it++)
		{
			it->move(dist, y);
		}

		for(std::vector<Alien3>::iterator it = alien3Lista2.begin();it !=alien3Lista2.end(); it++) 
		{
			it->move(dist, y);
		}
		bombsAliens.moveBombs(varTempo, -1);
	}
}


void Aliens::fireAliens()
{
	int randomNum=rand() % 6;
	bool dispara=true;
	float x;
	static long last = 0;
	int current = glutGet(GLUT_ELAPSED_TIME);
	if(current-last > 300)//define o intervalo de tempo de cada disparo dos 
	{
		last=current;
		switch(randomNum)
		{
		case 5:
			if(alien3Lista2.size()>0)
			{
				randomNum=rand() % alien3Lista2.size();
				bombsAliens.bomb(alien3Lista2[randomNum].getPosition());
				//break;
			}
			//std::cout << randomNum << "   5" << std::endl;
			break;
		case 4:
			if(alien3Lista1.size()>0)
			{

				randomNum=rand() % alien3Lista1.size();
				x=alien3Lista1[randomNum].getPosition().getX();
				for(std::vector<Alien3>::iterator it = alien3Lista2.begin();it !=alien3Lista2.end(); it++)
				{
					if( it->getPosition().getX() == x)
					{
						dispara=false;
						break;
					}
				}

				if (dispara)
				{
					bombsAliens.bomb(alien3Lista1[randomNum].getPosition());
					break;
				}
				dispara=true;
			}
			//std::cout << randomNum << "   4" << std::endl;
			break;
		case 3:
			if(alien2Lista2.size()>0)
			{
				randomNum=rand() % alien2Lista2.size();

				x=alien2Lista2[randomNum].getPosition().getX();

				for(std::vector<Alien3>::iterator it = alien3Lista1.begin();it !=alien3Lista1.end(); it++)
				{
					if( it->getPosition().getX() == x)
					{
						dispara=false;
						break;
					}
				}

				for(std::vector<Alien3>::iterator it = alien3Lista2.begin();it !=alien3Lista2.end(); it++)
				{
					if( it->getPosition().getX() == x || !dispara)
					{
						dispara=false;
						break;
					}
				}

				if (dispara)
				{
					bombsAliens.bomb(alien2Lista2[randomNum].getPosition());					
					break;
				}
				dispara=true;
			}
			//std::cout << randomNum << "   2" << std::endl;
			break;
		case 2:
			if(alien2Lista1.size()>0)
			{
				randomNum=rand() % alien2Lista1.size();

				x=alien2Lista1[randomNum].getPosition().getX();

				for(std::vector<Alien2>::iterator it = alien2Lista2.begin();it !=alien2Lista2.end(); it++)
				{
					if( it->getPosition().getX() == x)
					{
						dispara=false;
						break;
					}
				}

				for(std::vector<Alien3>::iterator it = alien3Lista1.begin();it !=alien3Lista1.end(); it++)
				{
					if( it->getPosition().getX() == x || !dispara)
					{
						dispara=false;
						break;
					}
				}

				for(std::vector<Alien3>::iterator it = alien3Lista2.begin();it !=alien3Lista2.end(); it++)
				{
					if( it->getPosition().getX() == x || !dispara)
					{
						dispara=false;
						break;
					}
				}

				if (dispara)
				{
					bombsAliens.bomb(alien2Lista1[randomNum].getPosition());				
					break;
				}
				dispara=true;
			}
			//std::cout << randomNum << "   3" << std::endl;
			break;
		case 1:
			if(alien1Lista2.size()>0)
			{
				randomNum=rand() % alien1Lista2.size();

				x=alien1Lista2[randomNum].getPosition().getX();

				for(std::vector<Alien2>::iterator it = alien2Lista1.begin();it !=alien2Lista1.end(); it++)
				{
					if( it->getPosition().getX() == x)
					{
						dispara=false;
						break;
					}
				}

				for(std::vector<Alien2>::iterator it = alien2Lista2.begin();it !=alien2Lista2.end(); it++)
				{
					if( it->getPosition().getX() == x || !dispara)
					{
						dispara=false;
						break;
					}
				}

				for(std::vector<Alien3>::iterator it = alien3Lista1.begin();it !=alien3Lista1.end(); it++)
				{
					if( it->getPosition().getX() == x || !dispara)
					{
						dispara=false;
						break;
					}
				}

				for(std::vector<Alien3>::iterator it = alien3Lista2.begin();it !=alien3Lista2.end(); it++)
				{
					if( it->getPosition().getX() == x || !dispara)
					{
						dispara=false;
						break;
					}
				}

				if (dispara)
				{
					bombsAliens.bomb(alien1Lista2[randomNum].getPosition());				
					break;
				}
				dispara=true;
			}
			//std::cout << randomNum << "   4" << std::endl;
			break;
		case 0:
			if(alien1Lista1.size()>0)
			{
				randomNum=rand() % alien1Lista1.size();

				x=alien1Lista1[randomNum].getPosition().getX();

				for(std::vector<Alien1>::iterator it = alien1Lista2.begin();it !=alien1Lista2.end(); it++)
				{
					if( it->getPosition().getX() == x)
					{
						dispara=false;
						break;
					}
				}

				for(std::vector<Alien2>::iterator it = alien2Lista1.begin();it !=alien2Lista1.end(); it++)
				{
					if( it->getPosition().getX() == x || !dispara)
					{
						dispara=false;
						break;
					}
				}

				for(std::vector<Alien2>::iterator it = alien2Lista2.begin();it !=alien2Lista2.end(); it++)
				{
					if( it->getPosition().getX() == x || !dispara)
					{
						dispara=false;
						break;
					}
				}

				for(std::vector<Alien3>::iterator it = alien3Lista1.begin();it !=alien3Lista1.end(); it++)
				{
					if( it->getPosition().getX() == x || !dispara)
					{
						dispara=false;
						break;
					}
				}

				for(std::vector<Alien3>::iterator it = alien3Lista2.begin();it !=alien3Lista2.end(); it++)
				{
					if( it->getPosition().getX() == x || !dispara)
					{
						dispara=false;
						break;
					}
				}

				if (dispara)
				{

					bombsAliens.bomb(alien1Lista1[randomNum].getPosition());
					break;
				}
				dispara=true;
			}
			//std::cout << randomNum << "   5" << std::endl;
			break;
		}

	}
}

void Aliens::moveBombs(int tempo){

	bombsAliens.moveBombs(tempo, -1);
}

list<Position> Aliens::returnBombs(){
	return bombsAliens.returnBombs();
}


list<Alien*> * Aliens::getAliens(){

	list<Alien*> * listaAlien= new list<Alien*>();

	for(std::vector<Alien1>::iterator it=alien1Lista1.begin(); it!=alien1Lista1.end(); it++) 
	{		
		listaAlien->push_back(&(*it));
	}

	for(std::vector<Alien1>::iterator it = alien1Lista1.begin();it !=alien1Lista1.end(); it++) 
	{
		listaAlien->push_back(&(*it));
	}

	for(std::vector<Alien1>::iterator it = alien1Lista2.begin();it !=alien1Lista2.end(); it++) 
	{
		listaAlien->push_back(&(*it));
	}

	for(std::vector<Alien2>::iterator it = alien2Lista1.begin();it !=alien2Lista1.end(); it++) 
	{
		listaAlien->push_back(&(*it));
	}

	for(std::vector<Alien2>::iterator it = alien2Lista2.begin();it !=alien2Lista2.end(); it++) 
	{
		listaAlien->push_back(&(*it));
	}

	for(std::vector<Alien3>::iterator it = alien3Lista1.begin();it !=alien3Lista1.end(); it++) 
	{
		listaAlien->push_back(&(*it));
	}

	for(std::vector<Alien3>::iterator it = alien3Lista2.begin();it !=alien3Lista2.end(); it++) 
	{
		listaAlien->push_back(&(*it));
	}
	return listaAlien;
}

bool Aliens::checkHealth(Position p)
{
	bool hit = false;
	for(std::vector<Alien3>::iterator it = alien3Lista2.begin();it !=alien3Lista2.end(); it++) {
		if(it->checkHealth(p, ALIEN_SIZE)){
			alien3Lista2.erase(it);
			hit = true;
			break;
		}
	}

	for(std::vector<Alien3>::iterator it = alien3Lista1.begin();it !=alien3Lista1.end(); it++) {
		if(it->checkHealth(p, ALIEN_SIZE)){
			alien3Lista1.erase(it);
			hit = true;
			break;
		}
	}

	for(std::vector<Alien2>::iterator it = alien2Lista2.begin();it !=alien2Lista2.end(); it++) {
		if(it->checkHealth(p, ALIEN_SIZE)){
			alien2Lista2.erase(it);
			hit = true;
			break;
		}
	}

	for(std::vector<Alien2>::iterator it = alien2Lista1.begin();it !=alien2Lista1.end(); it++) {
		if(it->checkHealth(p, ALIEN_SIZE)){
			alien2Lista1.erase(it);
			hit = true;
			break;
		}
	}

	for(std::vector<Alien1>::iterator it = alien1Lista2.begin();it !=alien1Lista2.end(); it++) {
		if(it->checkHealth(p, ALIEN_SIZE)){
			alien1Lista2.erase(it);
			hit = true;
			break;
		}
	}

	for(std::vector<Alien1>::iterator it = alien1Lista1.begin();it !=alien1Lista1.end(); it++) {
		if(it->checkHealth(p, ALIEN_SIZE)){
			alien1Lista1.erase(it);
			hit = true;
			break;
		}
	}          
	return hit;
}