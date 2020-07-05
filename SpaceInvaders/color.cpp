#include "color.h"

Color::Color(float r, float g, float b) : _r(r), _g(g), _b(b) {}

Color::~Color() {}

void Color::setRGB(float r, float g, float b) 
{
	_r=r;
	_g=g;
	_b=b;
}