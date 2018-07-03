#include "Camera.h"

Camera::Camera() {}

Camera::Camera(Point3d _vp, Point3d _vd, Point3d _vu, double _focallength, double _aperture, double _eyesep, int _screenwidth, int _screenheight)
{
	vp = _vp;
	vd = _vd;
	vu = _vu;
	focallength = _focallength;
	aperture = _aperture;
	eyesep = _eyesep;
	screenwidth = _screenwidth;
	screenheight = _screenheight;
}

Camera::~Camera(void) {}

/*
Move the camera to the home position
*/
void Camera::CameraHome(int mode)
{
	aperture = 50;
	focallength = 70;
	eyesep = focallength / 20;

	if (mode == 0)
	{
		// Camera position
		vp = Point3d(0, 0, focallength);

		// Camera view direction
		vd = Point3d(0, 0, -1);
	}
	else if (mode == 1)
	{
		/* Special camera position so the beam crosses the view */
		// Camera position
		vp = Point3d(39, 53, 22);

		// Camera view direction
		vd = Point3d(-vp.x, -vp.y, -vp.z);
	}

	// Up vector
	vu = Point3d(0, 1, 0);
}