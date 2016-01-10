#include "lighting.h"
#include <cmath>

void Lighting::initLighting(GLfloat positionX, GLfloat positionY, GLfloat positionZ)
{
	//光源位置
	GLfloat position[] = { positionX, positionY, positionY, 1 };
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glLightfv(GL_LIGHT1, GL_POSITION, position);
	glLightfv(GL_LIGHT2, GL_POSITION, position);
	glLightfv(GL_LIGHT3, GL_POSITION, position);
	glLightfv(GL_LIGHT4, GL_POSITION, position);
	glLightfv(GL_LIGHT5, GL_POSITION, position);
	glLightfv(GL_LIGHT6, GL_POSITION, position);
	glLightfv(GL_LIGHT7, GL_POSITION, position);

	//聚光灯方向
	GLfloat directionX = -100;
	GLfloat directionY = 0;
	GLfloat directionZ = 0;

	spotDirection1[0] = directionX;
	spotDirection1[1] = directionY;
	spotDirection1[2] = directionZ;
	spotDirection2[0] = directionX;
	spotDirection2[1] = directionY;
	spotDirection2[2] = directionZ;
	spotDirection3[0] = directionX;
	spotDirection3[1] = directionY;
	spotDirection3[2] = directionZ;
	spotDirection4[0] = directionX;
	spotDirection4[1] = directionY;
	spotDirection4[2] = directionZ;
	spotDirection5[0] = directionX;
	spotDirection5[1] = directionY;
	spotDirection5[2] = directionZ;
	spotDirection6[0] = directionX;
	spotDirection6[1] = directionY;
	spotDirection6[2] = directionZ;
	spotDirection7[0] = directionX;
	spotDirection7[1] = directionY;
	spotDirection7[2] = directionZ;
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spotDirection1);
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spotDirection2);
	glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, spotDirection3);
	glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, spotDirection4);
	glLightfv(GL_LIGHT5, GL_SPOT_DIRECTION, spotDirection5);
	glLightfv(GL_LIGHT6, GL_SPOT_DIRECTION, spotDirection6);
	glLightfv(GL_LIGHT7, GL_SPOT_DIRECTION, spotDirection7);

	//聚光程度
	GLfloat spotExponent = 100;
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, spotExponent);
	glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, spotExponent);
	glLightf(GL_LIGHT3, GL_SPOT_EXPONENT, spotExponent);
	glLightf(GL_LIGHT4, GL_SPOT_EXPONENT, spotExponent);
	glLightf(GL_LIGHT5, GL_SPOT_EXPONENT, spotExponent);
	glLightf(GL_LIGHT6, GL_SPOT_EXPONENT, spotExponent);
	glLightf(GL_LIGHT7, GL_SPOT_EXPONENT, spotExponent);

	//聚光灯角度
	GLfloat spotCutoff = 10;
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, spotCutoff);
	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, spotCutoff);
	glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, spotCutoff);
	glLightf(GL_LIGHT4, GL_SPOT_CUTOFF, spotCutoff);
	glLightf(GL_LIGHT5, GL_SPOT_CUTOFF, spotCutoff);
	glLightf(GL_LIGHT6, GL_SPOT_CUTOFF, spotCutoff);
	glLightf(GL_LIGHT7, GL_SPOT_CUTOFF, spotCutoff);

	//衰变
	GLfloat linearAttenuation = 0.1;
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, linearAttenuation);
	glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, linearAttenuation);
	glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, linearAttenuation);
	glLightf(GL_LIGHT3, GL_LINEAR_ATTENUATION, linearAttenuation);
	glLightf(GL_LIGHT4, GL_LINEAR_ATTENUATION, linearAttenuation);
	glLightf(GL_LIGHT5, GL_LINEAR_ATTENUATION, linearAttenuation);
	glLightf(GL_LIGHT6, GL_LINEAR_ATTENUATION, linearAttenuation);
	glLightf(GL_LIGHT7, GL_LINEAR_ATTENUATION, linearAttenuation);

	//点光源GL_LIGHT0
	GLfloat ambientAndDiffuseLight0[] = { 1, 0.5, 0.5, 1 };
	GLfloat specularLight0[] = { 0, 0, 0, 1 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientAndDiffuseLight0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, ambientAndDiffuseLight0);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight0);
	glEnable(GL_LIGHT0);

	//聚光灯
	GLfloat diffuseLight1[] = { 0.5, 0, 0, 1 };
	GLfloat specularLight1[] = { 0.5, 0, 0, 1 };
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuseLight1);
//	glLightfv(GL_LIGHT1, GL_AMBIENT, diffuseLight1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, specularLight1);
	glEnable(GL_LIGHT1);

	GLfloat diffuseLight2[] = { 0, 0.5, 0, 1 };
	GLfloat specularLight2[] = { 0, 0.5, 0, 1 };
