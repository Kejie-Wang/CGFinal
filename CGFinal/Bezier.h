#ifndef _BEZIERPATH_H
#define _BEZIERPATH_H

#include "Point.h"
#include <list>

class Bezier
{
public:
	Bezier();
	virtual ~Bezier();
	Point getPoint(float rate);
	Point getFstDer(float rate);
	void setCtrPoints(const std::list<Point> points);
	std::list<Point> getCtrPoints();
private:
	std::list<Point> ctrPoints;
	std::list<Point> fstCtrPoints;
	void RandomAPath();
	float start, end;
};

#endif