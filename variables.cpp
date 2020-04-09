#pragma once
/* a single file for storing all the variables*/
long int ptr = 0;
int loop = 0;
float arr[100000][3];		//array to store the vertices of the 3D object
// actual vector representing the camera's direction
float lx = 0.0f, ly = 0.0f, lz = -1.0f;	
// XZ position of the camera
float x = 0.0f, y = 1.0, z = 5.0f;
float deltax = 0.0f, deltay = 0.0f, deltaz = 0.0f, deltaAngle = 0.0f;
float anglep[10] = { 0.f };
float zoom = 1.0f;	//default zoom. to increase or decrease, use page up or page down button
float random[17];	//for drawing asteroids/comets , generate an array of randomized values and then choose
float initAngle = 160;
float angle = initAngle; //setting up the intitial rotation angle ( for yaw )
int xOrigin = -1;
float roll = 0.0f;	//to set the angle for roll	 
float pitch = 0.0f;	//to set the angle for pitch
