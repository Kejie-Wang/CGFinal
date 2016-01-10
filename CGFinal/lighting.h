#ifndef LIGHTING_H
#define LIGHTING_H

#include <GL/glut.h>

class Lighting{
private:
	GLfloat spotDirection1[3];
	GLfloat spotDirection2[3];
	GLfloat spotDirection3[3];
	GLfloat spotDirection4[3];
	GLfloat spotDirection5[3];
	GLfloat spotDirection6[3];
	GLfloat spotDirection7[3];

	GLfloat spot1SpeedY = 1;
	GLfloat spot1SpeedZ = 1;
	GLfloat spot2SpeedY = -1;
	GLfloat spot2SpeedZ = 0.7;
	GLfloat spot3SpeedY = 0.5;
	GLfloat spot3SpeedZ = -1;
	GLfloat spot4SpeedY = 0.3;
	GLfloat spot4SpeedZ = 0.7;
	GLfloat spot5SpeedY = -0.7;
	GLfloat spot5SpeedZ = -0.6;
	GLfloat spot6SpeedY = -0.5;
	GLfloat spot6SpeedZ = 0.5;
	GLfloat spot7SpeedY = 0.4;
	GLfloat spot7SpeedZ = -0.8;

public:

	//初始化光源
	void initLighting(GLfloat positionX, GLfloat positionY, GLfloat positionZ);

	//变换光源
	void changeLighting();

	//细分一个平面，传进来的四个点要按顺时针或者逆时针
	//其中只包括glVertex，不包括glBegin, glEnd, glNormal, glColor等
	static void splitAndDraw(GLfloat* p1, GLfloat* p2, GLfloat* p3, GLfloat* p4);
};


#endif