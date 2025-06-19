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
	glPolygonMode(GL_FRONT,GL_LINE);
	int p1[] = { 25,50 };
	int p2[] = { 50,10 };
	int p3[] = { 90,10 };
	int p4[] = { 115,50 };
	int p5[] = { 80,75 };
	int p6[] = { 55,75 };
	glBegin(GL_TRIANGLE_FAN);
	glVertex2iv(p1);
	glVertex2iv(p2);
	glVertex2iv(p3);
	glVertex2iv(p4);
	glVertex2iv(p5);
	glVertex2iv(p6);
	glEnd();
	/*glBegin(GL_TRIANGLE_STRIP);
	glVertex2iv(p1);
	glVertex2iv(p2);
	glVertex2iv(p6);
	glVertex2iv(p3);
	glVertex2iv(p5);
	glVertex2iv(p4);
	glEnd();*/
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
