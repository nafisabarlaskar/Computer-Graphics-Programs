// BresenhamLineAlgorithm.cpp : Defines the entry point for the console application.
//

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

#include "stdafx.h"

#include <Windows.h>
#include <iostream>
#include <math.h>

#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\glut.h>

using namespace std;

float xi, yi, xf, yf;

void Bresenham(void) {

	glClear(GL_COLOR_BUFFER_BIT);

	float dx = abs(xf - xi), dy = abs(yf - yi), x, y, p;

	glPointSize(2);
	glBegin(GL_POINTS);

	glColor3f(0, 0, 0);

	if (dx >= dy) {
		x = min(xi, xf);
		if (x == xi) {
			y = yi;
		}
		else {
			y = yf;
		}
		glVertex2f(x, y);
		p = 2 * dy - dx;
		for (int i = 0; i < dx; i++) {
			if (p < 0) {
				p = p + 2 * dy;
			}
			else {
				p = p + (2 * dy - 2 * dx);
				if (((yf - yi) / (xf - xi)) >= 0) {
					y++;
				}
				else {
					y--;
				}
			}
			x++;
			glVertex2f(x, y);
		}
	}
	else {
		y = min(yi, yf);
		if (y == yi) {
			x = xi;
		}
		else {
			x = xf;
		}
		p = 2 * dx - dy;
		glVertex2f(x, y);
		for (int i = 0; i < dy; i++) {
			if (p < 0) {
				p = p + 2 * dx;
			}
			else {
				p = p + (2 * dx - 2 * dy);
				if (((yf - yi) / (xf - xi)) >= 0) {
					x++;
				}
				else {
					x--;
				}
			}
			y++;
			glVertex2f(x, y);
		}
	}
	glEnd();

	glLineWidth(1);
	glColor3f(0, 0, 1);
	glBegin(GL_LINES);
	glVertex2f(-200, 0);
	glVertex2f(200, 0);
	glVertex2f(0, -200);
	glVertex2f(0, 200);
	glEnd();

	glFlush();
}

void init(void) {
	glClearColor(1, 1, 1, 0);
	gluOrtho2D(-200, 200, -200, 200);
}

int main(int argc, char** argv) {
	cout << "Bresenham Line Algorithm.. \n";
	cout << "Enter the coordinates of Initial points: \n";
	cout << "xi = ";
	cin >> xi;
	cout << "yi = ";
	cin >> yi;
	cout << "Enter the coordinates of Final points: \n";
	cout << "xf = ";
	cin >> xf;
	cout << "yf = ";
	cin >> yf;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Bresenham Line Algorithm");
	init();
	glutDisplayFunc(Bresenham);
	glutMainLoop();
	return 0;
}