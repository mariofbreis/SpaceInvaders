#include "Manager.h"
#include "light.h"

Manager::Manager() 
{
	for(int x=0; x<256; x++)
		teclado[x] = 0;

	ship = new Ship(173/255, 1, 47/255, 0, -8, 0);

	//Camera do topo
	_cameras.push_back(new Camera(0, 0, 2, 0, 0, 0, 0, 1, 0));
	//Camera 3rd person
	_cameras.push_back(new Camera(90.0, 1, POSICAO_MAXIMA*5, ship, 0, 0, 1, true));
	//Camera FPS
	_cameras.push_back(new Camera(90.0, 1, POSICAO_MAXIMA*5, ship, 0, 0, 1, false));
	//Vector das Cameras
	_currentCamera = _cameras[0]; /* A camara inicial e a primeira */

	explosionParticles=150;

	pontos=0;
	vidas=3;
	_gameOver=false;
	_restart=false;
}

Manager::~Manager() {}

void Manager::start(){
	planofundoTextura = texture.LoadBitmap("stars.bmp"); 
	explosionTexture = texture.LoadBitmap("particula.bmp");
	glBlendFunc(GL_SRC_ALPHA,GL_ONE);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);
}

void Manager::myReshape(GLsizei w, GLsizei h)  
{
	_currentCamera->ReshapeCamera(w,h);
}

void Manager::myDisplay()
{
	_currentCamera->cameraDisplay();
	drawObjects();
	drawMap();

	if(_currentCamera ==  _cameras[0]) 
	{
		drawPlanoFundo();
	}
	else if(_currentCamera == _cameras[1])
	{
		glPushMatrix();
		glTranslatef(0,0,-1);
		drawPlanoFundo();
		glPopMatrix();
	}	
	else if(_currentCamera == _cameras[2])
	{
		glPushMatrix();
		glRotatef(90, 1, 0, 0);
		glTranslatef(0,-12,-8);
		drawPlanoFundo();
		glPopMatrix();
	}
	if(_gameOver)
	{
		glClearColor(0,0,0,1);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		if(width <= height)
			glOrtho(-POSICAO_MAXIMA, POSICAO_MAXIMA, -POSICAO_MAXIMA/ratio, POSICAO_MAXIMA/ratio, -2.0f, 2.0f);
		else
			glOrtho(-POSICAO_MAXIMA*ratio, POSICAO_MAXIMA*ratio, -POSICAO_MAXIMA, POSICAO_MAXIMA, -2.0f, 2.0f);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		glColor3f(1.0f,1.0f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clean the screen and the depth buffer
		glLoadIdentity();
		// Imprime os FPS, tiles, camera, spotlight
		stringstream l (stringstream::in | stringstream::out);
		l.str(std::string()); 
		l <<  " High Score : " << pontos << "   Game Over, press R to restart";
		saida(-2, 0, l.str());
		glFlush();
		_restart = false;
		_gameOver = false;
		return;
	}


	glDisable(GL_LIGHTING);

	for(list<Explosion>::iterator iter = explosions.begin(); iter!=explosions.end(); ++iter)
		iter->Draw();

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(-MAX_DRAW_POSITION, MAX_DRAW_POSITION, -MAX_DRAW_POSITION, MAX_DRAW_POSITION, -2.0f, 2.0f);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glColor3f( 1., 1., 0.);
	glRasterPos2d( -9, -9.5);
	glPopMatrix();

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glColor3f(1.0f,1.0f,1.0f);

	stringstream l (stringstream::in | stringstream::out);

	l.str(std::string()); 
	l << vidas << " vidas, " << pontos << " pontos ";
	saida(MAX_GAME_POSITION/2, MAX_GAME_POSITION, l.str());

	saida(-MAX_GAME_POSITION, -MAX_GAME_POSITION+0.5, "r->restart");
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glEnable(GL_LIGHTING);
}

// Imprime caracteres no ecra
void Manager::saida(GLfloat x, GLfloat y, string text)
{
	glRasterPos2i(x, y);
	// Escreve caracter a caracter
	for(string::iterator it = text.begin(); it != text.end(); ++it)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *it);

}

//Temporizador
void Manager::teclado_verifica()
{
	if (teclado[GLUT_KEY_LEFT])
		ship->moveShip(varTempo, -1);
	else if (teclado[GLUT_KEY_RIGHT])
		ship->moveShip(varTempo, 1);
}

void Manager::drawObjects()
{
	teclado_verifica();
	ship->draw();
	aliens.drawAliens();
	bases.drawBases();

	//colocar aqui tudo o que seja para desenhar
}