//	glLightfv(GL_LIGHT1, GL_AMBIENT, diffuseLight2);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, diffuseLight2);
	glLightfv(GL_LIGHT2, GL_SPECULAR, specularLight2);
	glEnable(GL_LIGHT2);

	GLfloat diffuseLight3[] = { 0, 0, 0.5, 1 };
	GLfloat specularLight3[] = { 0, 0, 0.5, 1 };
	glLightfv(GL_LIGHT3, GL_DIFFUSE, diffuseLight3);
	glLightfv(GL_LIGHT3, GL_SPECULAR, specularLight3);
	glEnable(GL_LIGHT3);

	GLfloat diffuseLight4[] = { 0.5, 0.5, 0, 1 };
	GLfloat specularLight4[] = { 0.5, 0.5, 0, 1 };
	glLightfv(GL_LIGHT4, GL_DIFFUSE, diffuseLight4);
	glLightfv(GL_LIGHT4, GL_SPECULAR, specularLight4);
	glEnable(GL_LIGHT4);

	GLfloat diffuseLight5[] = { 0.5, 0, 0.5, 1 };
	GLfloat specularLight5[] = { 0.5, 0, 0.5, 1 };
	glLightfv(GL_LIGHT5, GL_DIFFUSE, diffuseLight5);
	glLightfv(GL_LIGHT5, GL_SPECULAR, specularLight5);
	glEnable(GL_LIGHT5);

	GLfloat diffuseLight6[] = { 0, 0.5, 0.5, 1 };
	GLfloat specularLight6[] = { 0, 0.5, 0.5, 1 };
	glLightfv(GL_LIGHT6, GL_DIFFUSE, diffuseLight6);
	glLightfv(GL_LIGHT6, GL_SPECULAR, specularLight6);
	glEnable(GL_LIGHT6);

	GLfloat diffuseLight7[] = { 0.3, 0.4, 0.8, 1 };
	GLfloat specularLight7[] = { 0.3, 0.4, 0.8, 1 };
	glLightfv(GL_LIGHT7, GL_DIFFUSE, diffuseLight7);
	glLightfv(GL_LIGHT7, GL_SPECULAR, specularLight7);
	glEnable(GL_LIGHT7);

	//材质
	GLfloat ambientMaterial[] = { 0.4, 0.4, 0.4, 1 };
	GLfloat specularMaterial[] = { 1, 1, 1, 1 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambientMaterial);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, ambientMaterial);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specularMaterial);
	glMateriali(GL_FRONT, GL_SHININESS, 1);

	glEnable(GL_LIGHTING);
}

