#include "stdafx.h"
#include "camera.h"
#include "crab.h"
#include "geometry.h"
#include "keyboard.h"
#include "main.h"
#include "seafloor.h"
#include "textures.h"

#include <GL\glut.h>
#include <math.h>

GLfloat lightStrength = 0.5f;
long frame = 0;

void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0) {
		h = 1;
	}		

	float ratio = (w * 1.0f) / (h * 1.0f);

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45.0f, ratio, 0.1f, 300.0f);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

void renderScene(void) {
	frame = (frame + 1) % 20000;
	PolarCoordinates cameraDelta = getCameraDelta();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	StandardCoordinates cameraPosition = updateCameraPosition(cameraDelta);
	glLoadIdentity();

	gluLookAt(
		cameraPosition.x, cameraPosition.y, cameraPosition.z,
		0.0f, 0.0f, 0.0f,
		0.0f, 10.0f, 0.0f);

	lightStrength = fmax(0.0f, fmin(1.0f, lightStrength + getLightDelta()));

	GLfloat light_position0[] = { 0.0f, 50.0f, 0.0f, lightStrength };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position0);

	GLfloat light_position1[] = { 0.0f, 1.0f, 20.0f, lightStrength / 2.0f };
	glLightfv(GL_LIGHT1, GL_POSITION, light_position0);

	drawSeafloor();	
	glTranslatef(0.0f, 4.0f, 0.0f);
	drawCrab();	

	glutSwapBuffers();
}

int main(int argc, char **argv) {

	initCameraPosition();

	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("OpenGL project");

	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);

	glutSpecialFunc(onKeyPressed);
	glutIgnoreKeyRepeat(1);
	glutSpecialUpFunc(onKeyReleased);

	loadTextures();

	GLfloat mat_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };	
	GLfloat lm_ambient[] = { 0.1f, 0.1f, 0.1f, 0.05f };		
	
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, 5.0);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lm_ambient);

	glShadeModel(GL_SMOOTH);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_NORMALIZE);

	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_TEXTURE_2D);									
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);							
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}