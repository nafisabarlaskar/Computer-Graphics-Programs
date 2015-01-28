// MidpointCircle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<Windows.h>
#include<math.h>
#include<iostream>
#include<gl/GL.h>
#include<gl/GLU.h>
#include<gl/glut.h>

float xc, yc, radius;

void MidpointCircle(void)
{
	float x = 0, y = radius;
	float p = (1 - radius);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2i(x + xc, y + yc);
	while (x <= y)
	{
		x++;
		if (p < 0)
		{
			
			p += 2 * x + 1;
		}
		else
		{
			y--;
			p += 2 * x + 1 - 2 * y;
		}
		glVertex2i(x + xc, y + yc);
		glVertex2i(y + xc, x + yc);
		glVertex2i(-x + xc, y + yc);
		glVertex2i(-y + xc, x + yc);
		glVertex2i(-x + xc, -y + yc);
		glVertex2i(-y + xc, -x + yc);
		glVertex2i(x + xc, -y + yc);
		glVertex2i(y + xc, -x + yc);
	}
	glEnd();
	glFlush();
}
void Init()
{
	glClearColor(0.67,0.49,0.53,0);
	gluOrtho2D(-400,400,-400,400);
}

int main(int argc, char **argv)
{
	xc = -150, yc = 0, radius = 250;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Midpoint Circle Algorithm");
	Init();
	glutDisplayFunc(MidpointCircle);
	glutMainLoop();
	return 0;
}