void Lighting::changeLighting()
{
	GLfloat rate = 1;
	GLfloat yMax = 100;
	GLfloat yMin = -100;
	GLfloat zMax = 100;
	GLfloat zMin = -100;

	spotDirection1[1] += spot1SpeedY*rate;
	spotDirection1[2] += spot1SpeedZ*rate;
	if (spotDirection1[1] > yMax || spotDirection1[1] < yMin)
		spot1SpeedY = -spot1SpeedY;
	if (spotDirection1[2] > zMax || spotDirection1[2] < zMin)
		spot1SpeedZ = -spot1SpeedZ;

	spotDirection2[1] += spot2SpeedY*rate;
	spotDirection2[2] += spot2SpeedZ*rate;
	if (spotDirection2[1] > yMax || spotDirection2[1] < yMin)
		spot2SpeedY = -spot2SpeedY;
	if (spotDirection2[2] > zMax || spotDirection2[2] < zMin)
		spot2SpeedZ = -spot2SpeedZ;

	spotDirection3[1] += spot3SpeedY*rate;
	spotDirection3[2] += spot3SpeedZ*rate;
	if (spotDirection3[1] > yMax || spotDirection3[1] < yMin)
		spot3SpeedY = -spot3SpeedY;
	if (spotDirection3[2] > zMax || spotDirection3[2] < zMin)
		spot3SpeedZ = -spot3SpeedZ;

	spotDirection4[1] += spot4SpeedY*rate;
	spotDirection4[2] += spot4SpeedZ*rate;
	if (spotDirection4[1] > yMax || spotDirection4[1] < yMin)
		spot4SpeedY = -spot4SpeedY;
	if (spotDirection4[2] > zMax || spotDirection4[2] < zMin)
		spot4SpeedZ = -spot4SpeedZ;

	spotDirection5[1] += spot5SpeedY*rate;
	spotDirection5[2] += spot5SpeedZ*rate;
	if (spotDirection5[1] > yMax || spotDirection5[1] < yMin)
		spot5SpeedY = -spot5SpeedY;
	if (spotDirection5[2] > zMax || spotDirection5[2] < zMin)
		spot5SpeedZ = -spot5SpeedZ;

	spotDirection6[1] += spot6SpeedY*rate;
	spotDirection6[2] += spot6SpeedZ*rate;
	if (spotDirection6[1] > yMax || spotDirection6[1] < yMin)
		spot6SpeedY = -spot6SpeedY;
	if (spotDirection6[2] > zMax || spotDirection6[2] < zMin)
		spot6SpeedZ = -spot6SpeedZ;

	spotDirection7[1] += spot7SpeedY*rate;
	spotDirection7[2] += spot7SpeedZ*rate;
	if (spotDirection7[1] > yMax || spotDirection7[1] < yMin)
		spot7SpeedY = -spot7SpeedY;
	if (spotDirection7[2] > zMax || spotDirection7[2] < zMin)
		spot7SpeedZ = -spot7SpeedZ;

	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spotDirection1);
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spotDirection2);
	glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, spotDirection3);
	glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, spotDirection4);
	glLightfv(GL_LIGHT5, GL_SPOT_DIRECTION, spotDirection5);
	glLightfv(GL_LIGHT6, GL_SPOT_DIRECTION, spotDirection6);
	glLightfv(GL_LIGHT7, GL_SPOT_DIRECTION, spotDirection7);
}

void Lighting::splitAndDraw(GLfloat* p1, GLfloat* p2, GLfloat* p3, GLfloat* p4)
{

	int resolution = 2;
	GLdouble length1 = sqrt((p1[0] - p2[0]) * (p1[0] - p2[0])
		+ (p1[1] - p2[1]) * (p1[1] - p2[1])
		+ (p1[2] - p2[2]) * (p1[2] - p2[2]));
	GLdouble length2 = sqrt((p3[0] - p2[0]) * (p3[0] - p2[0])
		+ (p3[1] - p2[1]) * (p3[1] - p2[1])
		+ (p3[2] - p2[2]) * (p3[2] - p2[2]));
	int num1 = length1 / resolution;
	if (num1 == 0)
		num1 = 1;
	int num2 = length2 / resolution;
	if (num2 == 0)
		num2 = 1;

	for (int i = 0; i <= num1; i++)
	{
		float temp1[] = { (p1[0] - p2[0]) / num1 * i + p2[0],
			(p1[1] - p2[1]) / num1 * i + p2[1], (p1[2] - p2[2]) / num1 * i + p2[2] };
		float temp2[] = { (p4[0] - p3[0]) / num1 * i + p3[0],
			(p4[1] - p3[1]) / num1 * i + p3[1], (p4[2] - p3[2]) / num1 * i + p3[2] };
		for (int j = 0; j <= num2; j++)
		{
			GLfloat x = (temp1[0] - temp2[0]) / num2 * j + temp2[0];
			GLfloat y = (temp1[1] - temp2[1]) / num2 * j + temp2[1];
			GLfloat z = (temp1[2] - temp2[2]) / num2 * j + temp2[2];

			glVertex3f(x, y, z);
			glVertex3f(x + (p2[0] - p1[0]) / num1, y + (p2[1] - p1[1]) / num1, z + (p2[2] - p1[2]) / num1);
			glVertex3f(x + (p2[0] - p1[0]) / num1 + (p3[0] - p2[0]) / num2,
				y + (p2[1] - p1[1]) / num1 + (p3[1] - p2[1]) / num2,
				z + (p2[2] - p1[2]) / num1 + (p3[2] - p2[2]) / num2);
			glVertex3f(x + (p4[0] - p1[0]) / num2, y + (p4[1] - p1[1]) / num2, z + (p4[2] - p1[2]) / num2);
		}
	}
}