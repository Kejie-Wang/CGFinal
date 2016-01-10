#ifndef _PATH_H_
#define _PATH_H_

#include "Bezier.h"
#include "Point.h"

class Path
{
private:
	Bezier path;
	float zStart, zEnd;
	int pathIndex;
public:
	Path();
	Path(float zStart, float zEnd);
	virtual ~Path();
	void RandomANewPath();
	Point getPoint(float zCoord);
	Point getFstDer(float zCoord);
};

#endif //_PATH_H_