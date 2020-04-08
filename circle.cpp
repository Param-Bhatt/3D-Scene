#include "variables.cpp"

void draw_circle(GLfloat h, GLfloat k, GLfloat r)
{
	float x, y;
	glBegin(GL_LINES);
	for (int i = 0; i < 180; i++)
	{
		x = r * cos(i) - h;
		y = r * sin(i) + k;
		glVertex3f(x + k, 0, y - h);

		x = r * cos(i + 0.1) - h;
		y = r * sin(i + 0.1) + k;
		glVertex3f(x + k, 0, y - h);
	}
	glEnd();
}