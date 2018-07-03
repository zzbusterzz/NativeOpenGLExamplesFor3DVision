#pragma once

#include "Point3d.h"
#include "Camera.h"

class Stereo
{
public:
	Stereo(Camera *camera);
	~Stereo(void);

	void InitStereo(void);
	void SetupView(int side);

public:
	Camera * camera;
	Point3d r;
	double ratio, radians, wd2, ndfl;
	double left, right, top, bottom, near_plane, far_plane;

	enum {
		RIGHT = 0,
		LEFT = 1
	};
};
