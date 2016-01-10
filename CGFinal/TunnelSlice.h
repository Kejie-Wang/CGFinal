/*TunnelSlice.h
*@brief Define a slice of a tunnel
*@Author: wang_kejie@foxmail.com
*@Date: 2015/12/29
*/

#ifndef _TUNNELSLICE_H_
#define _TUNNELSLICE_H_

#include "constant.h"
#include "Point.h"


class TunnelSlice
{
private:
	Point center1, center2;
	Point speed;
	float thick;
	float color[FACENUM][3];
	int sliceIndex;
public:
	TunnelSlice();
	TunnelSlice(Point center1, Point center2, float radius = SLICERADIUS, float thick = SLICETHICKNESS);
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
};

#endif