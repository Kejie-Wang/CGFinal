#include "Point.h"
#include <cmath>

Point::Point()
{
}

Point::~Point()
{
}

Point::Point(float x, float y, float z)
{
	this->x = x; this->y = y; this->z = z;
}

float Point::length()
{
	return sqrt(x*x + y*y + z*z);
}

Point operator+(const Point& lhs, const Point& rhs)
{
	return Point(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}

Point operator-(const Point& lhs, const Point& rhs)
{
	return Point(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
}

Point operator*(const float& lhs, const Point& rhs)
{
	return Point(lhs*rhs.x, lhs*rhs.y, lhs*rhs.z);
}

Point operator*(const Point& lhs, const float& rhs)
{
	return rhs * lhs;
}

