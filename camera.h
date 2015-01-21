#pragma once
#include "geometry.h"

#define GKOM_CAMERA_MIN_R		60.0f
#define GKOM_CAMERA_MAX_R		120.0f
#define GKOM_CAMERA_MIN_THETA	0.0f
#define GKOM_CAMERA_MAX_THETA	1.57f
#define GKOM_CAMERA_MIN_PHI		-3.14f
#define GKOM_CAMERA_MAX_PHI		3.14f

extern void initCameraPosition();
extern StandardCoordinates updateCameraPosition(PolarCoordinates delta);
