#ifndef POSITION_H
#define POSITION_H

class Position
{
	float _x;
	float _y;
	float _z;

public:
	Position();
	Position(float x, float y, float z);
	~Position();

	float getX() {return _x;}
	float getY() {return _y;}
	float getZ() {return _z;}
	void setX(float x) {_x=x;}
	void setY(float y) {_y=y;}
	void setZ(float z) {_z=z;}
	void setXYZ(float x, float y, float z);
};
#endif