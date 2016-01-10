#include "Cube.h"
#include <GL\glut.h>

Cube::Cube()
{
}

Cube::~Cube()
{
}

Cube::Cube(Point center, Point normal, float angle, float length)
	: Obstacle(center, normal, angle)
{
	this->length = length;
}

void Cube::draw()
{
	glPushMatrix();

	glTranslatef(center.x, center.y, center.z);
	glRotatef(angle, normal.x, normal.y, normal.z);
	glColor3f(1.0, 0.0, 0.0);
	glutSolidCube(length);

	glPopMatrix();
}
