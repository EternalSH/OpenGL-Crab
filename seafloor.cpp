#include "stdafx.h"
#include "seafloor.h"
#include "textures.h"

#include <GL\glut.h>

#define GKOM_SEAFLOOR_SIZE 160.0f

static void drawBottom();

void drawSeafloor() {	
	drawBottom();

	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glBindTexture(GL_TEXTURE_2D, getTexture(GKOM_TEX_SEASURFACE));
	glutSolidSphere(GKOM_SEAFLOOR_SIZE, 64, 64);

	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, getTexture(GKOM_TEX_SEAFLOOR));
		glTranslatef(0.0f, 1.0f, 0.0f);
		glScalef(1.0f, 0.1f, 0.8f);
		glutSolidSphere(50.0f, 64, 64);
	glPopMatrix();
}

static void drawBottom() {
	glPushMatrix();
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		glBindTexture(GL_TEXTURE_2D, getTexture(GKOM_TEX_SEASURFACE));

		glScalef(GKOM_SEAFLOOR_SIZE, GKOM_SEAFLOOR_SIZE, GKOM_SEAFLOOR_SIZE);

		glBegin(GL_QUADS);
			glNormal3f(0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f);	glVertex3f(-1.0f, 0.0f, -1.0f);		
			glTexCoord2f(0.0f, 1.0f);	glVertex3f(-1.0f, 0.0f,  1.0f);
			glTexCoord2f(1.0f, 1.0f);   glVertex3f( 1.0f, 0.0f,  1.0f);
			glTexCoord2f(1.0f, 0.0f);	glVertex3f( 1.0f, 0.0f, -1.0f);
		glEnd();

	glPopMatrix();
}
