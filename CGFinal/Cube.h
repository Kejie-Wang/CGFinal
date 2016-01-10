#ifndef _CUBE_H_
#define _CUBE_H_

#include "Obstacle.h"

class Cube : public Obstacle
{
public:
	Cube();
	Cube(int face);
	virtual ~Cube();
	virtual void draw();
private:
	float length;
};

#endif //_CUBE_H_