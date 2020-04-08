#include "variables.cpp"		
void planet(GLfloat radius, GLfloat orbrad, GLint i, GLfloat angspeed, GLfloat r, GLfloat g, GLfloat b)
{
	glLoadIdentity();
	gluLookAt(x, 1.0f, z, x + lx, 1.0f, z + lz, 0.0f, 1.0f, 0.0f);
	glScalef(zoom, zoom, zoom);
	glColor3f(r, g, b);
	glTranslatef(0.f, 1.f, 0.f);
	glRotatef(10, 1, 0, 0);
	draw_circle(0, 0, orbrad);
	glRotatef(anglep[i], 0.0f, 1.0f, 0.0f);
	anglep[i] += angspeed;
	glTranslatef(orbrad, 0.f, 0.f);
	glutSolidSphere(radius, 100, 100);
}