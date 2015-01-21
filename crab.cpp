#include "stdafx.h"
#include "crab.h"

#include <GL\glut.h>

static void drawCrabBody();
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

