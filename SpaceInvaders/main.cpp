#include "spaceinvaders.h"
#include "bases.h"
#include "aliens.h"
#include "manager.h"

Manager *m = new Manager();
Light *_light = new Light();

int pontos = 0;
int vidas = 0;

void myReshape(GLsizei w, GLsizei h)  
{
	m->myReshape(w,h);
}


void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	m->myDisplay();
	glFlush();

}


void specFunc(int key, int x, int y)
{
	m->specFunc(key, x, y);
}

void specUpFunc(int key, int x, int y)
{
	m->specUpFunc(key, x, y);
}


void drawObjects(int x)
{
	m->drawObjects();
	glutTimerFunc(TEMPO, drawObjects, 0);
	glutPostRedisplay();

}

void keyboard(unsigned char key, int x, int y)
{
	m->keyboard(key,x,y);

}

void keyboardUp(unsigned char key, int x, int y)
{
	m->keyboardUp(key,x,y);
}

void idleFunc()
{
	m->idle();

	if(m->restart()){
		pontos += m->getPontos();
		vidas = m->getVidas();
		delete m;
		m = new Manager();
		m->start();
		if(vidas != 0){
			m->setPontos(pontos);
			m->setVidas(vidas);
		}
	}
}

int main(int argc, char** argv) 
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(-1,-1);
	glutCreateWindow("Space Invaders");
	_light->iluminate();
	m->start();
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);
	glutSpecialFunc(specFunc);
	glutSpecialUpFunc(specUpFunc);
	glutKeyboardFunc(keyboard);
	glutKeyboardUpFunc(keyboardUp);
	glutTimerFunc(TEMPO, drawObjects, 0);
	glutIdleFunc(idleFunc);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glutMainLoop();
}