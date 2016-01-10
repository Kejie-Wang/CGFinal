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

	//GAME START
	//WITH A STRAIGHT PATH FIRST
	/*if (ctrPoints.empty())	
	{
		ctrPoints.push_back(Point(0.0f, 0.0f, 0.0f));
		ctrPoints.push_back(Point(0.0f, 0.0f, -CTRPOINTSDDST));
	}
	else if (ctrPoints.size() >= 2)	//STAY STRAIGHT IN THE TWO PATH
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
	}*/

	ctrPoints.clear();
	for (int i = 0; i < 4;i++)
		ctrPoints.push_back(Point(0.0f, 0.0f, -CTRPOINTSDDST * i));


	//RANDOM A LIST OF CONTROL POINTS
	srand(time(0));
	pathIndex++;
	while (ctrPoints.back().z > -TUNNELLENGTH + 200)
	{
		float dx, dy;
		dx = 2 * randf(RADIUSDIFFSPAN) - RADIUSDIFFSPAN;
		dy = 2 * randf(RADIUSDIFFSPAN) - RADIUSDIFFSPAN;
		dx = 0; dy = 0;
		float x = ctrPoints.back().x, y = ctrPoints.back().y, z = ctrPoints.back().z;

		ctrPoints.push_back(Point(x + dx, y + dy, z - CTRPOINTSDDST));
	}

	//STAY STRAIGHT AT THE END OF EACH PATH
	while (ctrPoints.back().z > -TUNNELLENGTH)
	{
		Point last = ctrPoints.back();
		last.x = 0;
		last.y = 0;
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