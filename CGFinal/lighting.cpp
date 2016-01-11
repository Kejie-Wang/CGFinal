#include "lighting.h"
#include <cmath>

void Lighting::initLighting(GLfloat positionX, GLfloat positionY, GLfloat positionZ)
{
	for (int i = 0; i < 8; i++)
		isOccupied[0] = false;

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
	GLfloat directionX = 0;
	GLfloat directionY = 0;
	GLfloat directionZ = -100;

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
	GLfloat spotExponent = 0;
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, spotExponent);
	glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, spotExponent);
	glLightf(GL_LIGHT3, GL_SPOT_EXPONENT, spotExponent);
	glLightf(GL_LIGHT4, GL_SPOT_EXPONENT, spotExponent);
	glLightf(GL_LIGHT5, GL_SPOT_EXPONENT, spotExponent);
	glLightf(GL_LIGHT6, GL_SPOT_EXPONENT, spotExponent);
	glLightf(GL_LIGHT7, GL_SPOT_EXPONENT, spotExponent);

	//聚光灯角度
	GLfloat spotCutoff = 6;
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, spotCutoff);
	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, spotCutoff);
	glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, spotCutoff);
	glLightf(GL_LIGHT4, GL_SPOT_CUTOFF, spotCutoff);
	glLightf(GL_LIGHT5, GL_SPOT_CUTOFF, spotCutoff);
	glLightf(GL_LIGHT6, GL_SPOT_CUTOFF, spotCutoff);
	glLightf(GL_LIGHT7, GL_SPOT_CUTOFF, spotCutoff);

	//衰变
	GLfloat linearAttenuation = 0.0001;
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, linearAttenuation);
	glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, linearAttenuation);
	glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, linearAttenuation);
	glLightf(GL_LIGHT3, GL_LINEAR_ATTENUATION, linearAttenuation);
	glLightf(GL_LIGHT4, GL_LINEAR_ATTENUATION, linearAttenuation);
	glLightf(GL_LIGHT5, GL_LINEAR_ATTENUATION, linearAttenuation);
	glLightf(GL_LIGHT6, GL_LINEAR_ATTENUATION, linearAttenuation);
	glLightf(GL_LIGHT7, GL_LINEAR_ATTENUATION, linearAttenuation);
	//GLfloat quadraticAttenuation = 0.00001;
	//glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, linearAttenuation);
	//glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, linearAttenuation);
	//glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, linearAttenuation);
	//glLightf(GL_LIGHT3, GL_QUADRATIC_ATTENUATION, linearAttenuation);
	//glLightf(GL_LIGHT4, GL_QUADRATIC_ATTENUATION, linearAttenuation);
	//glLightf(GL_LIGHT5, GL_QUADRATIC_ATTENUATION, linearAttenuation);
	//glLightf(GL_LIGHT6, GL_QUADRATIC_ATTENUATION, linearAttenuation);
	//glLightf(GL_LIGHT7, GL_QUADRATIC_ATTENUATION, linearAttenuation);


	//点光源GL_LIGHT0
	GLfloat ambientAndDiffuseLight0[] = { 0.15, 0.15, 0.15, 1 };
	GLfloat specularLight0[] = { 0, 0, 0, 1 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientAndDiffuseLight0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, ambientAndDiffuseLight0);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight0);
	glEnable(GL_LIGHT0);

	//聚光灯
	GLfloat diffuseLight1[] = { 0.4, 0.6, 0.86, 1 };
	GLfloat specularLight1[] = { 0.4, 0.6, 0.8, 1 };
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuseLight1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, specularLight1);
	glEnable(GL_LIGHT1);

	GLfloat diffuseLight2[] = { 0, 1, 0, 1 };
	GLfloat specularLight2[] = { 0, 1, 0, 1 };
	glLightfv(GL_LIGHT2, GL_DIFFUSE, diffuseLight2);
	glLightfv(GL_LIGHT2, GL_SPECULAR, specularLight2);
