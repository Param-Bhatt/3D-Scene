#include"variables.cpp"
void comet(GLfloat orbrad)
{
	glLoadIdentity();
	gluLookAt(x, 1.0f, z, x + lx, 1.0f, z + lz, 0.0f, 1.0f, 0.0f);
	glScalef(zoom, zoom, zoom);
	glColor3f(0.5f, 0.5f, 0.5f);
	glTranslatef(0.f, 1.f, 0.f);
	glRotatef(0, 1, 0, 0);
	//SHIFT
	//glRotatef(10, 0.f, 1.f, 0.f);
	//draw_circle(0, 0, orbrad);
	glRotatef(anglep[9], 0.0f, 1.0f, 0.0f);
	anglep[9] += 0.1;
	glTranslatef(orbrad + random[0], 0.f, 0.f);
	glutSolidSphere(random[0] / 20, 100, 100);
	for (int i = 0; i < 15; i++)
	{
		glTranslatef(-orbrad - random[i], 0.f, 0.f);
		glRotatef(25, 0.0f, 1.0f, 0.0f);
		glTranslatef(orbrad + random[i + 1], 0.f, 0.f);
		glutSolidSphere(random[i + 1] / 20, 100, 100);
	}
}