#pragma once
#include<GL\glut.h>

#define GKOM_TEX_SEAFLOOR		0
#define GKOM_TEX_SEASURFACE		1
#define GKOM_TEX_CRAB_BODY	11
#define GKOM_TEX_CRAB_ARM	12
#define GKOM_TEX_CRAB_LEG	13
#define GKOM_TEX_CRAB_GRIP	14

extern bool loadTextures();

extern GLuint getTexture(GLuint id);
