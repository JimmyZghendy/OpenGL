	#include<gl/glut.h>
#include<iostream>

void init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 4.0, -1.5, 1.5); 
}
float f(float x) {
	double pi = 3.141592653589793238;
	return exp(-x) * cos((2 * pi) * x);
}

void drawFunction() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);  //GL_LINE_STRIP
	for (float x = 0; x < 4.0; x += 0.01) { // btemche 0.01 step
		glVertex2f(x, f(x));
	}
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(0, 0);
		glVertex2f(4, 0);
	glEnd();
	glFlush();
}

void main(int argc,char** argv) {
	glutInit(&argc,argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Function:");

	init();
	glutDisplayFunc(drawFunction);
	glutMainLoop();
}
