#ifndef _OBSTACLE_H_
#define _OBSTACLE_H_

#include "Point.h"

class Obstacle
{
public:
	Obstacle();
	//Obstacle(Point center, Point front, Point up, Point left);
	//Obstacle(Point center, float xAngle, float yAngle, float zAngle);
	Obstacle(Point center, Point normal, float angle);
	virtual ~Obstacle();
	virtual void draw() = 0;
	void setCenter(Point center);

protected:
	Point normal;
	float angle;
	Point center;	//position center
	//Point front, up, left;	//direction vector
	//float xAngle, yAngle, zAngle;
};

#endif //_OBSTACLE_H_