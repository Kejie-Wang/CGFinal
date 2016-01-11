#include "Obstacle.h"

Obstacle::Obstacle()
{
}

Obstacle::~Obstacle()
{
}

/*
Obstacle::Obstacle(Point center, Point front, Point up, Point left)
{
	this->center = center;
	xAngle = intersecAngle(Point(0, 0, 1), front);
	yAngle = intersecAngle(Point(1, 0, 0), left);
	zAngle = intersecAngle(Point(0, 1, 0), up);
}

Obstacle::Obstacle(Point center, float xAngle, float yAngle, float zAngle)
{
	this->center = center;
	this->xAngle = xAngle;
	this->yAngle = yAngle;
	this->zAngle = zAngle;
}
*/

Obstacle::Obstacle(Point center, Point normal, float angle)
{
	this->center = center;
	this->normal = normal;
	this->angle = angle;
}

void Obstacle::setCenter(Point center)
{
	this->center = center;
}

void Obstacle::setColor(float color[])
{
	this->color[0] = color[0];
	this->color[1] = color[1];
	this->color[2] = color[2];
}