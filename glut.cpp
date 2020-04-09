/*This is our main file*/
#ifdef __APPLE__
#define glGenVertexArrays glGenVertexArraysAPPLE
#define glBindVertexArray glBindVertexArrayAPPLE
#define glDeleteVertexArrays glDeleteVertexArraysAPPLE
#endif
#define _CRT_SECURE_NO_WARNINGS
#include "GL/freeglut.h"
#include <iostream>
#include<math.h>
#include"glm/glm.hpp"
#include <string>
#include <vector>
#include"variables.cpp"
#include "keycontrol.cpp"
#include "load_object.cpp"
#include "comet.cpp"
#include "mouse_control.cpp"
#include "circle.cpp"
#include "planet.cpp"
#include "resize.cpp"
#include "render.cpp"
using namespace std;
/*Initializes glut window*/
void initGL() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); /* Set background color to black and opaque*/
	glClearDepth(1.0f);                   /* Set background depth to farthest*/
	glEnable(GL_DEPTH_TEST);   /* Enable depth testing for z-culling*/
	glDepthFunc(GL_LEQUAL);    /* Set the type of depth-test*/
	glShadeModel(GL_SMOOTH);   /* Enable smooth shading*/
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  /* Nice perspective corrections*/
}
/*This is the main function of our scene/assignment/code*/
int main(int argc, char** argv) {

	/* init GLUT and create window*/
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutCreateWindow(""); /* create a small window with default size and parameters*/
	glutFullScreen(); /* resize that window to fit your screen size*/
	if (loop == 0) /*flag to ensure that the object is loaded only once*/
	{
		loop++;
		loadObj("data/rocket.obj"); /*loading our 3D object*/
		x = lx = ly = 0;
		y = 1;
		z = 5;
		deltaAngle = deltax = deltay = 0;
		angle = initAngle;
		zoom = 1;
	}
	for (int i = 0; i < 17; i++)
	{
		random[i] = ((rand() % 30) / 10.0);
	}
	glutDisplayFunc(renderScene); /*rendering our scene*/
	glutReshapeFunc(changeSize); /* this function is kept to ensure that when window size changes , all our objects 
									and axes are scaled accordingly and nothing goes haywire*/
	glutIdleFunc(renderScene);  /*this function allows us to determine what will glut do when there is nothing going
									on in the screen , i.e. no keys/mouse presses , then too we will keep on 
									rendering our scene to ensure that there is continuity*/
	glutSpecialFunc(pressKey);  /* this function is used to implement keyboard key presses into our application. 
									for example, keys like page up , home , escape etc.*/
	glutIgnoreKeyRepeat(1);			/*this function will ignore all key presses. It will ignore the presses more than 
										 1 , and only start counting again after the key is released*/
	glutSpecialUpFunc(releaseKey);/* this function comes into action when an already pressed key is released.*/
	/*mouse clicks*/
	glutMouseFunc(mouseButton);	/*this function helps us in detecting mouse presses. it sets up the mouse callbacks 
									for us*/
	glutMotionFunc(mouseMove);	/*to set up the motion call back for our window while the mouse is pressed and the 
									mouse is moving*/
	/ OpenGL init*/
	glEnable(GL_DEPTH_TEST);	/*to enable the depth comparisons and update the depth buffer accordingly*/
	initGL();
	/* enter GLUT event processing cycle*/
	glutMainLoop();

	return 1;
}