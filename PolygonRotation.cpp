// transformations.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <Windows.h>
#include <iostream>
#include <math.h>

#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\glut.h>

using namespace std;

float tx, ty, theta, sx, sy;
int choice;

void transformations(void) {

	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POLYGON);

	glColor3ub(0, 102, 204);
	glVertex2f(0, 0);
	glVertex2f(0, 100);
	glVertex2f(50, 100);
	glVertex2f(50, 0);
	glEnd();

	glFlush();

	Sleep(1000);

	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POLYGON);

	if (choice == 1) {
		cout << "Translation \n";
		cout << "tx = ";
		cin >> tx;
		cout << "ty = ";
		cin >> ty;
		glColor3ub(255, 0, 51);
		glVertex2f(0 + tx, 0 + ty);
		glVertex2f(0 + tx, 100 + ty);
		glVertex2f(50 + tx, 100 + ty);
		glVertex2f(50 + tx, 0 + ty);
	}

	else if (choice == 2) {
		cout << "Rotation \n";
		cout << "theta (radians) = ";
		cin >> theta;
		glColor3ub(102, 204, 0);
		glVertex2f(0 * cos(theta) - 0 * sin(theta), 0 * sin(theta) + 0 * cos(theta));
		glVertex2f(0 * cos(theta) - 100 * sin(theta), 0 * sin(theta) + 100 * cos(theta));
		glVertex2f(50 * cos(theta) - 100 * sin(theta), 50 * sin(theta) + 100 * cos(theta));
		glVertex2f(50 * cos(theta) - 0 * sin(theta), 50 * sin(theta) + 0 * cos(theta));
	}

	else {
		cout << "Scaling \n";
		cout << "sx = ";
		cin >> sx;
		cout << "sy = ";
		cin >> sy;
		glColor3ub(204, 102, 51);
		glVertex2f(0 * sx, 0 * sy);
		glVertex2f(0 * sx, 100 * sy);
		glVertex2f(50 * sx, 100 * sy);
		glVertex2f(50 * sx, 0 * sy);
	}

	glEnd();

	glFlush();
}

void init(void) {
	glClearColor(1, 1, 1, 0);
	gluOrtho2D(-200, 200, -200, 200);
}

int main(int argc, char** argv) {
	cout << "Geometric Transformations.. \n";
	cout << "Menu: \n";
	cout << "1. Translation \n2. Rotation \n3. Scaling \n";
	cin >> choice;
	if (choice != 1 && choice != 2 && choice != 3) {
		cout << "Wrong Choice \nExiting..";
		exit(0);
	}
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Geometric Transformations");
	init();
	glutDisplayFunc(transformations);
	glutMainLoop();
	return 0;
}