void Manager::idle()
{
	static int AntigoTempo = 0;

	int NovoTempoInic = glutGet(GLUT_ELAPSED_TIME);

	varTempo = NovoTempoInic - AntigoTempo;

	AntigoTempo = NovoTempoInic;
	aliens.moveAliens(varTempo);
	aliens.fireAliens();
	ship->setTempo(varTempo);
	aliens.moveBombs(varTempo);

	list<Position> listaBalas = aliens.returnBombs();
	list<Position> listaBalasShip = ship->returnBombs();
	list<Alien*> *listaAlien = aliens.getAliens();

	if(listaAlien->size() == 0){
		listaAlien->clear();
		_restart = true;
		_gameOver = false;
		return;
	}

	else{

		for(std::list<Position>::iterator it = listaBalas.begin(); it != listaBalas.end(); it++){
			if(ship->checkHealth(*it, PLAYER_SIZE)){
				Explosion t(explosionTexture, *it, explosionParticles*10);
				explosions.push_back(t);
				aliens.removeBombs(*it);
				it = listaBalas.erase(it);
				vidas--;
				break;

			}
			if(bases.checkHealth(*it)){
				//Explosion t(explosionTexture, *it, explosionParticles*2);
				//explosions.push_back(t);
				aliens.removeBombs(*it);
				it = listaBalas.erase(it);
				break;
			}
		}
		for(std::list<Position>::iterator it = listaBalasShip.begin(); it != listaBalasShip.end(); it++){
			if(bases.checkHealth(*it)) {
				//Explosion t(explosionTexture, *it, explosionParticles*2);
				//explosions.push_back(t);
				ship->removeBomb(*it);
				it = listaBalasShip.erase(it);
				break;
			}
			if(aliens.checkHealth(*it)) {
				Explosion t(explosionTexture, *it, explosionParticles);
				explosions.push_back(t);
				ship->removeBomb(*it);
				it = listaBalasShip.erase(it);
				pontos+=10;
				break;
			}
		}
		for(std::list<Alien*>::iterator it = listaAlien->begin(); it != listaAlien->end(); it++){
			bases.checkHealth((*it)->getPosition());
			if(ship->checkHealth((*it)->getPosition(), PLAYER_SIZE) || (*it)->getPosition().getY()<=-MAX_DRAW_POSITION)
				vidas = vidas-3;
		}

		for(list<Explosion>::iterator iter = explosions.begin(); iter!=explosions.end(); ++iter){
			iter->Update(varTempo);
			//iter = explosions.erase(iter);
		}

		if(vidas <= 0)
			_gameOver = true;

	}
}


void Manager::keyboard(unsigned char key, int x, int y)
{
	if (key == '1') //Tecla 1 - camera topo
		_currentCamera = _cameras[0];

	else if (key == '2') //Tecla 2 - camera 3D
		_currentCamera = _cameras[1];

	else if (key == '3') //Tecla 3 - camera fps
		_currentCamera = _cameras[2];

	else if (52 == key) // Tecla 4 - luz geral
	{
		glEnable(GL_LIGHT0);
		glDisable(GL_LIGHT1);
	}

	else if (53 == key) // Tecla 5 - luz nave
	{
		glEnable(GL_LIGHT1);
		glDisable(GL_LIGHT0);
	}
	else if(key == 'l'){ // Tecla l - SpotLight
		if(!glIsEnabled(GL_LIGHT1)){
			glEnable(GL_LIGHT1);
			glDisable(GL_LIGHT0);
			GLfloat ambient[] = { 0.0, 0.0, 0.0, 1.0};
			glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);
		}
		else{
			glDisable(GL_LIGHT1);
			glEnable(GL_LIGHT0);
			GLfloat ambient[] = { 0.6, 0.6, 0.6, 1.0};
			glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);
		}
	}
	else if (key == 'r' || key == 'R') // Tecla r - restart
	{
		_restart=true;
		_gameOver=false;
	}
}
void Manager::keyboardUp(unsigned char key, int x, int y)
{	
	if(key == 32) // Tecla Space - faz a nave disparar
		ship->fire();
}

void Manager::drawMap(){
	/*
	glLineWidth(1);
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINES);

	glVertex3f(-MAX_WINDOW, -MAX_WINDOW, 0.0);
	glVertex3f(MAX_WINDOW, -MAX_WINDOW, 0.0);

	glVertex3f(MAX_WINDOW, -MAX_WINDOW, 0.0);
	glVertex3f(MAX_WINDOW, MAX_WINDOW, 0.0);

	glVertex3f(MAX_WINDOW, MAX_WINDOW, 0.0);
	glVertex3f(-MAX_WINDOW, MAX_WINDOW, 0.0);


	glVertex3f(-MAX_WINDOW, MAX_WINDOW, 0.0);
	glVertex3f(-MAX_WINDOW, -MAX_WINDOW, 0.0);
	glEnd();
	*/
}

void Manager::drawPlanoFundo(){

	GLfloat mat_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shine = 128;

	glMaterialfv (GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv (GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv (GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf (GL_FRONT, GL_SHININESS, mat_shine);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, planofundoTextura);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	int quality = 250;
	float tex = 5.0/quality;
	float dim = DIM/quality;
	for(int y=0; y<quality; y++)
	{
		float ytex=y*tex;
		float ydim=y*dim;
		for(int x=0; x<quality; x++)
		{
			float xtex=x*tex;
			float xdim=x*dim;
			glBegin(GL_TRIANGLE_STRIP);
			glNormal3f( 0., 0., 1.);
			glTexCoord2f(0+xtex, 0+ytex);		glVertex3f(xdim-CENTER, 0+ydim-MAX_WINDOW, 0);
			glTexCoord2f(tex+xtex, 0+ytex);		glVertex3f(dim+xdim-CENTER, 0+ydim-MAX_WINDOW, 0);
			glTexCoord2f(0+xtex, tex+ytex);		glVertex3f(0+xdim-CENTER, dim+ydim-MAX_WINDOW, 0);
			glTexCoord2f(tex+xtex, tex+ytex);	glVertex3f(dim+xdim-CENTER, dim+ydim-MAX_WINDOW, 0);
			glEnd();
		}
	}
	glDisable(GL_TEXTURE_2D);
}