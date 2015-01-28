// Flag.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


// Indian National Flag.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<Windows.h>
#include<math.h>

//Open GL header files
#include<gl\GL.h>
#include<gl\GLU.h>
#include<gl\glut.h>

void IndianNationalFlag(void) {
	//Clear all pixels
	glClear(GL_COLOR_BUFFER_BIT);

	//Orange Strip
	glColor3f(1.0, 0.5, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(-225, 200, 0);
	glVertex3f(-225, 300, 0);
	glVertex3f(225, 300, 0);
	glVertex3f(225, 200, 0);
	glEnd();

	//White Strip
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(-225, 200, 0);
	glVertex3f(-225, 100, 0);
	glVertex3f(225, 100, 0);
	glVertex3f(225, 200, 0);
	glEnd();

	//Green Strip
	glColor3f(0.0, 0.5, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(-225, 100, 0);
	glVertex3f(-225, 0, 0);
	glVertex3f(225, 0, 0);
	glVertex3f(225, 100, 0);
	glEnd();

	//Chakra
	glColor3f(0, 0, 0.5);
	glLineWidth(4);
	glBegin(GL_LINES);
	glVertex3f(0, 105, 0);
	glVertex3f(0, 195, 0);
	glVertex3f(-45, 150, 0);
	glVertex3f(45, 150, 0);
	glVertex3f(-32, 118, 0);
	glVertex3f(32, 182, 0);
	glVertex3f(-32, 182, 0);
	glVertex3f(32, 118, 0);
	glVertex3f(-42, 133, 0);
	glVertex3f(42, 167, 0);
	glVertex3f(-42, 167, 0);
	glVertex3f(42, 133, 0);
	glVertex3f(-17, 108, 0);
	glVertex3f(17, 192, 0);
	glVertex3f(-17, 192, 0);
	glVertex3f(17, 108, 0);
	glEnd();

	//Outer Circle
	float x = 0, y = 44, xc = 0, yc = 150, p = 1 - 44;

	glPointSize(4);
	glBegin(GL_POINTS);
	glVertex2i(x + xc, y + yc);
	int k;
	while (x <= y) {
		x++;
		if (p<0) {
			p = p + 2 * x + 1;
		}
		else {
			y--;
			p = p + 2 * x + 1 - 2 * y;
		}
		glVertex2i(x + xc, y + yc);
		glVertex2i(y + xc, x + yc);
		glVertex2i(y + xc, -x + yc);
		glVertex2i(x + xc, -y + yc);
		glVertex2i(-x + xc, -y + yc);
		glVertex2i(-y + xc, -x + yc);
		glVertex2i(-y + xc, x + yc);
		glVertex2i(-x + xc, y + yc);
	}
	glEnd();

	//Inner Outline Circle
	x = 0, y = 10, xc = 0, yc = 150, p = 1 - 10;

	glPointSize(2);
	glBegin(GL_POINTS);
	glVertex2i(x + xc, y + yc);
	while (x <= y) {
		x++;
		if (p<0) {
			p = p + 2 * x + 1;
		}
		else {
			y--;
			p = p + 2 * x + 1 - 2 * y;
		}
		glVertex2i(x + xc, y + yc);
		glVertex2i(y + xc, x + yc);
		glVertex2i(y + xc, -x + yc);
		glVertex2i(x + xc, -y + yc);
		glVertex2i(-x + xc, -y + yc);
		glVertex2i(-y + xc, -x + yc);
		glVertex2i(-y + xc, x + yc);
		glVertex2i(-x + xc, y + yc);
	}
	glEnd();

	//Inner Fill Circle
	x = 0, y = 10, xc = 0, yc = 150, p = 1 - 10;

	glBegin(GL_TRIANGLE_FAN);
	glVertex2i(x + xc, y + yc);
	while (x <= y) {
		x++;
		if (p<0) {
			p = p + 2 * x + 1;
		}
		else {
			y--;
			p = p + 2 * x + 1 - 2 * y;
		}
		glVertex2i(x + xc, y + yc);
		glVertex2i(y + xc, x + yc);
		glVertex2i(y + xc, -x + yc);
		glVertex2i(x + xc, -y + yc);
		glVertex2i(-x + xc, -y + yc);
		glVertex2i(-y + xc, -x + yc);
		glVertex2i(-y + xc, x + yc);
		glVertex2i(-x + xc, y + yc);
	}
	glEnd();

	glFlush();
}

void init(void) {
	//Background Color
	glClearColor(0.0, 0.0, 0.0, 0.0);

	//
	gluOrtho2D(-225, 225, 0, 300);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(450, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Indian National Flag");
	init();
	glutDisplayFunc(IndianNationalFlag);
	glutMainLoop();
	return 0;
}



