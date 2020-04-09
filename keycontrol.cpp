#include "variables.cpp"
/*Handles our key presses*/
void pressKey(int key, int xx, int yy) {

    switch (key) {
    case GLUT_KEY_LEFT:     /*pan left (move the camera towards left)*/
        deltaAngle -= 0.01f;
        break;
    case GLUT_KEY_RIGHT:    /*pan right (move the camera towards right)*/
        deltaAngle += 0.01f;
        break;
    case GLUT_KEY_UP:       /*pan forward (move the camera forward )*/
        deltaz = +0.09f;
        break;
    case GLUT_KEY_DOWN:     /*pan backward (move the camera backward ()*/
        deltaz = -0.09f;
        break;
    case GLUT_KEY_PAGE_UP:      /*zoom in*/
        zoom += 0.1f;
        break;
    case GLUT_KEY_PAGE_DOWN:    /*zoom out*/
        zoom -= 0.1f;
        break;
    case GLUT_KEY_HOME:         /*reset back to the start position*/
        y = 1;
        z = 5;
        x = lx = ly = deltaAngle = deltax = deltay = roll = pitch = 0;
        angle = initAngle;
        zoom = 1;
        break;
    case GLUT_KEY_SHIFT_R:      /*move upwards, going up along the y-axis*/
        deltay = 0.05f;
        break;
    case GLUT_KEY_CTRL_R:       /*move downwards, going down along the y-axis*/
        deltay = -0.05f;
        break;
    case GLUT_KEY_CTRL_L:       /*roll, rotate about the z-axis*/
        roll += 1;
        break;
    case GLUT_KEY_SHIFT_L:      /*roll , rotate about the z-axis but in the opposite direction*/
        roll -= 1;
        break;
    case GLUT_KEY_F1:           /*pitch , rotate about the x-axis */
        pitch += 10;
        break;
    case GLUT_KEY_F2:           /*pitch , rotate about the x-axis but in the opposite direction*/
        pitch -= 10;
        break;
    }
}
/*Handles our key releases*/
void releaseKey(int key, int x, int y) {    /*what happens when we release an already pressed key*/

	switch (key) {
	case GLUT_KEY_LEFT:
	case GLUT_KEY_RIGHT: deltaAngle = 0.0f; break;  /*panning will stop after releasing the key*/
	case GLUT_KEY_UP:
	case GLUT_KEY_DOWN: deltaz = 0; break;      /*panning will stop once the key is released*/
	case GLUT_KEY_CTRL_R:
	case GLUT_KEY_SHIFT_R: deltay = 0; break;      /*panning up and down will stop on releasing the key*/
	}
}