/*#include"snowman.cpp"
#include<math.h>
#include"pyramid.cpp"
#include"cube.cpp"
#include"torus.cpp"

#define INIT_VIEW_X 0.0    //Define initial camera position and viewing window values
#define INIT_VIEW_Y 0.0
#define INIT_VIEW_Z -4.5
#define VIEW_LEFT -2.0
#define VIEW_RIGHT 2.0
#define VIEW_BOTTOM -2.0
#define VIEW_TOP 2.0
#define VIEW_NEAR 1.0
#define VIEW_FAR 200.0
GLfloat AmbientLight[] = { 0.3,0.3,0.3,1.0 };                  //Initialization values for lighting
GLfloat DiffuseLight[] = { 0.8,0.8,0.8,1.0 };
GLfloat SpecularLight[] = { 1.0,1.0,1.0,1.0 };
GLfloat SpecRef[] = { 0.7,0.7,0.7,1.0 };
GLfloat LightPos[] = { -50.0,50.0,100.0,1.0 };
GLint Shine = 128;
GLint walkX = 0, walkY = 0, lookX = 0, lookY = 0;
GLint world = 1, oldX = -1, oldY = -1;
GLint doll = -1;

#include"human.cpp"
#include"resize.cpp"

void SetupRend()
{
	glClearColor(0.7, 0.7, 1.0, 1.0);
	glEnable(GL_DEPTH_TEST);         //Enable depth testing
	glEnable(GL_LIGHTING);             //Enable lighting
	glLightfv(GL_LIGHT0, GL_AMBIENT, AmbientLight);//Set up and enable light zero
	glLightfv(GL_LIGHT0, GL_DIFFUSE, DiffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, SpecularLight);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);                   //Enable color tracking
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);//Set material to follow
	glMaterialfv(GL_FRONT, GL_SPECULAR, SpecRef);//Set specular reflectivity and shine
	glMateriali(GL_FRONT, GL_SHININESS, Shine);
}

void renderScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//Clear the window
	glPushMatrix();//Save viewing matrix state
	glColor3f(0.9f, 0.9f, 0.9f);
	glBegin(GL_QUADS);
	glVertex3f(-100.0f, 0.0f, -100.0f);
	glVertex3f(-100.0f, 0.0f, 100.0f);
	glVertex3f(100.0f, 0.0f, 100.0f);
	glVertex3f(100.0f, 0.0f, -100.0f);

	if (world == 1)
	{
		glTranslatef(walkX, -1, walkY);
		glRotatef(lookY, 0, 1, 0);
		glRotatef(lookX, 1, 0, 0);
	}
	if (doll == 1)
	{
		glTranslatef(walkX, -1, walkY);
		glRotatef(lookY, 0, 1, 0);
		glRotatef(lookX, 1, 0, 0);
	}
	for (int i = -3; i < 3; i++) {
		for (int j = -3; j < 3; j++) {
			glColor3ub(50, 50, 150);//Change the draw color to slate blue
			glPushMatrix();
			glTranslatef(-1*10*i, 0, -6*2*j);
			eyeright();
			eyeleft();
			eyebrowleft();
			eyebrowright();
			glColor3f(0.0, 1.0, 0.0);
			neckring();
			glColor3ub(50, 40, 60);
			legright();
			legleft();
			glColor3ub(255, 90, 0);
			armleft();
			armright();
			BellyCoat();
			bellyCoatbottom();
			glColor3ub(0, 185, 0);
			handleft();
			handright();
			mouth();
			teeth();
			glColor3ub(255, 222, 173);
			head();
			glColor3f(0.0, 0.0, 0.0);
			footleft();
			footright();
			topbutton();
			middlebutton();
			bottombutton();
			pupilleft();
			pupilright();
			glPopMatrix();

		}
	}
	glPopMatrix();                                     //****Restore matrix state****
	glutSwapBuffers();                             //****Flush drawing commands****
}*/
#include "variables.cpp"
void SetupRend()
{
	glClearColor(0.7, 0.7, 1.0, 1.0);
	glEnable(GL_DEPTH_TEST);         //Enable depth testing
	glEnable(GL_LIGHTING);             //Enable lighting
	glLightfv(GL_LIGHT0, GL_AMBIENT, AmbientLight);//Set up and enable light zero
	glLightfv(GL_LIGHT0, GL_DIFFUSE, DiffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, SpecularLight);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);                   //Enable color tracking
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);//Set material to follow
	glMaterialfv(GL_FRONT, GL_SPECULAR, SpecRef);//Set specular reflectivity and shine
	glMateriali(GL_FRONT, GL_SHININESS, Shine);
}
void computePos(float deltaMove) {

	x += deltaMove * lx * 0.1f;
	z += deltaMove * lz * 0.1f;
}
void computeDir(float deltaAngle) {

	angle += deltaAngle;
	lx = sin(angle);
	lz = -cos(angle);
}
void renderScene(void) {
	if (deltaMove)
		computePos(deltaMove);
	if (deltaAngle)
		computeDir(deltaAngle);
	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(x, 1.0f, z, x + lx, 1.0f, z + lz, 0.0f, 1.0f, 0.0f);
	glScalef(zoom, zoom, zoom);// Reset the model-view matrix
	//SUN
	glColor3f(0.93f, 0.55f, 0.22f);
	glTranslatef(0.f, 1.f, 0.f);
	glutSolidSphere(1.5, 100, 100);
	//mercury
	planet(0.1f, 2.5f, 0, 0.8f, 0.5f, 0.5f, 0.5f);
	//VENUS
	planet(0.2f, 4.0f, 1, 0.7f, 0.54f, 0.568f, 0.631f);
	//EARTH
	planet(0.4f, 6.5f, 2, 0.5f, 0.34f, 0.568f, 0.64f);
	glColor3f(0.8f, 0.8f, 0.8f);
	glRotatef(10, 1, 0, 0);
	draw_circle(0, 0, 0.9f);
	glScalef(zoom, zoom, zoom);
	glRotatef(anglep[8], 0.0f, 1.0f, 0.0f);
	anglep[8] += 1;
	glTranslatef(0.9, 0.f, 0.f);
	glutSolidSphere(0.06, 100, 100);
	//Mars
	planet(0.3f, 8.5f, 3, 0.2f, 0.6f, 0.52f, 0.47f);
	glLoadIdentity();
	//DRAWS Commets of random radius <0.3 and orbrad [9.5,12.5]
	comet(9.5f);
	//Jupyter
	planet(0.9f, 14.5f, 4, 0.08f, 0.788f, 0.568f, 0.225f);
	//Saturn
	planet(0.7f, 18.f, 5, 0.05f, 0.749f, 0.74f, 0.68f);
	glRotatef(60, 0, 0, 1.f);
	for (float i = 0.9; i < 1.3; i += 0.03)
	{
		if (i == 10.5) {
			continue;
		}
		draw_circle(0.f, 0, i);
	}
	//Uranus
	planet(0.6f, 21.5f, 6, 0.02f, 0.28f, 0.49f, 0.658f);
	//Neptune
	planet(0.4f, 24.f, 7, 0.009f, 0.23f, 0.568f, 0.85f);
	//Object
	glLoadIdentity();
	glTranslatef(10.0f, 0.0f, 0.f);
	glRotatef(270, 0, 1, 0);
	glRotatef(anglep[3], 0, 0, 1);
	anglep[3] += 1.5;
	glScalef(0.003, 0.003, 0.003);
	ldobj();
	
	/*glScalef(100.0, 100.0, 100.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	glTranslatef(-34.0f, 0.0f, 0.0f);
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	glTranslatef(34.0f, 0.0f, 0.0f);
	//glutWireTeacup(4);
	glTranslatef(-34.0f, 0.0f, 0.0f);
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	glTranslatef(34.0f, 0.0f, 0.0f);
	glutWireTeapot(4);
	glTranslatef(-34.0f, 0.0f, 0.0f);
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	glTranslatef(34.0f, 0.0f, 0.0f);
	glutWireTorus(2, 4, 50, 25);
	*/glutSwapBuffers();
}