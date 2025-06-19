// ConsoleApplication1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <GL/glut.h>
class point {
public:
	GLfloat x, y;
};
void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 400.0, 0.0, 300.0);

}

void  parameterizedHouse(point peak, GLint width, GLint height)
{
	glBegin(GL_LINE_LOOP);
	glVertex2i(peak.x, peak.y); // draw the shell of house
	glVertex2i(peak.x-width/2, peak.y-3*height/8);
	glVertex2i(peak.x - width / 2, peak.y - height);
	glVertex2i(peak.x + width/2 , peak.y - height);
	glVertex2i(peak.x + width / 2, peak.y - 3 * height / 8);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(peak.x - width / 4, peak.y - 3 * height / 16); // draw the cheminee
	glVertex2i(peak.x - width / 4, peak.y);
	glVertex2i(peak.x - width / 8, peak.y);
	glVertex2i(peak.x - width / 8, peak.y -3* height /32);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2i(peak.x - 3 * width / 8, peak.y -height); // draw the door
	glVertex2i(peak.x - 3 * width / 8, peak.y-6*height/8);
	glVertex2i(peak.x -width/8, peak.y - 6 * height /8);
	glVertex2i(peak.x - width / 8, peak.y - height);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2i(peak.x + 1 * width / 8, peak.y - 5*height/8); // draw the window
	glVertex2i(peak.x + 3 * width / 8, peak.y - 5 * height / 8);
	glVertex2i(peak.x + 3 * width / 8, peak.y -4* height / 8);
	glVertex2i(peak.x + 1 * width / 8, peak.y - 4 * height / 8);
	glEnd();
}


void village(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.4, 0.2);
	point peak;
	peak.x = 50;
	peak.y = 120;
	int width = 40;
	int height = 60;
	parameterizedHouse(peak, width, height);
	peak.x = 120;
	peak.y = 120;
	width = 60;
	height = 80;
	parameterizedHouse(peak, width, height);
	peak.x = 190;
	peak.y = 120;
	width = 60;
	height = 100;
	parameterizedHouse(peak, width, height);
	peak.x = 240;
	peak.y = 60;
	width = 30;
	height = 30;
	parameterizedHouse(peak, width, height);
	glFlush();
}

void main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("drawing points");
	init();
	glutDisplayFunc(village);
	glutMainLoop();
}
