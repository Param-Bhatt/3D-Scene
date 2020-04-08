#include"variables.cpp"
void ldobj()
{
	glPointSize(2.0);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_LINES);
	for (int i = 0; i < ptr - 1; i++)
	{
		int cx = arr[i][0], cy = arr[i][1], cz = arr[i][2];
		glVertex3f(cx, cy, cz);
	}
	
	glEnd();
}
void loadObj(const char* fname)
{
	FILE* fp;
	int read;
	GLfloat x, y, z;
	char ch;
	//_model = glGenLists(1);
	fp = fopen(fname, "r");
	if (!fp)
	{
		printf("can't open file %s\n", fname);
		exit(1);
	}
	{
		//glPushMatrix();
		//glBegin(GL_POINTS);
		while (!(feof(fp)))
		{
			read = fscanf(fp, "%c %f %f %f", &ch, &x, &y, &z);
			if (read == 4 && ch == 'v')
			{
				arr[ptr][0] = (x);
				arr[ptr][1] = (y);
				arr[ptr][2] = (z);
				++ptr;
			}
		}
	}
	fclose(fp);
}