// flyingKite.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <Windows.h>
#include <iostream>
#include <math.h>

#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\glut.h>

using namespace std;

float tx, ty, theta;

void flyingKite(void) {

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3ub(0, 102, 204);
	glBegin(GL_POLYGON);
	glVertex2f(0, 80);
	glVertex2f(-40, 120);
	glVertex2f(0, 160);
	glVertex2f(40, 120);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(0, 80);
	glVertex2f(-16, 60);
	glVertex2f(16, 60);
	glEnd();
	glFlush();

	Sleep(1000);

	for (theta = 0; theta >= -0.5; theta -= 0.005) {
		glFlush();
		Sleep(5);
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3ub(102, 204, 0);
		glBegin(GL_POLYGON);
		glVertex2f(0 * cos(theta) - 80 * sin(theta), 0 * sin(theta) + 80 * cos(theta));
		glVertex2f(-40 * cos(theta) - 120 * sin(theta), -40 * sin(theta) + 120 * cos(theta));
		glVertex2f(0 * cos(theta) - 160 * sin(theta), 0 * sin(theta) + 160 * cos(theta));
		glVertex2f(40 * cos(theta) - 120 * sin(theta), 40 * sin(theta) + 120 * cos(theta));
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2f(0 * cos(theta) - 80 * sin(theta), 0 * sin(theta) + 80 * cos(theta));
		glVertex2f(-16 * cos(theta) - 60 * sin(theta), -16 * sin(theta) + 60 * cos(theta));
		glVertex2f(16 * cos(theta) - 60 * sin(theta), 16 * sin(theta) + 60 * cos(theta));
		glEnd();
	}

	Sleep(1000);

	theta = -0.5;
	for (tx = 0, ty = 0; ty <= 24; tx += 0.1, ty += 0.2) {
		glFlush();
		Sleep(5);
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3ub(204, 102, 51);
		glBegin(GL_POLYGON);
		glVertex2f(0 * cos(theta) - 80 * sin(theta) + tx, 0 * sin(theta) + 80 * cos(theta) + ty);
		glVertex2f(-40 * cos(theta) - 120 * sin(theta) + tx, -40 * sin(theta) + 120 * cos(theta) + ty);
		glVertex2f(0 * cos(theta) - 160 * sin(theta) + tx, 0 * sin(theta) + 160 * cos(theta) + ty);
		glVertex2f(40 * cos(theta) - 120 * sin(theta) + tx, 40 * sin(theta) + 120 * cos(theta) + ty);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2f(0 * cos(theta) - 80 * sin(theta) + tx, 0 * sin(theta) + 80 * cos(theta) + ty);
		glVertex2f(-16 * cos(theta) - 60 * sin(theta) + tx, -16 * sin(theta) + 60 * cos(theta) + ty);
		glVertex2f(16 * cos(theta) - 60 * sin(theta) + tx, 16 * sin(theta) + 60 * cos(theta) + ty);
		glEnd();
	}

	Sleep(1000);

	for (ty = 48; ty >= 0; tx -= 0.1, ty -= 0.2) {
		glFlush();
		Sleep(1);
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3ub(51, 204, 102);
		glBegin(GL_POLYGON);
		glVertex2f(0 * cos(theta) - 80 * sin(theta) + tx, 0 * sin(theta) + 80 * cos(theta) + ty);
		glVertex2f(-40 * cos(theta) - 120 * sin(theta) + tx, -40 * sin(theta) + 120 * cos(theta) + ty);
		glVertex2f(0 * cos(theta) - 160 * sin(theta) + tx, 0 * sin(theta) + 160 * cos(theta) + ty);
		glVertex2f(40 * cos(theta) - 120 * sin(theta) + tx, 40 * sin(theta) + 120 * cos(theta) + ty);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2f(0 * cos(theta) - 80 * sin(theta) + tx, 0 * sin(theta) + 80 * cos(theta) + ty);
		glVertex2f(-16 * cos(theta) - 60 * sin(theta) + tx, -16 * sin(theta) + 60 * cos(theta) + ty);
		glVertex2f(16 * cos(theta) - 60 * sin(theta) + tx, 16 * sin(theta) + 60 * cos(theta) + ty);
		glEnd();
	}

	Sleep(1000);

	for (theta = -0.5; theta <= 0.5; theta += 0.005) {
		glFlush();
		Sleep(50);
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3ub(255, 0, 51);
		glBegin(GL_POLYGON);
		glVertex2f(0 * cos(theta) - 80 * sin(theta), 0 * sin(theta) + 80 * cos(theta));
		glVertex2f(-40 * cos(theta) - 120 * sin(theta), -40 * sin(theta) + 120 * cos(theta));
		glVertex2f(0 * cos(theta) - 160 * sin(theta), 0 * sin(theta) + 160 * cos(theta));
		glVertex2f(40 * cos(theta) - 120 * sin(theta), 40 * sin(theta) + 120 * cos(theta));
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2f(0 * cos(theta) - 80 * sin(theta), 0 * sin(theta) + 80 * cos(theta));
		glVertex2f(-16 * cos(theta) - 60 * sin(theta), -16 * sin(theta) + 60 * cos(theta));
		glVertex2f(16 * cos(theta) - 60 * sin(theta), 16 * sin(theta) + 60 * cos(theta));
		glEnd();
	}

	Sleep(1000);

	theta = 0.5;
	for (tx = 0, ty = 0; ty <= 24; tx += 0.1, ty += 0.2) {
		glFlush();
		Sleep(100);
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3ub(204, 255, 51);
		glBegin(GL_POLYGON);
		glVertex2f(0 * cos(theta) - 80 * sin(theta) + tx, 0 * sin(theta) + 80 * cos(theta) + ty);
		glVertex2f(-40 * cos(theta) - 120 * sin(theta) + tx, -40 * sin(theta) + 120 * cos(theta) + ty);
		glVertex2f(0 * cos(theta) - 160 * sin(theta) + tx, 0 * sin(theta) + 160 * cos(theta) + ty);
		glVertex2f(40 * cos(theta) - 120 * sin(theta) + tx, 40 * sin(theta) + 120 * cos(theta) + ty);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2f(0 * cos(theta) - 80 * sin(theta) + tx, 0 * sin(theta) + 80 * cos(theta) + ty);
		glVertex2f(-16 * cos(theta) - 60 * sin(theta) + tx, -16 * sin(theta) + 60 * cos(theta) + ty);
		glVertex2f(16 * cos(theta) - 60 * sin(theta) + tx, 16 * sin(theta) + 60 * cos(theta) + ty);
		glEnd();
	}

	glFlush();
	Sleep(1000);
}

void init(void) {
	glClearColor(1, 1, 1, 0);
	gluOrtho2D(-200, 200, 0, 200);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 400);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Flying Kite");
	init();
	glutDisplayFunc(flyingKite);
	glutMainLoop();
	return 0;
}