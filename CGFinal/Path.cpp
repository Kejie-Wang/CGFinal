#include "Path.h"
#include "constant.h"
#include <ctime>
#include <iostream>

using namespace std;

#define randf(x) (1.0 * rand() / RAND_MAX * x)

Path::Path()
{
	
}

Path::Path(float zStart, float zEnd)
{
	this->zStart = zStart;
	this->zEnd = zEnd;
	pathIndex = 0;
	RandomANewPath();
}

Path::~Path()
{
}

void Path::RandomANewPath()
{
	list<Point> ctrPoints = path.getCtrPoints();

	if (ctrPoints.empty())
	{
		ctrPoints.push_back(Point(0.0f, 0.0f, 0.0f));
		ctrPoints.push_back(Point(0.0f, 0.0f, -CTRPOINTSDDST));
	}
	else if (ctrPoints.size() >= 2)
	{
		Point last1 = ctrPoints.back();	
		ctrPoints.pop_back();
		Point last2 = ctrPoints.back();


		Point newPoint1 = last1;
		newPoint1.z = 0.0f;
		Point newPoint2 = newPoint1 + last1 - last2;

		ctrPoints.clear();
		ctrPoints.push_back(newPoint1);
		ctrPoints.push_back(newPoint2);

		//this->zStart = CTRPOINTSDDST;
	}

	/*for (int i = 0; i < 10; i++)
	{
		Point last = ctrPoints.back();
		last.z -= SLICETHICKNESS;
		ctrPoints.push_back(last);
	}*/

	srand(time(0));
	pathIndex++;
	while (ctrPoints.back().z > -TUNNELLENGTH + 50)
	{
		float dx, dy;
		//if (ctrPoints.size() <= 5 && ctrPoints.size() >=1)
		//{
		dx = 2 * randf(RADIUSDIFFSPAN) - RADIUSDIFFSPAN;
		dy = 2 * randf(RADIUSDIFFSPAN) - RADIUSDIFFSPAN;
		/*float xy = randf(1.0);
		if (xy > 0.5)
			dx = 0;
		else
			dy = 0;
		}
		else
		{
			dx = 0;
			dy = 0;
		}*/

		float x = ctrPoints.back().x, y = ctrPoints.back().y, z = ctrPoints.back().z;

		ctrPoints.push_back(Point(x + dx, y + dy, z - CTRPOINTSDDST));
	}

	while (ctrPoints.back().z > -TUNNELLENGTH)
	{
		Point last = ctrPoints.back();
		last.z -= CTRPOINTSDDST;
		ctrPoints.push_back(last);
	}


	path.setCtrPoints(ctrPoints); 
} 

Point Path::getPoint(float zCoord)
{
	return path.getPoint((zCoord - zStart) / (zEnd - zStart));
}

Point Path::getFstDer(float zCoord)
{
	return path.getFstDer((zCoord - zStart) / (zEnd - zStart));
}