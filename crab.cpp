#include "stdafx.h"
#include "crab.h"
#include "main.h"
#include "textures.h"

#include <GL\glut.h>
#include <math.h>

static GLfloat crabArmsColour[4] = { 1.00f, 0.73f, 0.23f, 1.0 };
static GLfloat crabBodyColour[4] = { 0.88f, 0.59f, 0.06f, 1.0 };
static GLfloat crabGripColour[4] = { 0.85f, 0.38f, 0.15f, 1.0 };
static GLfloat crabLegsColour[4] = { 1.00f, 0.73f, 0.23f, 1.0 };

static void drawCrabArm();
static void drawCrabBody();
static void drawEye();
static void drawEyes();
static void drawCrabGrip();
static void drawCrabLeg();
static void drawCrabLegs();

void drawCrab() {

	glPushMatrix();

		drawCrabBody();
		
		glPushMatrix();
			glTranslatef(0.0f, 10.0f, 13.0f);
			drawEyes();
		glPopMatrix();

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
			drawCrabArm();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(5.0f, 8.0f, 20.0f);
			glRotatef(160.0f, 0.0f, 1.0f, 0.0f);
			glRotatef(180.0f, 0.0f, 0.0f, 1.0f);
			drawCrabArm();
		glPopMatrix();	
	glPopMatrix();
}

static void drawCrabArm() {
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, crabArmsColour);
	glBindTexture(GL_TEXTURE_2D, getTexture(GKOM_TEX_CRAB_ARM));

	glPushMatrix();
		glPushMatrix();
			glTranslatef(0.8f, 0.0f, 9.5f);
			glRotatef(185.0f, 0.0f, 1.0f, 0.0f);

			glPushMatrix();
				glTranslatef(0.0f, 0.0f, 6.5f);
				GLUquadricObj *diskQuadratic2 = gluNewQuadric();
				gluQuadricNormals(diskQuadratic2, GLU_SMOOTH);
				gluQuadricTexture(diskQuadratic2, GLU_TRUE);
				gluDisk(diskQuadratic2, 0.0f, 1.0f, 64, 4);
				gluDeleteQuadric(diskQuadratic2);
			glPopMatrix();

			glPushMatrix();
				GLUquadricObj *cylinderQuadratic1 = gluNewQuadric();
				gluCylinder(cylinderQuadratic1, 0.8f, 1.0f, 6.5f, 64, 64);
				gluQuadricNormals(cylinderQuadratic1, GLU_SMOOTH);
				gluQuadricTexture(cylinderQuadratic1, GLU_TRUE);
				gluDeleteQuadric(cylinderQuadratic1);
			glPopMatrix();

			glTranslatef(0.2f, 0.0f, 0.1f);
			glRotatef(100.0f, 0.0f, 1.0f, 0.0f);

			glPushMatrix();
				glutSolidSphere(1.1f, 64, 64);
			glPopMatrix();

			glPushMatrix();
				GLUquadricObj *cylinderQuadratic2 = gluNewQuadric();
				gluQuadricNormals(cylinderQuadratic2, GLU_SMOOTH);
				gluQuadricTexture(cylinderQuadratic2, GLU_TRUE);
				gluCylinder(cylinderQuadratic2, 1.1f, 0.7f, 10.5f, 64, 64);
				gluDeleteQuadric(cylinderQuadratic2);
			glPopMatrix();
		glPopMatrix();
				
		glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
		glScalef(0.5f, 0.5f, 0.5f);
		glTranslatef(0.0f, -3.0f, 0.0f);
		drawCrabGrip();
	glPopMatrix();
}

static void drawCrabBody() {
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, crabBodyColour);
	glBindTexture(GL_TEXTURE_2D, getTexture(GKOM_TEX_CRAB_BODY));

	glPushMatrix();
		glScalef(0.95f, 1.0f, 1.2f);
		glPushMatrix();
			glTranslatef(0.0f, 6.0f, 0.0f);
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
			gluQuadricNormals(cylinderQuadratic1, GLU_SMOOTH);
			gluQuadricTexture(cylinderQuadratic1, GLU_TRUE);
			gluCylinder(cylinderQuadratic1, 10.0f, 9.0f, 2.7f, 64, 64);
			gluDeleteQuadric(cylinderQuadratic1);
		glPopMatrix();
	glPopMatrix();
}

static void drawEye() {
	glPushMatrix();
		glRotatef(-18.0f, 1.0f, 0.0f, 0.0f);

		glMaterialfv(GL_FRONT, GL_DIFFUSE, crabBodyColour);
		glBindTexture(GL_TEXTURE_2D, getTexture(GKOM_TEX_CRAB_BODY));
		glutSolidSphere(2.0f, 32, 32);

		glBindTexture(GL_TEXTURE_2D, getTexture(GKOM_TEX_CRAB_EYE));
		glTranslatef(0.0f, 0.0f, 0.4f);
		glutSolidSphere(1.8, 32, 32);

		glBindTexture(GL_TEXTURE_2D, getTexture(GKOM_TEX_CRAB_PUPIL));
		glTranslatef(0.0f, 0.0f, 1.4f);
		glScalef(1.0f, 1.0f, 0.5f);
		glutSolidSphere(1.0f, 32, 32);
	glPopMatrix();
}

static void drawEyes() {
	glPushMatrix();
		glTranslatef(-2.25f, 0.0f, 0.0f);
		drawEye();
		glTranslatef(5.0f, 0.0f, 0.0f);
		drawEye();
	glPopMatrix();
}

static void drawCrabGrip() {
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, crabGripColour);
	glBindTexture(GL_TEXTURE_2D, getTexture(GKOM_TEX_CRAB_GRIP));

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
				gluQuadricNormals(sphereQuadratic1, GLU_SMOOTH);
				gluQuadricTexture(sphereQuadratic1, GLU_TRUE);
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
				gluQuadricNormals(sphereQuadratic2, GLU_SMOOTH);
				gluQuadricTexture(sphereQuadratic2, GLU_TRUE);
				gluSphere(sphereQuadratic2, 11.8, 64, 64);
				gluDeleteQuadric(sphereQuadratic2);
			glPopMatrix();
		glDisable(GL_CLIP_PLANE1);
	glPopMatrix();
}

static void drawCrabLegs() {
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, crabLegsColour);

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
		glBindTexture(GL_TEXTURE_2D, getTexture(GKOM_TEX_CRAB_LEG));

		glScalef(1.0f, 1.0f, 0.6f);
			glTranslatef(0.0f, 10.6f, 0.0f);
		glRotatef(90, 1.0f, 0.0f, 0.0f);

		glPushMatrix();
			glTranslatef(0.0f, 0.0f, 6.5f);
			GLUquadricObj *diskQuadratic2 = gluNewQuadric();
			gluQuadricNormals(diskQuadratic2, GLU_SMOOTH);
			gluQuadricTexture(diskQuadratic2, GLU_TRUE);
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
