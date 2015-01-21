#include "stdafx.h"

#include "crab.h"
#include "textures.h"

#define PI 3.14f

void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;
	float ratio = (w * 1.0f) / (h * 1.0f);

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



void drawSeafloor() {
	GLfloat seafloorDiffuse[] = { 0.9f, 0.5f, 0.1f, 1.0f };

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, seafloorDiffuse);
	glScaled(30.0f, 1.0f, 30.0f);
	glutSolidCube(1.0);
	
	glPopMatrix();
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
		0.0f, 10.0f, 0.0f);

	


	// Draw ground
	//glBindTexture(GL_TEXTURE_2D, getTexture(GKOM_TEX_SEAFLOOR));
	
	//glBegin(GL_QUADS);
	//glTexCoord2f(0.0f, 0.0f); glVertex3f(-100.0f, 0.0f, -100.0f);
	//glTexCoord2f(0.0f, 16.0f); glVertex3f(-100.0f, 0.0f, 100.0f);
	//glTexCoord2f(16.0f, 16.0f); glVertex3f(100.0f, 0.0f, 100.0f);
	//glTexCoord2f(16.0f, 0.0f); glVertex3f(100.0f, 0.0f, -100.0f);
	//glEnd();

	// Draw 
	
	drawSeafloor();
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

	// register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);

	glutSpecialFunc(onKeyPressed);
	// here are the new entries
	glutIgnoreKeyRepeat(1);
	glutSpecialUpFunc(onKeyReleased);

	//loadTextures();

	// remove //
	//float ambientLevel = 2.6;
	//GLfloat light_diffuse[] = { 0.1, 0.1, 0.1, 1.0 };
	//GLfloat LightDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	//GLfloat LightPosition2[] = { 0.0f, 20.0f, 0.0f, 1.0f };
	//GLfloat LightPosition1[] = { 10.0f, 35.0f, 10.0f, 1.0f };
	//GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	//GLfloat mat_shininess[] = { 10.0 };

	//GLfloat ambient[] = { ambientLevel, ambientLevel, ambientLevel, 1.0f };
	//glMaterialfv(GL_FRONT, GL_AMBIENT, mat_specular);

	//glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);		// Setup The Ambient Light
	//glLightfv(GL_LIGHT0, GL_DIFFUSE, LightDiffuse);		// Setup The Diffuse Light
	//glLightfv(GL_LIGHT0, GL_POSITION, LightPosition2);	// Position The Light

	//glLightfv(GL_LIGHT1, GL_AMBIENT, ambient);		// Setup The Ambient Light
	//glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);		// Setup The Diffuse Light
	//glLightfv(GL_LIGHT1, GL_POSITION, LightPosition1);	// Position The Light

	//glEnable(GL_LIGHT0);
	//glEnable(GL_LIGHT1);

	//glEnable(GL_LIGHTING);
	// remove //

	GLfloat mat_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_position[] = { 0.0, 0.0, 10.0, 1.0 };
	GLfloat lm_ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, 50.0);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lm_ambient);

	glShadeModel(GL_SMOOTH);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);

	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);

	// OpenGL init
	glClearColor(0.0, 0.0, 0.0, 0.0);
	//glEnable(GL_TEXTURE_2D);									
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);							
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}