/*Tunnel.h
*@brief define the tunnel of the game
*@Author: wang_kejie@foxmail.com
*@Date: 2016/1/3
*/
#include "Tunnel.h"
#include "constant.h"
#include <iostream>

using namespace std;

Tunnel::Tunnel() 
	: path(0, -TUNNELLENGTH)
{
	//initializa the tunnel
	TunnelSlice slice(Point(eyex, eyey, eyez), Point(eyex, eyey, eyez - SLICETHICKNESS));
	slice.setSliceIndex(0);
	slice.setSpeed(path.getFstDer(0));
	tunnel.push_back(slice);

	while (tunnel.size() < SLICENUMS)
	{
		float zCoord = tunnel.back().getBackCenter().z;
		int sliceIndex = tunnel.back().getSliceIndex();

		Point newCenter1 = tunnel.back().getBackCenter();
		Point newCenter2 = path.getPoint((-sliceIndex - 2) * SLICETHICKNESS);

		TunnelSlice newSlice(newCenter1, newCenter2);
		newSlice.setSliceIndex(sliceIndex + 1);
		newSlice.setSpeed(path.getFstDer(zCoord));
		tunnel.push_back(newSlice);
	}
}

Tunnel::~Tunnel()
{
}

void Tunnel::updateTunnel()
{
	//move
	Point speed = tunnel.front().getSpeed();
	float speedValue = speed.length();
	//for (int i = 0; i < 3;i++)
		tunnel.pop_front();



	float dx = -tunnel.front().getFrontCenter().x;
	float dy = -tunnel.front().getFrontCenter().y;
	float dz = -tunnel.front().getFrontCenter().z;

	//new a tunnel
	while(tunnel.size() < SLICENUMS)
	{
		float zCoord = tunnel.back().getBackCenter().z;
		int sliceIndex = tunnel.back().getSliceIndex();
		if (sliceIndex + 1 == SLICENUMS)
		{
			path.RandomANewPath();
			std::cout << "fuck";
			sliceIndex = -1;
		}

		Point newCenter1 = tunnel.back().getBackCenter();
		//Point newCenter1 = path.getPoint(-sliceIndex - 1);
		Point newCenter2 = path.getPoint((-sliceIndex - 2)*SLICETHICKNESS);
		newCenter1.z = zCoord;
		newCenter2.z = zCoord - SLICETHICKNESS;

		TunnelSlice newSlice(newCenter1, newCenter2);
		newSlice.setSliceIndex((sliceIndex + 1) % SLICENUMS);
		newSlice.setSpeed(path.getFstDer(zCoord));
		tunnel.push_back(newSlice);
	}

	for (list<TunnelSlice>::iterator it = tunnel.begin(); it != tunnel.end(); it++)
		it->move(dx, dy, dz);
}

void Tunnel::drawATunnel()
{
	for (list<TunnelSlice>::iterator it = tunnel.begin(); it != tunnel.end(); it++)
		it->drawASlice();
}

Point Tunnel::getDirection()
{
	updateTunnel();

	Point p1 = tunnel.front().getFrontCenter();
	Point p2 = tunnel.front().getBackCenter();
	return p2 - p1;

	Point p = tunnel.front().getSpeed();
	return p;
}