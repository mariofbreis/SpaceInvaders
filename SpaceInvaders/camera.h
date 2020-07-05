#ifndef CAMERA_H
#define CAMERA_H

#include "spaceinvaders.h"
#include "ship.h"
//class Ship;

class Camera
{
	static const int size = 10;
	double _w;
	double _h;
	double  _eyeX;  
	double  _eyeY;
	double  _eyeZ; 
	double  _centerX;
	double  _centerY;
	double  _centerZ;
	double  _upX;
	double  _upY;
	double  _upZ;
	double _fov;
	double _zNear;
	double _zFar;
	bool isOrtho;
	bool isC2;
	Ship *_ship; // para fazer a visao FPS, precisamos da posiçao da ship

public:
	//Camera Ortho
	Camera(double eyex, double eyey, double eyez, double centerx, double centery, double centerz, double upx, double upy, double upz);
	//Camera Prespective
	Camera(double fov, double zNear, double zFar, Ship *ship, double upx, double upy, double upz, bool c2);
	~Camera();
	void ReshapeCamera(double width, double height);
	void cameraDisplay();
};

#endif