//	glEnable(GL_LIGHT2);

	GLfloat diffuseLight3[] = { 0.7, 0.3, 1, 1 };
	GLfloat specularLight3[] = { 0.7, 0.3, 1, 1 };
	glLightfv(GL_LIGHT3, GL_DIFFUSE, diffuseLight3);
	glLightfv(GL_LIGHT3, GL_SPECULAR, specularLight3);
	glEnable(GL_LIGHT3);

	GLfloat diffuseLight4[] = { 1, 1, 0, 1 };
	GLfloat specularLight4[] = { 1, 1, 0, 1 };
	glLightfv(GL_LIGHT4, GL_DIFFUSE, diffuseLight4);
	glLightfv(GL_LIGHT4, GL_AMBIENT, diffuseLight4);
	glLightfv(GL_LIGHT4, GL_SPECULAR, specularLight4);
//	glEnable(GL_LIGHT4);

	GLfloat diffuseLight5[] = { 0.5, 0, 1, 1 };
	GLfloat specularLight5[] = { 0.5, 0, 1, 1 };
	glLightfv(GL_LIGHT5, GL_AMBIENT, diffuseLight5);
	glLightfv(GL_LIGHT5, GL_DIFFUSE, diffuseLight5);
	glLightfv(GL_LIGHT5, GL_SPECULAR, specularLight5);
//	glEnable(GL_LIGHT5);

	GLfloat diffuseLight6[] = { 0.2, 1, 0.5, 1 };
	GLfloat specularLight6[] = { 0.2, 1, 0.5, 1 };
	glLightfv(GL_LIGHT6, GL_DIFFUSE, diffuseLight6);
	glLightfv(GL_LIGHT6, GL_SPECULAR, specularLight6);
	glEnable(GL_LIGHT6);

	GLfloat diffuseLight7[] = { 1, 0.4, 0.8, 1 };
	GLfloat specularLight7[] = { 1, 0.4, 0.8, 1 };
	glLightfv(GL_LIGHT7, GL_DIFFUSE, diffuseLight7);
	glLightfv(GL_LIGHT7, GL_SPECULAR, specularLight7);
//	glEnable(GL_LIGHT7);

	//材质
	GLfloat ambientMaterial[] = { 1, 1, 1, 1 };
	GLfloat specularMaterial[] = { 1, 1, 1, 1 };
//	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientMaterial);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, ambientMaterial);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specularMaterial);
	glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, 1);

	glEnable(GL_LIGHTING);
}

int Lighting::updateLight(int index, GLfloat* direction)
{
	GLfloat position[] = { 0, 0, 0, 1 };

	if (index == 0)
	{
		for (int i = 1; i < 8; i++)
		{
			if (isOccupied[i] == false)
			{
				index = i;
				isOccupied[i] = true;
				switch (index)
				{
				case 1:
					glEnable(GL_LIGHT1);
					break;
				case 2:
					glEnable(GL_LIGHT2);
					break;
				case 3:
					glEnable(GL_LIGHT3);
					break;
				case 4:
					glEnable(GL_LIGHT4);
					break;
				case 5:
					glEnable(GL_LIGHT5);
					break;
				case 6:
					glEnable(GL_LIGHT6);
					break;
				case 7:
					glEnable(GL_LIGHT7);
					break;
				}
				break;
			}
		}
	}

	switch (index)
	{
	case 1:
		spotDirection1[0] = direction[0];
		spotDirection1[1] = direction[1];
		spotDirection1[2] = direction[2];
		glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spotDirection1);
	//	glLightfv(GL_LIGHT1, GL_POSITION, position);
		break;
	case 2:
		spotDirection2[0] = direction[0];
		spotDirection2[1] = direction[1];
		spotDirection2[2] = direction[2];
		glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spotDirection2);
	//	glLightfv(GL_LIGHT2, GL_POSITION, position);
		break;
	case 3:
		spotDirection3[0] = direction[0];
		spotDirection3[1] = direction[1];
		spotDirection3[2] = direction[2];
		glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, spotDirection3);
	//	glLightfv(GL_LIGHT3, GL_POSITION, position);
		break;
	case 4:
		spotDirection4[0] = direction[0];
		spotDirection4[1] = direction[1];
		spotDirection4[2] = direction[2];
		glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, spotDirection4);
	//	glLightfv(GL_LIGHT4, GL_POSITION, position);
		break;
	case 5:
		spotDirection5[0] = direction[0];
		spotDirection5[1] = direction[1];
		spotDirection5[2] = direction[2];
		glLightfv(GL_LIGHT5, GL_SPOT_DIRECTION, spotDirection5);
	//	glLightfv(GL_LIGHT5, GL_POSITION, position);
		break;
	case 6:
		spotDirection6[0] = direction[0];
		spotDirection6[1] = direction[1];
		spotDirection6[2] = direction[2];
		glLightfv(GL_LIGHT6, GL_SPOT_DIRECTION, spotDirection6);
	//	glLightfv(GL_LIGHT6, GL_POSITION, position);
		break;
	case 7:
		spotDirection7[0] = direction[0];
		spotDirection7[1] = direction[1];
		spotDirection7[2] = direction[2];
		glLightfv(GL_LIGHT7, GL_SPOT_DIRECTION, spotDirection7);
	//	glLightfv(GL_LIGHT7, GL_POSITION, position);
		break;
	}
	return index;
}

