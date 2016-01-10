#ifndef _CUBE_H_
#define _CUBE_H_

#include "Obstacle.h"
#include "Point.h"

class Cube : public Obstacle
{
public:
	Cube();
	//Cube(Point center, Point front, Point up, Point left);
	Cube(Point center, Point normal, float angle, float length);
	virtual ~Cube();
	virtual void draw();
private:
	float length;
};
#endif //_CUBE_H_