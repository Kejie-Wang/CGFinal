#ifndef _POINT_H_
#define _POINT_H_

class Point
{
public:
	float x, y, z;
	Point();
	virtual ~Point();
	Point(float x, float y, float z);
	float length() const;
	float* toArray(float* array);
	friend Point operator+(const Point& lhs, const Point& rhs);
	friend Point operator-(const Point& lhs, const Point& rhs);
	friend Point operator*(const float& lhs, const Point& rhs);
	friend Point operator*(const Point& lhs, const float& rhs);
	friend float intersecAngle(const Point& lhs, const Point& rhs);
	friend float dotProduct(const Point& lhs, const Point& rhs);
	friend Point crossProduct(const Point& lhs, const Point& rhs);
};

Point operator+(const Point& lhs, const Point& rhs);
Point operator-(const Point& lhs, const Point& rhs);
Point operator*(const float& lhs, const Point& rhs);
Point operator*(const Point& lhs, const float& rhs);
float intersecAngle(const Point& lhs, const Point& rhs);
float dotProduct(const Point& lhs, const Point& rhs);
Point crossProduct(const Point& lhs, const Point& rhs);

#endif //_POINT_H_