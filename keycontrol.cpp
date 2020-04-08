/*#include"render.cpp"


void processNormalKeys(unsigned char key, int x, int y) {
	float fraction = 0.1f;
	if (key == 27)
		exit(0);
	
}
void walk(int key, int x, int y)                                      //change positions using arrow keys
{
    if (key == GLUT_KEY_UP)    walkY += 1;
    if (key == GLUT_KEY_DOWN)  walkY -= 1;
    if (key == GLUT_KEY_RIGHT) walkX -= 1;
    if (key == GLUT_KEY_LEFT)  walkX += 1;
    if (key == GLUT_KEY_F10)    world = -world;
    if (key == GLUT_KEY_F9)    doll = -doll;

}*/
#include "variables.cpp"
void pressKey(int key, int xx, int yy) {

	switch (key) {
	case GLUT_KEY_LEFT:
		deltaAngle = -0.01f;
		break;
	case GLUT_KEY_RIGHT:
		deltaAngle = 0.01f;
		break;
	case GLUT_KEY_UP:
		deltaMove = 0.9f;
		break;
	case GLUT_KEY_DOWN:
		deltaMove = -0.9f;
		break;
	case GLUT_KEY_PAGE_UP:
		zoom += 0.1f;
		break;
	case GLUT_KEY_PAGE_DOWN:
		zoom -= 0.1f;
		break;
	case GLUT_KEY_HOME:
		x = y = lx = ly = 0;
		z = 5;
		deltaAngle = deltaMove = 0;
		zoom = 1;
		break;
		//case GLUT_KEY_F1:

	}
}

void releaseKey(int key, int x, int y) {

	switch (key) {
	case GLUT_KEY_LEFT:
	case GLUT_KEY_RIGHT: deltaAngle = 0.0f; break;
	case GLUT_KEY_UP:
	case GLUT_KEY_DOWN: deltaMove = 0; break;
	}
}