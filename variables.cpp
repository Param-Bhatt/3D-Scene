#pragma once
long int ptr = 0;
int loop = 0;
float arr[10000000][3];
// actual vector representing the camera's direction
float lx = 0.0f, ly = 0.0f, lz = -1.0f;
// XZ position of the camera
float x = 0.0f, y = 0, z = 5.0f;
float deltaAngle = 0.0f;
float anglep[10] = { 0.f };
float deltaMove = 0;
float zoom = 1.0f;
float random[17];
int refreshMills = 15;
float angle = 0.f;
int xOrigin = -1;
bool flag = false;
GLfloat AmbientLight[] = { 0.3,0.3,0.3,1.0 };                  //Initialization values for lighting
GLfloat DiffuseLight[] = { 0.8,0.8,0.8,1.0 };
GLfloat SpecularLight[] = { 1.0,1.0,1.0,1.0 };
GLfloat SpecRef[] = { 0.7,0.7,0.7,1.0 };
GLfloat LightPos[] = { -50.0,50.0,100.0,1.0 };
GLint Shine = 128;
GLint walkX = 0, walkY = 0, lookX = 0, lookY = 0;
GLint world = 1, oldX = -1, oldY = -1;
GLint doll = -1;