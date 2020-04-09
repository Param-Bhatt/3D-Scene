#include "variables.cpp"
/*Handles our mouse clicks and the changes that we make while our mouse button is clicked*/
void mouseButton(int button, int state, int x, int y) {

	/* only start motion if the left button is pressed*/
	if (button == GLUT_LEFT_BUTTON) {

		/* when the button is released*/
		if (state == GLUT_UP) {		/*reset the values to the original ones before the mouse was pressed*/
			angle -= deltaAngle;
			xOrigin = -1;
		}
		else {/* state = GLUT_DOWN*/
			xOrigin = x;		/*change  the origin while the mouse is pressed, and then update it*/
		}
	}
	
}
/*to set up the motion call back for our window while the mouse is pressed and the
									mouse is moving*/
void mouseMove(int x, int y) {

	/* this will only be true when the left button is down*/
	if (xOrigin >= 0) {

		/* update deltaAngle*/
		deltaAngle = (x - xOrigin) * 0.0001f;

		/* update camera's direction*/
		lx = sin(angle + deltaAngle);
		lz = -cos(angle + deltaAngle);
	}
}
