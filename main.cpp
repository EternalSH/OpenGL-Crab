#include "stdafx.h"


void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;
	float ratio = w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

void drawSnowMan() {

	glColor3f(1.0f, 1.0f, 1.0f);

	// Draw Body

	glTranslatef(0.0f, 0.75f, 0.0f);
	glutSolidSphere(0.75f, 20, 20);

	// Draw Head
	glTranslatef(0.0f, 1.0f, 0.0f);
	glutSolidSphere(0.25f, 20, 20);

	// Draw Eyes
	glPushMatrix();
	glColor3f(0.0f, 0.0f, 0.0f);
	glTranslatef(0.05f, 0.10f, 0.18f);
	glutSolidSphere(0.05f, 10, 10);
	glTranslatef(-0.1f, 0.0f, 0.0f);
	glutSolidSphere(0.05f, 10, 10);
	glPopMatrix();

	// Draw Nose
	glColor3f(1.0f, 0.5f, 0.5f);
	glRotatef(0.0f, 1.0f, 0.0f, 0.0f);
	glutSolidCone(0.08f, 0.5f, 10, 2);
}

void renderScene(void) {

	PolarCoordinates cameraDelta = getCameraDelta();

	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Get camera position
	StandardCoordinates cameraPosition = updateCameraPosition(cameraDelta);
	printf("Camera position %f %f %f \n", cameraPosition.x, cameraPosition.y, cameraPosition.z);

	// Load empty tranformations matrix
	glLoadIdentity();
	// Set the camera

	gluLookAt(
		cameraPosition.x, cameraPosition.y, cameraPosition.z,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f);

	// Draw ground

	glColor3f(0.9f, 0.9f, 0.9f);
	glBegin(GL_QUADS);
	glVertex3f(-100.0f, 0.0f, -100.0f);
	glVertex3f(-100.0f, 0.0f, 100.0f);
	glVertex3f(100.0f, 0.0f, 100.0f);
	glVertex3f(100.0f, 0.0f, -100.0f);
	glEnd();

	// Draw 36 SnowMen

	for (int i = -3; i < 3; i++)
	for (int j = -3; j < 3; j++) {
		glPushMatrix();
		glTranslatef(i*10.0, 0, j * 10.0);
		drawSnowMan();
		glPopMatrix();
	}

	glutSwapBuffers();
}




int main(int argc, char **argv) {

	initCameraPosition();

	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(320, 320);
	glutCreateWindow("Lighthouse3D - GLUT Tutorial");

	// register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);

	glutSpecialFunc(onKeyPressed);
	// here are the new entries
	glutIgnoreKeyRepeat(1);
	glutSpecialUpFunc(onKeyReleased);

	// OpenGL init
	glEnable(GL_DEPTH_TEST);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}