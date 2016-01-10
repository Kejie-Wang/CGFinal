#ifndef _OBSTACLE_H_
#define _OBSTACLE_H_

class Obstacle
{
public:
	Obstacle();
	virtual ~Obstacle();
	virtual void draw() = 0;
};

#endif //_OBSTACLE_H_