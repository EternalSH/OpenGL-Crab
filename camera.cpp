#include "stdafx.h"
#include "camera.h"

#include <math.h>

static PolarCoordinates cameraPosition;

static float minMaxBound(float min, float x, float max) {
	return fmax(min, fmin(max, x));
}

void initCameraPosition() {
	cameraPosition.r = 80.0f;
	cameraPosition.phi = 0.0f;
	cameraPosition.theta = 0.785f;
}

StandardCoordinates updateCameraPosition(PolarCoordinates delta) {
	cameraPosition.r = minMaxBound(GKOM_CAMERA_MIN_R, (cameraPosition.r + delta.r), GKOM_CAMERA_MAX_R);
	cameraPosition.phi = minMaxBound(GKOM_CAMERA_MIN_PHI, (cameraPosition.phi + delta.phi), GKOM_CAMERA_MAX_PHI);
	cameraPosition.theta = minMaxBound(GKOM_CAMERA_MIN_THETA, (cameraPosition.theta + delta.theta), GKOM_CAMERA_MAX_THETA);

	float rCast = cameraPosition.r * cos(cameraPosition.theta);

	StandardCoordinates xyzCameraPosition;
	xyzCameraPosition.x = rCast * sin(cameraPosition.phi);
	xyzCameraPosition.y = cameraPosition.r * sin(cameraPosition.theta);
	xyzCameraPosition.z = rCast * cos(cameraPosition.phi);
	return xyzCameraPosition;
}