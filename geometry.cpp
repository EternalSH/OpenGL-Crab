#include "stdafx.h"
#include "geometry.h"
#include <GL\glut.h>
#include <math.h>

#define M_PI 3.14f
#define _V(f, v, i)	f(v[3 * (i) + 0], v[3 * (i) + 1], v[3 * (i) + 2])

void drawHalfSphere(const GLfloat r, int segments) {
	int i, j;
	GLfloat *v = new GLfloat[segments * segments * 3]; //[segments * segments][3];

	for (i = 0; i < segments; ++ i) {
		for (j = 0; j < segments; ++ j) {
			v[3 * (i * segments + j) + 0] = (float) r * cosf(j * 2.0f * M_PI / segments) * cosf(i * M_PI / (2.0f * segments));
			v[3 * (i * segments + j) + 1] = (float) r * sinf(i * M_PI / (2.0f * segments));
			v[3 * (i * segments + j) + 2] = (float) r * sinf(j * 2.0f * M_PI / segments) * cosf(i * M_PI / (2.0f * segments));
		}
	}

	glBegin(GL_QUADS);

	for (i = 0; i < segments - 1; ++ i) {
		for (j = 0; j < segments; ++ j) {

			_V(glVertex3f, v, i * segments + j);
			_V(glVertex3f, v, i * segments + (j + 1) % segments);
			_V(glVertex3f, v, (i + 1) * segments + (j + 1) % segments);
			_V(glVertex3f, v, (i + 1) * segments + j);

			//glVertex3f(_V30(v, i * segments + j), _V31(v, i * segments + j), _V32(v, i * segments + j));

			//glVertex3fv(v[i * segments + j]);
			//glVertex3fv(v[i * segments + (j + 1) % segments]);
			//glVertex3fv(v[(i + 1) * segments + (j + 1) % segments]);
			//glVertex3fv(v[(i + 1) * segments + j]);
		}
	}

	glEnd();
}