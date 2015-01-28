// Kite.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<Windows.h>
#include<iostream>
#include<gl/GL.h>
#include<gl/GLU.h>
#include<gl/glut.h>

void NestedPolygon(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.45, 0.6, 0.1);
	glBegin(GL_POLYGON);
	glVertex2i(-300, 100);
	glVertex2i(300, 100);
	glVertex2i(300, -100);
	glVertex2i(-300, -100);
	glEnd();
	glColor3f(0.0, 0.6, 0.1);
	glBegin(GL_POLYGON);
	glVertex2i(-100, 30);
	glVertex2i(100, 30);
	glVertex2i(100, -30);
	glVertex2i(-100, -30);
	glEnd();
	glFlush();

	int sx = 1.9, sy = 2.5, k1, k2;

	Sleep(1000);
	
	
	for (k1 = 0, k2 = 0; k1 <= sx, k2 <= sy; k1 += 0.001, k2 += 0.001)
	{
		Sleep(100);

		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(0.45, 0.6, 0.1);
		glBegin(GL_POLYGON);
		glVertex2i(-300, 100);
		glVertex2i(300, 100);
		glVertex2i(300, -100);
		glVertex2i(-300, -100);
		glEnd();

		glColor3f(0.1, 0.33, 0.1);
		glBegin(GL_POLYGON);
		glVertex2i(-100 * sx, 30 * sy);
		glVertex2i(100 * sx, 30 * sy);
		glVertex2i(100 * sx, -30 * sy);
		glVertex2i(-100 * sx, -30 * sy);
		glEnd();
		glFlush();
	}
	glFlush();
}
void Init()
{
	glClearColor(0.45, 0.8, 1.0, 0);
	gluOrtho2D(-500, 500, -500, 500);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Kite");
	Init();
	glutDisplayFunc(NestedPolygon);
	glutMainLoop();
	return 0;
}