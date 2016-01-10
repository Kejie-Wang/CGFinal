/*Tunnel.h
*@brief define the tunnel of the game
*@Author: wang_kejie@foxmail.com
*@Date: 2016/1/3
*/
#ifndef _TUNNEL_H_
#define _TUNNEL_H_

#include <list>
#include "TunnelSlice.h"
#include "Path.h"
#include "Obstacle.h"

class Tunnel
{
public:
	Tunnel();
	~Tunnel();
	void drawATunnel();
	Point getDirection();
private:
	std::list<TunnelSlice> tunnel;
	//std::list<Obstacle*> obstacles;
	Path path;
	void updateTunnel();
};

#endif	//_TUNNEL_H_