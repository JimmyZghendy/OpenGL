// ConsoleApplication1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <GL/glut.h>

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);

}

void polygone(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.5, 0.5);
	glPolygonMode(GL_FRONT, GL_LINE);
	glBegin(GL_POLYGON);
	glVertex2i(25, 50);
	glVertex2i(50, 10);
	glVertex2i(90, 10);
	glVertex2i(115, 50);
	glVertex2i(115, 50);
	glVertex2i(80, 75);
	glVertex2i(55, 75);
	glEnd();
	glFlush();
}

void main(int argc, char ** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(400, 300);
	glutCreateWindow("an example opengl program");
	init();
	glutDisplayFunc(polygone);
	glutMainLoop();
}
