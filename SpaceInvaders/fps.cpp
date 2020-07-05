#include "fps.h"

float Fps::calculateFPS()
{
	frameCount++;
	int currentTime = glutGet(GLUT_ELAPSED_TIME);
	int timeInterval = currentTime - previousTime;

	if(timeInterval > 1000)
	{
		fps = frameCount / (timeInterval / 1000.0f);
		previousTime = currentTime;
		frameCount = 0;
	}
	return fps;
}

string Fps::returnString()
{
	stringstream ss (stringstream::in | stringstream::out);
	ss << calculateFPS();
	string text = ss.str() + " fps";

	return text;
}