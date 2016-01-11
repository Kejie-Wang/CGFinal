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

float Point::length() const
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

float dotProduct(const Point& lhs, const Point& rhs)
{
	return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

float intersecAngle(const Point& lhs, const Point& rhs)
{
	return acos(dotProduct(lhs, rhs) / lhs.length() / rhs.length());
}

float* Point::toArray(float* array)
{
	array[0] = x;
	array[1] = y;
	array[2] = z;

	return array;
}

Point crossProduct(const Point& lhs, const Point& rhs)
{
	return Point(lhs.y * rhs.z - lhs.z * rhs.y, lhs.z * rhs.x - lhs.x * rhs.z, lhs.x * rhs.y - lhs.y * rhs.x);
}