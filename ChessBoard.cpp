// ChessBoard.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<Windows.h>
#include<math.h>
#include<gl/GL.h>
#include<gl/GLU.h>
#include<gl/glut.h>

void ChessBoard(void)
{
	int i, j;
	glClear(GL_COLOR_BUFFER_BIT);
	for (i = 10; i < 90; i += 10)
	{
		for (j = 10; j < 90; j += 20)
		{
			if (i%20!=0)
			{
				glColor3f(1.0, 1.0, 1.0);
				glBegin(GL_POLYGON);
				glVertex2i(j + 10, i);
				glVertex2i(j + 20, i);
				glVertex2i(j + 20, i + 10);
				glVertex2i(j + 10, i + 10);
				glEnd();
				glFlush();
			}
			else
			{
				glColor3f(1.0, 1.0, 1.0);
				glBegin(GL_POLYGON);
				glVertex2i(j, i);
				glVertex2i(j + 10, i);
				glVertex2i(j + 10, i + 10);
				glVertex2i(j, i + 10);
				glEnd();
				glFlush();
			}
			
		}
	}
}
void Init()
{
	glClearColor(0.0,0.0,0.0,0);
	gluOrtho2D(10,90,10,90);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(620,620);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Chess Board");
	Init();
	glutDisplayFunc(ChessBoard);
	glutMainLoop();
	return 0;
}