#include "Bezier.h"
#include "constant.h"
#include <cstdlib>

using namespace std;

Bezier::Bezier()
{
}

Bezier::~Bezier()
{
}

void Bezier::setCtrPoints(const list<Point> points)
{
	this->ctrPoints = points;
	fstCtrPoints.clear();
	int n = ctrPoints.size();
	for (list<Point>::iterator it = ctrPoints.begin(); it != ctrPoints.end(); it++)
	{
		if (++it == ctrPoints.end())
			break;
		Point p2 = *it, p1 = *(--it);
		fstCtrPoints.push_back(n * (p2 - p1));
	}
}

Point Bezier::getPoint(float rate)
{
	if (ctrPoints.empty())
		return Point();

	list<Point> points = ctrPoints;
	while (points.size() > 1)
	{
		list<Point> tmp;
		for (list<Point>::iterator it = points.begin(); it != points.end(); ++it)
		{
			if (++it == points.end())
				break;
			Point p2 = *it;
			Point p1 = *(--it);
			tmp.push_back(rate * p2 + (1 - rate) * p1);
		}
		points = tmp;
	}

	return points.back();
}

Point Bezier::getFstDer(float rate)
{
	if (fstCtrPoints.empty())
		return Point();

	list<Point> points = fstCtrPoints;
	while (points.size() > 1)
	{
		list<Point> tmp;
		for (list<Point>::iterator it = points.begin(); it != points.end(); ++it)
		{
			if (++it == points.end())
				break;
			Point p2 = *it;
			Point p1 = *(--it);
			tmp.push_back(rate * p2 + (1 - rate) * p1);
		}
		points = tmp;
	}
	
	return points.back();
}

list<Point> Bezier::getCtrPoints()
{
	return ctrPoints;
}