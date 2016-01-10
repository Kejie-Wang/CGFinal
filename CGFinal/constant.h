/*constant.h
*@brief Define some constant variables
*@Author: wang_kejie@foxmail.com
*@Date: 2015/12/29
*/
#ifndef _CONSTANT_H_
#define _CONSTANT_H_

#include <cmath>

static const double PI = 2 * asin(1);

/*
*view constant
*/

static float eyex = 0.0f;
static float eyey = 0.0f;
static const float eyez = 0.0f;

/*
*window constant
*/
static const int WINWIDTH = 800;
static const int WINHEIGHT = 500;

/*
*tunnel slice constant
*/
static const int FACENUM = 12;
static const int ANGLESPAN = 360 / FACENUM;

static const float SLICERADIUS = 10.0f;
static const float SLICETHICKNESS = 1.0f;

/*
*tunnel constant
*/
static const float TUNNELLENGTH = 300.0f;
static const int SLICENUMS = 300;

/*
*Bezier path constant
*/
static const float CTRPOINTSDDST = 100.0f;
static const float RADIUSDIFFSPAN = 30.0f;

#endif