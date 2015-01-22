#pragma once

typedef struct _standard_coordinates {
	float x;
	float y;
	float z;
} StandardCoordinates;

typedef struct _polar_coordinates {
	float r;
	float phi;
	float theta;
} PolarCoordinates;

extern void drawHalfSphere(const GLfloat r, int segments);
