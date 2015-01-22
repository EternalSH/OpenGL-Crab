#include "stdafx.h"
#include "textures.h"

#include <stdio.h>
#include <GL\glut.h>
#include <soil.h>

#pragma comment(lib, "SOIL")

static GLuint textures[6];

static void _loadTexture(GLuint id, const char *filepath) {
	textures[id] = SOIL_load_OGL_texture(filepath, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	glBindTexture(GL_TEXTURE_2D, textures[id]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
}

bool loadTextures() {
	_loadTexture(GKOM_TEX_SEAFLOOR, "textures/sand.jpg");
	_loadTexture(GKOM_TEX_SEASURFACE, "textures/water.jpg");
	_loadTexture(GKOM_TEX_CRAB_EYE,  "textures/crab-eye.png");
	_loadTexture(GKOM_TEX_CRAB_PUPIL, "textures/crab-pupil.png");
	_loadTexture(GKOM_TEX_CRAB_ARM,  "textures/crab-arm.png");
	_loadTexture(GKOM_TEX_CRAB_BODY, "textures/crab-body.png");
	_loadTexture(GKOM_TEX_CRAB_GRIP, "textures/crab-grip.png");
	_loadTexture(GKOM_TEX_CRAB_LEG,  "textures/crab-leg.png");

	printf("Textures loaded.\n");

	return true;
}

GLuint getTexture(GLuint id) {
	return textures[id];
}
