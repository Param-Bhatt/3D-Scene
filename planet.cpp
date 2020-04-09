#include "variables.cpp"	
/*To draw a planet with a fixed radius, orbit , angular speed and of a specific rgb colour*/
void planet(GLfloat radius, GLfloat orbrad, GLint i, GLfloat angspeed, GLfloat r, GLfloat g, GLfloat b)
{
	if (i == 7)/*if planet number == 7 ( planet is Neptune )*/
	{
		glLoadIdentity();	/*clearing all previous buffers*/
		glRotatef(roll, 0.0f, 0.0f, 1.0f);
		glRotatef(pitch, 1.0f, 0.0f, 0.0f);
		gluLookAt(x, y, z, x + lx, y, z + lz, 0.0f, 1.0f, 0.0f);	/*set the camera to look at the points x+lx...*/
		glScalef(zoom, zoom, zoom);
		glColor3f(r, g, b);
		glTranslatef(0.f, 1.f, 0.f);	/*translate our pen to the y-axis*/
		glRotatef(10, 1, 0, 0);
		draw_circle(0, 0, orbrad);		/*draw the orbit of our planet , on which path it will follow and revolve
										around the sun*/
		glRotatef(anglep[i], 0.0f, 1.0f, 0.0f);
		anglep[i] += angspeed;		/*change the speed accordingly. each planet will have different speed as they
									are at different distances from the sun*/
		glTranslatef(orbrad, 0.f, 0.f);
		glutSolidSphere(radius, 100, 100);
		glTranslatef(-orbrad, 0.f, 0.f);
		glRotatef(anglep[2], 0.0f, 1.0f, 0.0f);
		glTranslatef(orbrad + 10, 0.f, 0.f);
		return;
	}
	glLoadIdentity();
	glRotatef(roll, 0.0f, 0.0f, 1.0f);
	glRotatef(pitch, 1.0f, 0.0f, 0.0f);
	gluLookAt(x, y, z, x + lx, y, z + lz, 0.0f, 1.0f, 0.0f);
	glScalef(zoom, zoom, zoom);
	glColor3f(r, g, b);
	glTranslatef(0.f, 1.f, 0.f);
	glRotatef(10, 1, 0, 0);
	draw_circle(0, 0, orbrad);		/*draw the orbit of our planet , on which path it will follow and revolve
									around the sun*/
	glRotatef(anglep[i], 0.0f, 1.0f, 0.0f);
	anglep[i] += angspeed;		/*change the speed accordingly. each planet will have different speed as they
									are at different distances from the sun*/
	glTranslatef(orbrad, 0.f, 0.f);
	glutSolidSphere(radius, 100, 100);

}