/*TunnelSlice.cpp
*@brief An implementation of the class TunnelSlice
*@Author: wang_kejie@foxmail.com
*@Date: 2015/12/29
*/

#include "TunnelSlice.h"
#include "constant.h"
#include <GL/glut.h>
#include <cstring>

TunnelSlice::TunnelSlice()
{
}

TunnelSlice::~TunnelSlice()
{
}

TunnelSlice::TunnelSlice(Point center1, Point center2, float radius, float thick)
{
	this->center1 = center1;
	this->center2 = center2;
	this->thick = thick;
	for (int i = 0; i < FACENUM; i++)
	{
		color[i][0] = 1.0f;
		color[i][1] = 1.0f;
		color[i][2] = 1.0f;
	}
}

double TunnelSlice::toRadian(double angle)
{
	return angle / 180.0 * PI;
}

void TunnelSlice::drawASlice()
{
	glPushMatrix();

	glTranslated(center1.x,center1.y, center1.z);
	
	double angle = -ANGLESPAN / 2;
	for (int i = 0; i < FACENUM; i++)
	{
		float x1, x2, y1, y2, z1, z2;
		float x3, x4, y3, y4, z3, z4;

		x1 = 10.0*cos(toRadian(angle)); y1 = 10.0*sin(toRadian(angle));
		x2 = 10.0*cos(toRadian(angle + ANGLESPAN)); y2 = 10.0*sin(toRadian(angle + ANGLESPAN));
		z1 = 0.0f; z2 = 0.0f;

		x3 = x1 + center2.x - center1.x; x4 = x2 + center2.x - center1.x;
		y3 = y1 + center2.y - center1.y; y4 = y2 + center2.y - center1.y;
		z3 = z1 + center2.z - center1.z; z4 = z2 + center2.z - center1.z;
		
		glColor3f(0.0f, 0.0f, 0.0f);

		glBegin(GL_LINES);
		glVertex3f(x1, y1, z1);
		glVertex3f(x3, y3, z3);
		glVertex3f(x2, y2, z2);
		glVertex3f(x4, y4, z4);
		//glVertex3f((x1 + x3) / 2, (y1 + y3) / 2, (z1 + z2) / 2);
		//glVertex3f((x2 + x4)(/ 2, (y2 + y4) / 2, (z1 + z2) / 2);
		glEnd();

		//draw the tunnel
		glColor3fv(color[i]);

		glBegin(GL_TRIANGLES);
		glVertex3f(x1, y1, z1);
		glVertex3f(x2, y2, z2);
		glVertex3f(x3, y3, z3);

		glVertex3f(x2, y2, z2);
		glVertex3f(x3, y3, z3);
		glVertex3f(x4, y4, z4);
		glEnd();

		angle += 30;
	}

	glPopMatrix();
}

void TunnelSlice::move(float dx, float dy, float dz)
{
	this->center1.x += dx;
	this->center1.y += dy;
	this->center1.z += dz;

	this->center2.x += dx;
	this->center2.y += dy;
	this->center2.z += dz;
}

Point TunnelSlice::getFrontCenter()
{
	return center1;
}
 
Point TunnelSlice::getBackCenter()
{
	return center2;
}

void TunnelSlice::setFaceColor(int face, float color[])
{
	memcpy(this->color[face], color, 3 * sizeof(float));
}

int TunnelSlice::getSliceIndex()
{
	return sliceIndex;
}

void TunnelSlice::setSliceIndex(int index)
{
	sliceIndex = index;
}
