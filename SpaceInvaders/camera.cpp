#include "camera.h"

Camera::Camera(double eyex, double eyey, double eyez, double centerx, double centery, double centerz, double upx, double upy, double upz){//topo
	_eyeX = eyex;
	_eyeY = eyey;
	_eyeZ = eyez;
	_centerX = centerx;
	_centerY = centery;
	_centerZ = centerz;
	_upX = upx;
	_upY = upy;
	_upZ = upz;
	isOrtho = true;
}

Camera::Camera(double fov, double zNear, double zFar, Ship *ship, double upx, double upy, double upz, bool c2){//fps
	_fov = fov;
	_zNear = zNear;
	_zFar = zFar;
	_ship = ship;
	_upX = upx;
	_upY = upy;
	_upZ = upz;
	isOrtho = false;
	isC2 = c2;
}

Camera::~Camera(){}

void Camera::ReshapeCamera(double width, double height){
	_w = width;
	_h = height;
}

void Camera::cameraDisplay(){
	glViewport(0, 0, _w, _h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	float ratio = _w*1.0/_h;
	if (isOrtho == true){
		if(_w <= _h)
			glOrtho(-MAX_WINDOW, MAX_WINDOW, -MAX_WINDOW/ratio, MAX_WINDOW/ratio, -MAX_WINDOW*5.0f, MAX_WINDOW*5.0f);
		else
			glOrtho(-MAX_WINDOW*ratio, MAX_WINDOW*ratio, -MAX_WINDOW, MAX_WINDOW, -MAX_WINDOW*5.0f, MAX_WINDOW*5.0f);
	}
	else{
		if(_h == 0) _h = 1;
		double aspectRatio = (double) _w / (double) _h;
		gluPerspective(_fov, aspectRatio, _zNear, _zFar);
	}
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	if(isC2 == false){
		// camera FPS -> necessario ter a posicao da nave
		_eyeX = _ship->getPosition().getX();
		_eyeY = _ship->getPosition().getY();
		_eyeZ = _ship->getPosition().getZ();
		_centerX = _ship->getPosition().getX();
		_centerY = -_ship->getPosition().getY();
		_centerZ = 0;
	}
	if(isC2 == true){
		_eyeX = _ship->getPosition().getX();
		_eyeY = _ship->getPosition().getY() - 1;
		_eyeZ = 6;
		_centerX = _ship->getPosition().getX();
		_centerY = -_ship->getPosition().getY()- 10;
		_centerZ = -3;
	}

	gluLookAt(_eyeX, _eyeY, _eyeZ, _centerX, _centerY, _centerZ, _upX, _upY, _upZ);
}