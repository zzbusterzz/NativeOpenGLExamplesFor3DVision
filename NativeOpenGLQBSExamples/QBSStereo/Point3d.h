#pragma once

class Point3d
{
public:
	Point3d(void);
	Point3d(double, double, double);
	~Point3d(void);

	void SetPointLocation(double, double, double);

public:
	double x, y, z;
};

void Normalise(Point3d *p);