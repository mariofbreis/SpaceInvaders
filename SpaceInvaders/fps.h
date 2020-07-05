#ifndef FPS_H
#define FPS_H

#include "spaceinvaders.h"

class Fps
{
	int frameCount, previousTime;
	float fps;

public:
	Fps() { frameCount=previousTime=0; fps=0; }
	float calculateFPS();
	string returnString();
};

#endif