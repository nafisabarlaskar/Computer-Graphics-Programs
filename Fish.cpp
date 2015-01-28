#include"stdafx.h"
#include<Windows.h>

#include<stdio.h>
#include<math.h>
#include<GL/glut.h>

#include<gl/GL.h>
#include<gl/GLU.h>

void fish()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(0, 50, 0);
	glVertex3f(100, 50, 0);
	glVertex3f(100, -50, 0);
	glVertex3f(0, -50, 0);
	glEnd();

	glColor3f(1.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(50, 50, 0);
	glVertex3f(160, 75, 0);
	glVertex3f(100, 50, 0);
	glEnd();


	glColor3f(1.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(50, -50, 0);
	glVertex3f(160, -75, 0);
	glVertex3f(100, -50, 0);
	glEnd();

	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(100, 50, 0);
	glVertex3f(200, 0, 0);
	glVertex3f(100, -50, 0);
	glEnd();

	glColor3f(1.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(200, 0, 0);
	glVertex3f(300, 40, 0);
	glVertex3f(250, 0, 0);
	glVertex3f(300, -40, 0);
	glEnd();

	//glColor3f(1.0,0.0,1.0);
	float rx = 100, ry = 50;
	float x = 0, y = ry, p, po;
	//glClear(GL_COLOR_BUFFER_BIT);
	p = (ry*ry) - (rx*rx*ry) + ((rx*rx) / 4);
	glColor3f(1.0, 0.0, 1.0);
	glBegin(GL_TRIANGLE_FAN);
	while (2 * ry*ry*x <= 2 * rx*rx*y){
		if (p<0){
			x += 1;

			//glVertex2i(x,y);
			p += (2 * ry*ry*x) + (ry*ry);
		}
		else{
			x += 1;
			y -= 1;
			//glVertex2i(x,y);
			p += (2 * ry*ry*x) - (2 * rx*rx*y) + (ry*ry);
		}
		glVertex2f(-x, y);
		// glVertex2f(-y,x);
		glVertex2f(-x, -y);
		//glVertex2f(-y,-x);
	}
	glEnd();
	glFlush();
	po = ry*ry*(x + 0.5)*(x + 0.5) + rx*rx*(y - 1)*(y - 1) - (rx*rx*ry*ry);
	glBegin(GL_TRIANGLE_FAN);
	while (y != 0){
		if (po <= 0){
			x += 1;
			y -= 1;

			po += (2 * ry*ry*x) - (2 * rx*rx*y) + (rx*rx);
		}
		else{
			y -= 1;
			po += (-2 * rx*rx*y) + (rx*rx);
		}
		glVertex2f(-x, y);
		//glVertex2f(-y,x);
		glVertex2f(-x, -y);
		//glVertex2f(-y,-x);
	}
	glEnd();
	//glFlush();
	/*glColor3f(1.0,1.0,1.0);
	glBegin(GL_POINTS);
	int i;
	for(i=-100;i<=100;i++)
	glVertex2f(i,0);

	for(i=-150;i<=150;i++)
	glVertex2f(0,i);

	glEnd();*/

	float r = 0, s = 3;
	float xc = -70, yc = 25;
	float d = 1 - 2;
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POINTS);
	glVertex2f(r, s);
	while (r<s)
	{
		if (d<0)
		{
			r++;
			d = d + (2 * r) + 1;
		}
		else
		{
			r++;
			s--;
			d = d + 2 * (r - s) + 1;
		}
		glVertex2f(r + xc, s + yc);
		glVertex2f(s + xc, r + yc);
		glVertex2f(r + xc, -s + yc);
		glVertex2f(s + xc, -r + yc);
		glVertex2f(-r + xc, -s + yc);
		glVertex2f(-s + xc, -r + yc);
		glVertex2f(-r + xc, s + yc);
		glVertex2f(-s + xc, r + yc);
	}
	glEnd();
	glFlush();
}
void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-300, 300, -300, 300);
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("fish");
	init();
	glutDisplayFunc(fish);
	glutMainLoop();
	return 0;
}
