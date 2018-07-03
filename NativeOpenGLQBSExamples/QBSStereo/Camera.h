#pragma once

#include "Point3d.h"

class Camera
{
public:
	Camera();
	Camera(Point3d, Point3d, Point3d, double, double, double, int, int);
	~Camera(void);

	void CameraHome(int mode);

public:
	Point3d vp; /* View position */
	Point3d vd; /* View direction vector */
	Point3d vu; /* View up direction */
	double focallength; /* Focal Length along vd */
	double aperture; /* Camera aperture */
	double eyesep; /* Eye separation */
	int screenwidth, screenheight;
};
