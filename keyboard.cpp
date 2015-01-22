#include "stdafx.h"
#include "main.h"
#include "geometry.h"
#include <GL\glut.h>

static PolarCoordinates cameraDelta;
static GLfloat lightDelta;

PolarCoordinates getCameraDelta() {
	return cameraDelta;
}

GLfloat getLightDelta() {
	return lightDelta;
}

void onKeyPressed(int key, int xx, int yy) {

	switch (key) {
		case GLUT_KEY_HOME:
			lightDelta = -0.025f;
			break;

		case GLUT_KEY_END:
			lightDelta = 0.025f;
			break;

		case GLUT_KEY_PAGE_UP:
			cameraDelta.r = -0.2f;
			break;

		case GLUT_KEY_PAGE_DOWN:
			cameraDelta.r = 0.2f;
			break;

		case GLUT_KEY_LEFT: 
			cameraDelta.phi = -0.007f; 
			break;

		case GLUT_KEY_RIGHT: 
			cameraDelta.phi = 0.007f; 
			break;

		case GLUT_KEY_UP: 
			cameraDelta.theta = 0.007f;
			break;

		case GLUT_KEY_DOWN: 
			cameraDelta.theta = -0.007f; 
			break;
	}
}

void onKeyReleased(int key, int x, int y) {

	switch (key) {

		case GLUT_KEY_PAGE_UP:
		case GLUT_KEY_PAGE_DOWN:
			cameraDelta.r = 0.0f;
			break;

		case GLUT_KEY_LEFT:
		case GLUT_KEY_RIGHT: 
			cameraDelta.phi = 0.0f;
			break;

		case GLUT_KEY_UP:
		case GLUT_KEY_DOWN: 
			cameraDelta.theta = 0.0f; 
			break;

		case GLUT_KEY_HOME:
		case GLUT_KEY_END:
			lightDelta = 0.0f;
			break;
	}
}
