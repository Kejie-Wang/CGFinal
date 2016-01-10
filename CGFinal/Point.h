#ifndef _POINT_H_
#define _POINT_H_

class Point
{
public:
	float x, y, z;
	Point();
	virtual ~Point();
	Point(float x, float y, float z);
	float length();
	friend Point operator+(const Point& lhs, const Point& rhs);
	friend Point operator-(const Point& lhs, const Point& rhs);
	friend Point operator*(const float& lhs, const Point& rhs);
	friend Point operator*(const Point& lhs, const float& rhs);
};

Point operator+(const Point& lhs, const Point& rhs);
Point operator-(const Point& lhs, const Point& rhs);
Point operator*(const float& lhs, const Point& rhs);
Point operator*(const Point& lhs, const float& rhs);

#endif //_POINT_H_