#define GLUT_DISABLE_ATEXIT_HACK
#include<stdlib.h>
#include "GL/glut.h"
#include <cmath>
#include <iostream>
#include "Tunnel.h"
#include "constant.h"
#include "lighting.h"
#include "object.h"
#pragma comment(linker,"/subsystem:windows /entry:mainCRTStartup")

using namespace std;

Tunnel tunnel;
tank tankObj;
GLfloat angle = 0;

void display()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glShadeModel(GL_SMOOTH);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	Point dir = tunnel.getDirection() + Point(eyex, eyey, 0);

	gluLookAt(eyex, eyey, 0, dir.x, dir.y, dir.z, 0, 1, 0);	//set the position and direction of the  eye point
	tunnel.setAngle(angle);
	//tankObj.drawtank();
	glDisable(GL_TEXTURE_2D);
	tunnel.drawATunnel();

	glutSwapBuffers();

}

void Reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1.0 * w / h, 1, 300);
}

void myIdle()
{
	light.changeLighting();
	glutPostRedisplay();
}

void specialKeyCB(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		angle += 360 / 12;
		break;
	case GLUT_KEY_RIGHT:
		angle -= 30;
		break;
	default:
		break;
	}
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(WINWIDTH, WINHEIGHT);	
	glutCreateWindow("Tunnel Test");

	light.initLighting(0, 0, 0);
	glutSpecialFunc(specialKeyCB);
	glutDisplayFunc(&display);
	glutIdleFunc(myIdle);
	glutReshapeFunc(Reshape);
	init();
	glutMainLoop();
	return 0;
}
