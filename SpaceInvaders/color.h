#ifndef COLOR_H
#define COLOR_H

class Color
{
	float _r;
	float _g;
	float _b;

public:
	Color(float r, float g, float b);
	~Color();

	float getR() {return _r;}
	float getG() {return _g;}
	float getB() {return _b;}

	void setRGB(float r, float g, float b);

};
#endif