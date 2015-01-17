#include "stdafx.h"

static PolarCoordinates cameraPosition;

void initCameraPosition() {
	cameraPosition.r = 20.0f;
	cameraPosition.phi = 0.0f;
	cameraPosition.theta = 0.785f;
}

StandardCoordinates updateCameraPosition(PolarCoordinates delta) {
	cameraPosition.r += delta.r;
	cameraPosition.phi += delta.phi;
	cameraPosition.theta += delta.theta;

	float rCast = cameraPosition.r * cos(cameraPosition.theta);

	StandardCoordinates xyzCameraPosition;
	xyzCameraPosition.x = rCast * sin(cameraPosition.phi);
	xyzCameraPosition.y = cameraPosition.r * sin(cameraPosition.theta);
	xyzCameraPosition.z = rCast * cos(cameraPosition.phi);
	return xyzCameraPosition;
}