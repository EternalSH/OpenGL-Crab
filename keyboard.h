#pragma once
#include "geometry.h"
#include <GL\glut.h>

extern PolarCoordinates getCameraDelta();
extern GLfloat getLightDelta();
extern void onKeyPressed(int key, int x, int y);
extern void onKeyReleased(int key, int x, int y);
