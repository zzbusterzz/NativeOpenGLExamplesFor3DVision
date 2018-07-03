#include <math.h>
#include <gl/glut.h> // Header File For Glut Operations

#include "Stereo.h"
#include "Point3d.h"
#include "Camera.h"

#define DTOR 0.0174532925 // Degrees to Radians

#define CROSSPROD(p1,p2,p3) \
p3.x = p1.y*p2.z - p1.z*p2.y; \
p3.y = p1.z*p2.x - p1.x*p2.z; \
p3.z = p1.x*p2.y - p1.y*p2.x

Stereo::Stereo(Camera *_camera)
{
	camera = _camera;
}

Stereo::~Stereo(void)
{
}

void Stereo::InitStereo() {
	near_plane = 0.1;
	far_plane = 10000;

	// Clip to avoid extreme stereo
	near_plane = camera->focallength / 5;

	ratio = camera->screenwidth / (double)camera->screenheight;
	radians = DTOR * camera->aperture / 2; // aperature = 50 degrees
	wd2 = near_plane * tan(radians);
	ndfl = near_plane / camera->focallength;

	// Derive the two eye positions
	CROSSPROD(camera->vd, camera->vu, r);
	Normalise(&r);
	r.x *= camera->eyesep / 2.0;
	r.y *= camera->eyesep / 2.0;
	r.z *= camera->eyesep / 2.0;
}

void Stereo::SetupView(int side)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (side == RIGHT)
	{
		// Set the Right viewing frustrum
		left = -ratio * wd2 - 0.5 * camera->eyesep * ndfl;
		right = ratio * wd2 - 0.5 * camera->eyesep * ndfl;
	}
	else if (side == LEFT)
	{
		// Set the Left Viewing Frustrum
		left = -ratio * wd2 + 0.5 * camera->eyesep * ndfl;
		right = ratio * wd2 + 0.5 * camera->eyesep * ndfl;
	}

	top = wd2;
	bottom = -wd2;
	glFrustum(left, right, bottom, top, near_plane, far_plane);

	glMatrixMode(GL_MODELVIEW);

	if (side == RIGHT)
	{
		// Set to Right Buffer
		glDrawBuffer(GL_BACK_RIGHT);
	}
	else if (side == LEFT)
	{
		// Set to Left Buffer
		glDrawBuffer(GL_BACK_LEFT);
	}

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	if (side == RIGHT)
	{
		// Set where right camera is looking
		gluLookAt(camera->vp.x + r.x,
			camera->vp.y + r.y,
			camera->vp.z + r.z,

			camera->vp.x + r.x + camera->vd.x,
			camera->vp.y + r.y + camera->vd.y,
			camera->vp.z + r.z + camera->vd.z,

			camera->vu.x,
			camera->vu.y,
			camera->vu.z);
	}
	else if (side == LEFT)
	{
		// Set where left camera is looking
		gluLookAt(camera->vp.x - r.x,
			camera->vp.y - r.y,
			camera->vp.z - r.z,

			camera->vp.x - r.x + camera->vd.x,
			camera->vp.y - r.y + camera->vd.y,
			camera->vp.z - r.z + camera->vd.z,

			camera->vu.x,
			camera->vu.y,
			camera->vu.z);
	}
}