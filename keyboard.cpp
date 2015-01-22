#include "stdafx.h"

static PolarCoordinates cameraDelta;

PolarCoordinates getCameraDelta() {
	return cameraDelta;
}

void onKeyPressed(int key, int xx, int yy) {

	switch (key) {
		case GLUT_KEY_PAGE_UP:
			cameraDelta.r = -0.05f;
			break;

		case GLUT_KEY_PAGE_DOWN:
			cameraDelta.r = 0.05f;
			break;

		case GLUT_KEY_LEFT: 
			cameraDelta.phi = -0.007f; //-1.0f * GKOM_KEYBOARD_STEP_PHI;
			break;

		case GLUT_KEY_RIGHT: 
			cameraDelta.phi = 0.007f; // GKOM_KEYBOARD_STEP_PHI;
			break;

		case GLUT_KEY_UP: 
			cameraDelta.theta = 0.007f; // GKOM_KEYBOARD_STEP_THETA;
			break;

		case GLUT_KEY_DOWN: 
			cameraDelta.theta = -0.007f; //-1.0f * GKOM_KEYBOARD_STEP_THETA;
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
	}
}
