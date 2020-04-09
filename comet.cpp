#include"variables.cpp"
/*Draws comets of random orbit and size between the planets*/
void comet(GLfloat orbrad)
{
	glLoadIdentity(); /*clear all buffers*/
	glRotatef(roll, 0.0f, 0.0f, 1.0f);
	glRotatef(pitch, 1.0f, 0.0f, 0.0f);
	gluLookAt(x, y, z, x + lx, y, z + lz, 0.0f, 1.0f, 0.0f);
	glScalef(zoom, zoom, zoom);		/*a function to scale our camera as per the variable 'zoom' , implemented for 
									zooming in and zooming out*/
	glColor3f(0.5f, 0.5f, 0.5f);
	glTranslatef(0.f, 1.f, 0.f);	/*move to any point in our coordinate system , with (0,0,0) in the center and as
									as our reference*/
	glRotatef(10, 1, 0, 0);			/*rotate our system by angle about the x - axis*/
	glRotatef(anglep[9], 0.0f, 1.0f, 0.0f);
	anglep[9] += 0.1;
	glTranslatef(orbrad + random[0], 0.f, 0.f);
	glutSolidSphere(random[0] / 20, 100, 100);	/*draw a solid sphere*/
	for (int i = 0; i < 15; i++)
	{
		glTranslatef(-orbrad - random[i], 0.f, 0.f);
		glRotatef(25, 0.0f, 1.0f, 0.0f);
		glTranslatef(orbrad + random[i + 1], 0.f, 0.f);
		glutSolidSphere(random[i + 1] / 20, 100, 100);
	}
}