/*TunnelSlice.cpp
*@brief An implementation of the class TunnelSlice
*@Author: wang_kejie@foxmail.com
*@Date: 2015/12/29
*/

#include "TunnelSlice.h"
#include "constant.h"
#include "ObstacleType.h"
#include "Cube.h"
#include <GL/glut.h>
#include <cstring>
#include "lighting.h"

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
		float x11, x21, y11, y21, z11, z21;
		float x31, x41, y31, y41, z31, z41;

		x11 = 9.7*cos(toRadian(angle)); y11 = 9.7*sin(toRadian(angle));
		x21 = 9.7*cos(toRadian(angle + ANGLESPAN)); y21 = 9.7*sin(toRadian(angle + ANGLESPAN));
		z11 = 0.0f; z21 = 0.0f;

		x31 = x11 + center2.x - center1.x; x41 = x21 + center2.x - center1.x;
		y31 = y11 + center2.y - center1.y; y41 = y21 + center2.y - center1.y;
		z31 = z11 + center2.z - center1.z; z41 = z21 + center2.z - center1.z;

		glColor3f(0.0f, 0.0f, 0.0f);

		glLineWidth(2.0);
		glBegin(GL_LINES);
		glVertex3f(x11, y11, z11);
		glVertex3f(x31, y31, z31);
		glVertex3f(x21, y21, z21);
		glVertex3f(x41, y41, z41);
		if (sliceIndex % 4 == 0)
		{
			glVertex3f((x11 + x31) / 2, (y11 + y31) / 2, (z11 + z21) / 2);
			glVertex3f((x21 + x41) / 2, (y21 + y41) / 2, (z11 + z21) / 2);
		}
		glEnd();
		
		
		float x1, x2, y1, y2, z1, z2;
		float x3, x4, y3, y4, z3, z4;

		x1 = SLICERADIUS*cos(toRadian(angle)); y1 = SLICERADIUS*sin(toRadian(angle));
		x2 = SLICERADIUS*cos(toRadian(angle + ANGLESPAN)); y2 = SLICERADIUS*sin(toRadian(angle + ANGLESPAN));
		z1 = 0.0f; z2 = 0.0f;

		x3 = x1 + center2.x - center1.x; x4 = x2 + center2.x - center1.x;
		y3 = y1 + center2.y - center1.y; y4 = y2 + center2.y - center1.y;
		z3 = z1 + center2.z - center1.z; z4 = z2 + center2.z - center1.z;
		
		//glColor3f(0.0f, 0.0f, 0.0f);

		Point p1 = Point(x1, y1, z1);
		Point p2 = Point(x2, y2, z2);
		Point p3 = Point(x3, y3, z3);
		Point p4 = Point(x4, y4, z4);

		Point normal = crossProduct(Point(x3, y3, z3) - Point(x1, y1, z1), Point(x2, y2, z2) - Point(x1, y1, z1));

		//Point normal(0, 1, 0);

		//draw the tunnel
		glColor3fv(color[i]);
		glNormal3fv(normal.toArray());

		glBegin(GL_TRIANGLES);
		
		/*glVertex3f(x1, y1, z1);
		glVertex3f(x2, y2, z2);
		glVertex3f(x3, y3, z3);

		glVertex3f(x2, y2, z2);
		glVertex3f(x4, y4, z4);
		glVertex3f(x3, y3, z3); */

		/*Lighting::splitAndDraw(Point(x1, y1, z1).toArray(),
			Point(x2, y2, z2).toArray(),
			Point(x3, y3, z3).toArray(),
			Point(x4, y4, z4).toArray());*/

		for (int i = 0; i < SLICESPLITNUM; i++)
		{
			Point p11 = 1.0 * i / SLICESPLITNUM*p1 + 1.0 *(SLICESPLITNUM - i) / SLICESPLITNUM *p2;
			Point p31 = 1.0 *(i + 1) / SLICESPLITNUM*p1 + 1.0 *(SLICESPLITNUM - i - 1) / SLICESPLITNUM *p2;
			Point p21 = 1.0 *i / SLICESPLITNUM*p3 + 1.0 *(SLICESPLITNUM - i) / SLICESPLITNUM *p4;
			Point p41 = 1.0 *(i + 1) / SLICESPLITNUM*p3 + 1.0 *(SLICESPLITNUM - i - 1) / SLICESPLITNUM *p4;

			glVertex3fv(p11.toArray());
			glVertex3fv(p21.toArray());
			glVertex3fv(p31.toArray());

			glVertex3fv(p21.toArray());
			glVertex3fv(p41.toArray());
			glVertex3fv(p31.toArray());
		}

		glEnd();

		angle += 30;
	}

	if (sliceIndex == 100 && obs == nullptr)
	{
		randomAnObstacle(center1, center2);
	}
	
	glPopMatrix();

	if (obs != nullptr)
	{
		Point center = center1;
		center.z -= PATHWIDTH / 2;
		center.y = center.y - PATHHEIGHT / 2 + PATHWIDTH / 2 + 0.1;
		obs->setCenter(center);
		obs->draw();
	}
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

void TunnelSlice::setSpeed(Point s)
{
	this->speed = s;
}

Point TunnelSlice::getSpeed()
{
	return speed;
}

void TunnelSlice::randomAnObstacle(const Point& sliceCenter1, const Point& sliceCenter2)
{
	Point dir = sliceCenter2 - sliceCenter1;
	ObstacleType type = (ObstacleType)(0);
	int face = 9;

	switch (type)
	{
	case CUBE:
	{
		Point p(0, 0, -1);
		Point normal = crossProduct(p, dir);
		Point center = sliceCenter1;
		float angle = 0;
		if (normal.x != 0 || normal.y != 0 || normal.z != 0)
			float angle = intersecAngle(p, dir);
		center.z -= PATHWIDTH / 2;
		center.y = center.y - PATHHEIGHT / 2 + PATHWIDTH / 2;
		obs = new Cube(center, normal, angle, PATHWIDTH);
		break;
	}
	default:
		break;
	}
}