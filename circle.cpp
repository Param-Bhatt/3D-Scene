#include "variables.cpp"
/*A function to draw a circle with a radius r and centre (h,k)*/
void draw_circle(GLfloat h, GLfloat k, GLfloat r)
{
	float x, y;
	glBegin(GL_LINES);	/*start drawing lines between every two consecutive coordinates*/
	for (int i = 0; i < 180; i++)	/*draw half of the circle, the other half is drawn by symmetry*/
	{
		x = r * cos(i) - h;		/*h is the x-coordinate of the center */
		y = r * sin(i) + k;		/*k is the y-coordinate of the center*/
		glVertex3f(x + k, 0, y - h);

		x = r * cos(i + 0.1) - h;
		y = r * sin(i + 0.1) + k;
		glVertex3f(x + k, 0, y - h);
	}
	glEnd();
}