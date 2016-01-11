/*TunnelSlice.h
*@brief Define a slice of a tunnel
*@Author: wang_kejie@foxmail.com
*@Date: 2015/12/29
*/

#ifndef _TUNNELSLICE_H_
#define _TUNNELSLICE_H_

#include "constant.h"
#include "Point.h"
#include "Obstacle.h"

class TunnelSlice
{
private:
	Point center1, center2;
	Point speed;
	float thick;
	float color[FACENUM][3];
	int sliceIndex;
	int face;
	float *ObstacleColor = nullptr;
	int ligthIndex;
	bool isWithObstacle;
	bool colorSet[FACENUM];
	Obstacle* obs = nullptr;
	void randomAnObstacle(const Point& sliceCenter1, const Point& sliceCenter2);
public:
	TunnelSlice();
	TunnelSlice(Point center1, Point center2, bool isWithObstacle = false);
	~TunnelSlice();
	void drawASlice();
	void move(float dx, float dy, float dz);
	Point getFrontCenter();
	Point getBackCenter();
	double toRadian(double angle);
	void setFaceColor(int face, float color[]);
	void setSliceIndex(int index);
	int getSliceIndex();
	void setSpeed(Point s);
	Point getSpeed();
	void setIsWithObstacle(bool isWith);
	bool getIsWithObstacle();
	int getFace();
	float* getObstacleColor();
};

#endif