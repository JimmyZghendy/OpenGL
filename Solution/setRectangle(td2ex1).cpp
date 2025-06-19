#include<gl/glut.h>
#include<iostream>
#include<ctime>

void init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 800.0, 0.0, 600.0);
}

void drawRectangle(int width, int height, int x, int y) {
	glBegin(GL_QUADS);
	glVertex2i(x, y);
	glVertex2i(x + width, y);
	glVertex2i(x + width, y + height);
	glVertex2i(x, y + height);
	glEnd();
}

void draw2Rectangle() {
	int x, y, height, width;
	glClear(GL_COLOR_BUFFER_BIT);
	srand(time(0));
	for (int i = 0; i < 2; i++) {
		x = rand() % 600;
		y = rand() % 400;
		height = rand() % 200;
		width = rand() % 200;
		glColor3f(0.0, 0.0, 0.0);
		drawRectangle(width, height, x, y);
	}
	glFlush();
}
void drawSetRectangle() {
	int x, y, height, width;
	float r, g, b;
	int n;
	n = rand() % 20;
	glClear(GL_COLOR_BUFFER_BIT);
	srand(time(0));
	for (int i = 0; i < n; i++) {
		x = rand() % 600;
		y = rand() % 400;
		height = rand() % 200;
		width = rand() % 200;
		r = (float)(rand() % 255) / 255;
		g = (float)(rand() % 255) / 255;
		b = (float)(rand() % 255) / 255;
		glColor3f(r, g, b);
		drawRectangle(width, height, x, y);
	}
	glFlush();
}



void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Draw Rectangles");

	init();
	glutDisplayFunc(drawSetRectangle);
	glutMainLoop();

}