// Hut.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<Windows.h>
#include<math.h>

#include<gl\GL.h>
#include<gl\GLU.h>
#include<gl\glut.h>

void Hut(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	//Roof Side Fill
	glColor3f(0.5, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(440, 380, 0);
	glVertex3f(280, 680, 0);
	glVertex3f(270, 680, 0);
	glVertex3f(110, 380, 0);
	glEnd();

	//Roof Side Boundary
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(2);
	glBegin(GL_LINE_LOOP);
	glVertex3f(440, 380, 0);
	glVertex3f(280, 680, 0);
	glVertex3f(270, 680, 0);
	glVertex3f(110, 380, 0);
	glEnd();

	//Wall Main Fill
	glColor3f(0.89, 0.848, 0.434);
	glBegin(GL_POLYGON);
	glVertex3f(420, 60, 0);
	glVertex3f(420, 460, 0);
	glVertex3f(1020, 460, 0);
	glVertex3f(1020, 120, 0);
	glEnd();

	//Wall Main Boundary
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(2);
	glBegin(GL_LINE_LOOP);
	glVertex3f(420, 60, 0);
	glVertex3f(420, 460, 0);
	glVertex3f(1020, 460, 0);
	glVertex3f(1020, 120, 0);
	glEnd();

	//Wall Side Fill (Triangle)
	glColor3f(0.89, 0.848, 0.434);
	glBegin(GL_POLYGON);
	glVertex3f(280, 680, 0);
	glVertex3f(140, 420, 0);
	glVertex3f(420, 420, 0);
	glEnd();

	//Wall Side Fill (Rectangle)
	glColor3f(0.89, 0.848, 0.434);
	glBegin(GL_POLYGON);
	glVertex3f(140, 120, 0);
	glVertex3f(140, 420, 0);
	glVertex3f(420, 420, 0);
	glVertex3f(420, 60, 0);
	glEnd();

	//Wall Side Boundary (Triangle)
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(2);
	glBegin(GL_LINE_STRIP);
	glVertex3f(420, 420, 0);
	glVertex3f(280, 680, 0);
	glVertex3f(140, 420, 0);
	glEnd();

	//Wall Side Boundary (Rectangle)
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(2);
	glBegin(GL_LINE_STRIP);
	glVertex3f(420, 420, 0);
	glVertex3f(420, 60, 0);
	glVertex3f(140, 120, 0);
	glVertex3f(140, 420, 0);
	glEnd();

	//Roof Main Fill
	glColor3f(0.5, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(430, 380, 0);
	glVertex3f(270, 680, 0);
	glVertex3f(940, 680, 0);
	glVertex3f(1100, 410, 0);
	glEnd();

	//Roof Main Boundary
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(2);
	glBegin(GL_LINE_LOOP);
	glVertex3f(430, 380, 0);
	glVertex3f(270, 680, 0);
	glVertex3f(940, 680, 0);
	glVertex3f(1100, 410, 0);
	glEnd();

	//Window Fill
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(580, 160, 0);
	glVertex3f(580, 300, 0);
	glVertex3f(860, 320, 0);
	glVertex3f(860, 190, 0);
	glEnd();

	//Window Boundary
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(2);
	glBegin(GL_LINE_LOOP);
	glVertex3f(580, 160, 0);
	glVertex3f(580, 300, 0);
	glVertex3f(860, 320, 0);
	glVertex3f(860, 190, 0);
	glEnd();

	//Window Bars
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex3f(720, 175, 0);
	glVertex3f(720, 310, 0);
	glVertex3f(580, 230, 0);
	glVertex3f(860, 255, 0);
	glEnd();

	//Door Fill
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(210, 105, 0);
	glVertex3f(210, 360, 0);
	glVertex3f(350, 350, 0);
	glVertex3f(350, 75, 0);
	glEnd();

	//Door Boundary
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(2);
	glBegin(GL_LINE_LOOP);
	glVertex3f(210, 105, 0);
	glVertex3f(210, 360, 0);
	glVertex3f(350, 350, 0);
	glVertex3f(350, 75, 0);
	glEnd();

	//Circle Fill
	float r = 40, x = 0, y = r, xc = 280, yc = 500, p = 1 - r;
	int k;

	glColor3f(1.0, 1.0, 1.0);
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

	//Circle Boundary
	r = 40, x = 0, y = r, xc = 280, yc = 500, p = 1 - r;

	glColor3f(0.0, 0.0, 0.0);
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



	glFlush();
}

void init(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	gluOrtho2D(0, 1366, 0, 768);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(450, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Hut");
	init();
	glutDisplayFunc(Hut);
	glutMainLoop();
	return 0;
}
