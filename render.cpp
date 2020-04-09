#include "variables.cpp"
/*update the x and z coordinates if there is any change. this change comes while
									panning*/
void computePos(float deltaz) {	
	x += deltaz * lx;
	z += deltaz * lz;
}
/*when angle is changed , we update the change in the x-z plane as sin and
									cos components*/
void computeDir(float deltaAngle) {	
	angle += deltaAngle;
	lx = -sin(angle);
	lz = cos(angle);
}
/*Renders our objects and entire scene every single frame*/
void renderScene(void) {
	if (deltaz)
		computePos(deltaz);
	if (deltaAngle)
		computeDir(deltaAngle);
	/* Clear Color and Depth Buffers*/

	y += deltay;		/*change y axis, while panning*/
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	/* Reset the model-view matrix to our starting point of the scene */
	glLoadIdentity();			/*clear all buffers, reset the model-view matrix*/
	glRotatef(roll, 0.0f, 0.0f, 1.0f);
	glRotatef(pitch, 1.0f, 0.0f, 0.0f);
	gluLookAt(x, y, z, x + lx, y, z + lz, 0.0f, 1.0f, 0.0f);
	glScalef(zoom, zoom, zoom);
	/*SUN*/
	glColor3f(0.93f, 0.55f, 0.22f);
	glTranslatef(0.f, 1.f, 0.f);
	glutSolidSphere(1.5, 100, 100);
	/*mercury*/
	planet(0.1f, 2.5f, 0, 0.8f, 0.5f, 0.5f, 0.5f);
	/*VENUS*/
	planet(0.2f, 4.0f, 1, 0.7f, 0.54f, 0.568f, 0.631f);
	/*EARTH*/
	planet(0.4f, 6.5f, 2, 0.5f, 0.34f, 0.568f, 0.64f);
	glColor3f(0.8f, 0.8f, 0.8f);
	glRotatef(10, 1, 0, 0);
	glScalef(zoom, zoom, zoom);
	draw_circle(0, 0, 0.9f);		/*drawing the orbit of our moon*/
	glRotatef(anglep[8], 0.0f, 1.0f, 0.0f);
	anglep[8] += 1;		/*update the angle for rotation of moon about the earth*/
	glTranslatef(0.9, 0.f, 0.f);
	glutSolidSphere(0.06, 100, 100);
	/*Mars*/
	planet(0.3f, 8.5f, 3, 0.2f, 0.6f, 0.52f, 0.47f);
	/*Draws comets of random radius <0.3 and orbit radius [9.5,12.5]*/
	comet(9.5f);
	/*Jupiter*/
	planet(0.9f, 14.5f, 4, 0.08f, 0.788f, 0.568f, 0.225f);
	/*Saturn*/
	planet(0.7f, 18.f, 5, 0.05f, 0.749f, 0.74f, 0.68f);
	glRotatef(60, 0, 0, 1.f);	/*change the plane for drawing the rings of Saturn*/
	for (float i = 0.9; i < 1.3; i += 0.03)	/*drawing the rings of Saturn*/
	{
		if (i == 10.5) {
			continue;
		}
		draw_circle(0.f, 0, i);
	}
	/*Uranus*/
	planet(0.6f, 21.5f, 6, 0.02f, 0.28f, 0.49f, 0.658f);
	/*Neptune*/
	planet(0.4f, 24.f, 7, 0.009f, 0.23f, 0.568f, 0.85f);
	glRotatef(270, 1.0f, 0.0f, 0.0f);
	glScalef(0.01, 0.01, 0.01);
	ldobj();	/*calling the function to draw our 3D object , which happens to be a rocket here.*/ 
	glRotatef(90, 1.0, 0, 0);
	glScalef(100, 100, 100);
	glTranslatef(-34.0f, 0.0f, 0.0f);
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	glTranslatef(34.0f, 0.0f, 0.0f);
	glutWireTeacup(4);		/*draw teacup as a random floating object. */
	glTranslatef(-34.0f, 0.0f, 0.0f);
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	glTranslatef(34.0f, 0.0f, 0.0f);
	glutSolidTeapot(1);		/*draw a teapot in space. why not?*/
	glTranslatef(-34.0f, 0.0f, 0.0f);
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	glTranslatef(34.0f, 0.0f, 0.0f);
	glutWireTorus(0.7, 1, 50, 25);		/*draw a torus in space. if teapot and teacup exist, why not?*/
	glutSwapBuffers();	/*swapping the 2nd buffer with the front buffer. opengl allows us to handle 2 buffers at a 
						time , so that one is shown while the other buffer is being drawn behind*/
}