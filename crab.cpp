#include "stdafx.h"
#include "crab.h"

#include <GL\glut.h>

static void drawCrabBody();
static void drawCrabGrip();
static void drawCrabLeg();
static void drawCrabLegs();

void drawCrab() {

	glPushMatrix();
	
		drawCrabBody();

		glPushMatrix();
			glTranslatef(-18.0f, 0.0f, 0.0f);
			drawCrabLegs();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(18.0f, 0.0f, 0.0f);
			glRotatef(180, 0.0f, 1.0f, 0.0f);
			drawCrabLegs();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-5.0f, 8.0f, 20.0f);
			glRotatef(-160.0f, 0.0f, 1.0f, 0.0f);

			glPushMatrix();
				glPushMatrix();
					glTranslatef(0.8f, 0.0f, 9.5f);
					glRotatef(185.0f, 0.0f, 1.0f, 0.0f);

					glPushMatrix();
						glTranslatef(0.0f, 0.0f, 6.5f);
						GLUquadricObj *diskQuadratic2 = gluNewQuadric();
						gluDisk(diskQuadratic2, 0.0f, 1.0f, 64, 4);
						gluDeleteQuadric(diskQuadratic2);
					glPopMatrix();

					glPushMatrix();
						GLUquadricObj *cylinderQuadratic1 = gluNewQuadric();
						gluCylinder(cylinderQuadratic1, 0.8f, 1.0f, 6.5f, 64, 64);
						gluDeleteQuadric(cylinderQuadratic1);
					glPopMatrix();

					glTranslatef(0.2f, 0.0f, 0.1f);
					glRotatef(100.0f, 0.0f, 1.0f, 0.0f);

					glPushMatrix();
						glutSolidSphere(1.1f, 64, 64);
					glPopMatrix();

					glPushMatrix();
						GLUquadricObj *cylinderQuadratic2 = gluNewQuadric();
						gluCylinder(cylinderQuadratic2, 1.1f, 0.7f, 10.5f, 64, 64);
						gluDeleteQuadric(cylinderQuadratic2);
						glPopMatrix();
					glPopMatrix();
				glPopMatrix();

				glTranslatef(0.0f, -1.15f, 0.0f);
				glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
				glScalef(0.5f, 0.5f, 0.5f);
				drawCrabGrip();
			glPopMatrix();

			
		glPopMatrix();


	
	glPopMatrix();
}


static void drawCrabBody() {
	glPushMatrix();
		glScalef(0.95f, 1.0f, 1.2f);
		glPushMatrix();
			glTranslatef(0.0f, 6.0f, 0.0f);
			GLfloat torus_diffuse[] = { 0.7f, 0.4f, 0.2f, 0.4f };
			glMaterialfv(GL_FRONT, GL_AMBIENT, torus_diffuse);
			glScalef(1.0f, 0.25f, 1.0f);
			glutSolidSphere(9.0f, 64, 64);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0.0f, 9.0f, 0.0f);
			glScalef(1.0f, 0.4f, 1.0f);
			glutSolidSphere(10.0f, 64, 64);
		glPopMatrix();
		glPushMatrix();			
			glTranslatef(0.0f, 8.5f, 0.0f);
			glRotatef(90, 1.0f, 0.0f, 0.0f);
			GLUquadricObj *cylinderQuadratic1 = gluNewQuadric();
			gluCylinder(cylinderQuadratic1, 10.0f, 9.0f, 2.7f, 64, 64);
			gluDeleteQuadric(cylinderQuadratic1);
		glPopMatrix();
	glPopMatrix();
}

static void drawCrabGrip() {
	glPushMatrix();
		glScalef(1.0f, 1.0f, 0.7f);
		glRotatef(45.0f, 0.0f, 1.0f, 0.0f);
		glScalef(0.7f, 0.3f, 0.7f);

		GLdouble cuttingPlaneX[4] = { 1.0, 0.0, 0.0, 0.0 };
		glClipPlane(GL_CLIP_PLANE0, cuttingPlaneX);

		glEnable(GL_CLIP_PLANE0);
			glPushMatrix();
				glTranslatef(0.0f, 10.0f, 0.0f);
				glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
				glutSolidSphere(12.0f, 64, 64);
				glScalef(1.0f, 0.2f, 1.0f);
				GLUquadricObj *sphereQuadratic1 = gluNewQuadric();
				gluQuadricOrientation(sphereQuadratic1, GLU_INSIDE);
				gluSphere(sphereQuadratic1, 12.0, 64, 64);
				gluDeleteQuadric(sphereQuadratic1);
			glPopMatrix();
		glDisable(GL_CLIP_PLANE0);

		glTranslatef(0.0f, 10.0f, 0.0f);

		float animationAngle = 30.0f * sin(frame * 0.01f);
		glRotatef(animationAngle, 0.0f, 1.0f, 0.0f);

		GLdouble cuttingPlaneY[4] = { 0.0, 0.0, 1.0, 0.0 };
		glClipPlane(GL_CLIP_PLANE1, cuttingPlaneY);

		glEnable(GL_CLIP_PLANE1);
			glPushMatrix();
				glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
				glutSolidSphere(11.8f, 64, 64);
				glScalef(1.0f, 1.0f, 0.2f);
				GLUquadricObj *sphereQuadratic2 = gluNewQuadric();
				gluQuadricOrientation(sphereQuadratic2, GLU_INSIDE);
				gluSphere(sphereQuadratic2, 11.8, 64, 64);
				gluDeleteQuadric(sphereQuadratic2);
			glPopMatrix();
		glDisable(GL_CLIP_PLANE1);
	glPopMatrix();
}

static void drawCrabLegs() {
	drawCrabLeg();

	glPushMatrix();		
		glRotatef(20, 0.0f, 1.0f, 0.0f);
		glTranslatef(-0.5f, 0.0f, 7.0f);
		drawCrabLeg();
	glPopMatrix();

	glPushMatrix();
		glRotatef(-20, 0.0f, 1.0f, 0.0f);
		glTranslatef(0.5f, 0.0f, -7.0f);
		drawCrabLeg();
	glPopMatrix();
}

static void drawCrabLeg() {
	glPushMatrix();
	glScalef(1.0f, 1.0f, 0.6f);
	glTranslatef(0.0f, 10.6f, 0.0f);
	glRotatef(90, 1.0f, 0.0f, 0.0f);

	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 6.5f);
	GLUquadricObj *diskQuadratic2 = gluNewQuadric();
	gluDisk(diskQuadratic2, 0.0f, 1.0f, 64, 4);
	gluDeleteQuadric(diskQuadratic2);
	glPopMatrix();

	glPushMatrix();
	GLUquadricObj *cylinderQuadratic1 = gluNewQuadric();
	gluCylinder(cylinderQuadratic1, 0.8f, 1.0f, 6.5f, 64, 64);
	gluDeleteQuadric(cylinderQuadratic1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 6.3f);
	glRotatef(15, 0.0f, 1.0f, 0.0f);
	glutSolidCone(0.9f, 4.0f, 64, 64);
	glPopMatrix();

	glTranslatef(0.2f, 0.0f, 0.1f);
	glRotatef(70, 0.0f, 1.0f, 0.0f);

	glPushMatrix();
	glutSolidSphere(1.1f, 64, 64);
	glPopMatrix();

	glPushMatrix();
	GLUquadricObj *cylinderQuadratic2 = gluNewQuadric();
	gluCylinder(cylinderQuadratic2, 1.1f, 0.7f, 10.5f, 64, 64);
	gluDeleteQuadric(cylinderQuadratic2);
	glPopMatrix();
	glPopMatrix();
}

