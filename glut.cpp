//#include"glut.h"
#ifdef __APPLE__
#define glGenVertexArrays glGenVertexArraysAPPLE
#define glBindVertexArray glBindVertexArrayAPPLE
#define glDeleteVertexArrays glDeleteVertexArraysAPPLE
#endif
#define _CRT_SECURE_NO_WARNINGS
#include"GL/freeglut.h"
#include <iostream>
#include<math.h>
#include"glm/glm.hpp"
#include <string>
#include <vector>
#include"variables.cpp"
#include "keycontrol.cpp"
#include "load_object.cpp"
#include "mouse_control.cpp"
#include "circle.cpp"
#include "comet.cpp"
#include "planet.cpp"
#include "resize.cpp"
#include "render.cpp"

using namespace std;

void initGL() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClearDepth(1.0f);                   // Set background depth to farthest
	glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
	glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
	glShadeModel(GL_SMOOTH);   // Enable smooth shading
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}

int main(int argc, char** argv) {

	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutCreateWindow("");
	glutFullScreen();
	if (loop == 0)
	{
		loop++;
		loadObj("data/rocket.obj");
	}
	for (int i = 0; i < 17; i++)
	{
		random[i] = ((rand() % 30) / 10.0);
		cout << random[i] << endl;
	}
	flag = true;
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);
	glutSpecialFunc(pressKey);
	// here are the new entries
	glutIgnoreKeyRepeat(1);
	glutSpecialUpFunc(releaseKey);
	//mouse clicks
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMove);
	// OpenGL init
	glEnable(GL_DEPTH_TEST);
	initGL();
	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}