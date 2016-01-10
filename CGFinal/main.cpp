#include "GL/glut.h"
#include <cmath>
#include <iostream>
#include "Tunnel.h"
#include "constant.h"

using namespace std;

Tunnel tunnel;

void display()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	Point dir = tunnel.getDirection() + Point(eyex, eyey, 0); 

	gluLookAt(eyex, eyey, 0, dir.x, dir.y, dir.z, 0, 1, 0);	//set the position and direction of the  eye point
	
	tunnel.drawATunnel();
	
	glutSwapBuffers();

}

void Reshape(int w, int h)
{
	//if (w > h)
	//	glViewport((w - h) / 2, 0, h, h);
	//else
	//	glViewport(0, (h - w) / 2, w, w);

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 1, 300);
}

void myIdle()
{
	display();
}

int main(int argc, char *argv[])
{
	/*list<int> l;
	l.push_back(1);
	l.push_back(10);
	l.push_back(20);

	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
		cout << *it << endl;

	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
		
	
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
		cout << *it << endl;
		*/
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(WINWIDTH, WINHEIGHT);
	glutCreateWindow("Tunnel Test");
	glutDisplayFunc(&display);
	glutIdleFunc(myIdle);
	glutReshapeFunc(Reshape);
	glutMainLoop();
	return 0;
}