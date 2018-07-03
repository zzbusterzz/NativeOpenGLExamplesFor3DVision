#include "Point3d.h"
#include <math.h>

Point3d::Point3d(void)
{
	Point3d(0.0, 0.0, 0.0);
}

Point3d::Point3d(double _x, double _y, double _z)
{
	x = _x;
	y = _y;
	z = _z;
}

Point3d::~Point3d(void) {}

void Point3d::SetPointLocation(double _x, double _y, double _z)
{
	x = _x;
	y = _y;
	z = _z;
}

void Normalise(Point3d *p)
{
	double length;

	length = sqrt(p->x * p->x + p->y * p->y + p->z * p->z);
	if (length != 0) {
		p->x /= length;
		p->y /= length;
		p->z /= length;
	}
	else {
		p->x = 0;
		p->y = 0;
		p->z = 0;
	}
}