void Lighting::deleteLight(int index)
{
	isOccupied[index] = false;

	switch (index)
	{
	case 1:
		glDisable(GL_LIGHT1);
		break;
	case 2:
		glDisable(GL_LIGHT2);
		break;
	case 3:
		glDisable(GL_LIGHT3);
		break;
	case 4:
		glDisable(GL_LIGHT4);
		break;
	case 5:
		glDisable(GL_LIGHT5);
		break;
	case 6:
		glDisable(GL_LIGHT6);
		break;
	case 7:
		glDisable(GL_LIGHT7);
		break;
	}
}

void Lighting::changeLighting()
{
	GLfloat rate = 1.5;
	GLfloat xMax = 14;
	GLfloat xMin = -14;
	GLfloat yMax = 14;
	GLfloat yMin = -10;

	spotDirection1[0] += spot1SpeedX*rate;
	spotDirection1[1] += spot1SpeedY*rate;
	if (spotDirection1[0] > xMax || spotDirection1[0] < xMin)
		spot1SpeedX = -spot1SpeedX;
	if (spotDirection1[1] > yMax || spotDirection1[1] < yMin)
		spot1SpeedY = -spot1SpeedY;

	spotDirection2[0] += spot2SpeedX*rate;
	spotDirection2[1] += spot2SpeedY*rate;
	if (spotDirection2[0] > xMax || spotDirection2[0] < xMin)
		spot2SpeedX = -spot2SpeedX;
	if (spotDirection2[1] > yMax || spotDirection2[1] < yMin)
		spot2SpeedY = -spot2SpeedY;

	spotDirection3[0] += spot3SpeedX*rate;
	spotDirection3[1] += spot3SpeedY*rate;
	if (spotDirection3[0] > xMax || spotDirection3[0] < xMin)
		spot3SpeedX = -spot3SpeedX;
	if (spotDirection3[1] > yMax || spotDirection3[1] < yMin)
		spot3SpeedY = -spot3SpeedY;

	spotDirection4[0] += spot4SpeedX*rate;
	spotDirection4[1] += spot4SpeedY*rate;
	if (spotDirection4[0] > xMax || spotDirection4[0] < xMin)
		spot4SpeedX = -spot4SpeedX;
	if (spotDirection4[1] > yMax || spotDirection4[1] < yMin)
		spot4SpeedY = -spot4SpeedY;

	spotDirection5[0] += spot5SpeedX*rate;
	spotDirection5[1] += spot5SpeedY*rate;
	if (spotDirection5[0] > xMax || spotDirection5[0] < xMin)
		spot5SpeedX = -spot5SpeedX;
	if (spotDirection5[1] > yMax || spotDirection5[1] < yMin)
		spot5SpeedY = -spot5SpeedY;

	spotDirection6[0] += spot6SpeedX*rate;
	spotDirection6[1] += spot6SpeedY*rate;
	if (spotDirection6[0] > xMax || spotDirection6[0] < xMin)
		spot6SpeedX = -spot6SpeedX;
	if (spotDirection6[1] > yMax || spotDirection6[1] < yMin)
		spot6SpeedY = -spot6SpeedY;

	spotDirection7[0] += spot7SpeedX*rate;
	spotDirection7[1] += spot7SpeedY*rate;
	if (spotDirection7[0] > xMax || spotDirection7[0] < xMin)
		spot7SpeedX = -spot7SpeedX;
	if (spotDirection7[1] > yMax || spotDirection7[1] < yMin)
		spot7SpeedY = -spot7SpeedY;

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

	int resolution = 1;
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