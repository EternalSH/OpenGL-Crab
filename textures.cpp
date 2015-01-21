#include "stdafx.h"
#include "textures.h"
#include "GL\glut.h"
#include "soil.h"

#pragma comment(lib, "SOIL")

static GLuint textures[2];

static void _loadTexture(GLuint id, const char *filepath, bool repeat) {
	textures[id] = SOIL_load_OGL_texture(filepath, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	glBindTexture(GL_TEXTURE_2D, textures[id]);
	if (repeat) {
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	}
	else {
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	}	
}

bool loadTextures() {
	_loadTexture(GKOM_TEX_SEAFLOOR, "textures/sand.jpg", true);
	_loadTexture(GKOM_TEX_SEASURFACE, "textures/water.jpg", true);
	
	// TODO: error checking
	return true;
}

GLuint getTexture(GLuint id) {
	return textures[id];
}
