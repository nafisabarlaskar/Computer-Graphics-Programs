// MidpointEllipse.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<Windows.h>
#include<iostream>
#include<math.h>
#include<gl/GL.h>
#include<gl/GLU.h>
#include<gl/glut.h>

float xc, yc, rx, ry;

void midPonitEllipseAlgorithm(void)
{
	float x = 0, y = ry;
	float p = pow(ry, 2) - pow(rx, 2)*ry + (1 / 4)*pow(rx, 2);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2i(x + xc, y + yc);
	while (2 * pow(ry, 2)*x <= 2 * pow(rx, 2)*y)
	{
		x++;
		if (p<0)
		{
			p = p + 2 * pow(ry, 2)*x + pow(ry, 2);
		}
		else
		{
			y--;
			p = p + 2 * pow(ry, 2)*x - 2 * pow(rx, 2)*y + pow(ry, 2);
		}
		glVertex2i(x + xc, y + yc);
		glVertex2i(-x + xc, y + yc);
		glVertex2i(x + xc, -y + yc);
		glVertex2i(-x + xc, -y + yc);
	}
	float q = pow(ry, 2)*pow((x + 0.5), 2) + pow(rx, 2)*pow((y - 1), 2) - pow(rx, 2)*pow(ry, 2);
	while (y)
	{
		y--;
		if (q>0)
		{
			q = q - 2 * pow(rx, 2)*y + pow(rx, 2);
		}
		else
		{
			x++;
			q = q + 2 * pow(ry, 2)*x - 2 * pow(rx, 2)*y + pow(rx, 2);
		}
		glVertex2i(x + xc, y + yc);
		glVertex2i(-x + xc, y + yc);
		glVertex2i(x + xc, -y + yc);
		glVertex2i(-x + xc, -y + yc);
	}
	glEnd();
	glFlush();
}

void Init()
{
	glClearColor(0.1, 0.0, 0.0, 0);
	glColor3f(0.0, 0.0, 0.0);
	gluOrtho2D(-400, 400, -400, 400);
}

int main(int argc, char ** argv)
{
	xc = 100, yc = 200, rx = 200, ry = 150;
	glutInit(&argc, argv);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Mid Ponit Ellipse Algorithm");
	Init();
	glutDisplayFunc(midPonitEllipseAlgorithm);
	glutMainLoop();
	return 0;
}
