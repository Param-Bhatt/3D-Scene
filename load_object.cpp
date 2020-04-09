#include"variables.cpp"
/*Draws the vertices from the values in our array that we loaded from the object*/
void ldobj()
{
	glPointSize(3.0); 
	glColor3f(1.0f, 1.0f, 1.0f); /*color white*/
	glBegin(GL_POINTS);		/*draw points only*/
	for (int i = 0; i < ptr - 1; i++) /*drawing the stored coordinates of the vertices in our array*/
	{
		int cx = arr[i][0], cy = arr[i][1], cz = arr[i][2];
		glVertex3f(cx, cy, cz);
	}
	glEnd();
}
/*Load our 3D object(.obj) vertices(x,y,z) into an array .*/
void loadObj(const char* fname)
{
	FILE* fp;
	int read;
	GLfloat x, y, z;
	char ch;
	fp = fopen(fname, "r");
	if (!fp)
	{
		printf("can't open file %s\n", fname);
		exit(1);	/*escape and close the application if our file isnt opened*/
	}
	{
		while (!(feof(fp)))
		{
			read = fscanf(fp, "%c %f %f %f", &ch, &x, &y, &z);
			if (read == 4 && ch == 'v')
			{						/*storing the vertices of our 3D object in an array so as to use them later*/
				arr[ptr][0] = (x);
				arr[ptr][1] = (y);
				arr[ptr][2] = (z);
				ptr++;
				if (ptr > 100000)
					return;
			}
		}
	}
	fclose(fp);
}