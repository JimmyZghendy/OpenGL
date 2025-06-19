#include<gl/glut.h>

void init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2i(10, 50);
	glVertex2i(150, 50);
	glVertex2i(10, 100);
	glVertex2i(150, 100);
	glVertex2i(50, 10);
	glVertex2i(50, 140);
	glVertex2i(100, 10);
	glVertex2i(100, 140);
	glEnd();
	glFlush();
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(400, 300);
	glutCreateWindow("ex1: Hashtag");


	init();
	glutDisplayFunc(display);
	glutMainLoop();



}

