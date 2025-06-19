#include<gl/glut.h>

void init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 400.0, 0.0, 300.0);
}

void houseBuild(float x,float y) {
	//house walls and floor
	glBegin(GL_LINES);
	glVertex2i(40 + x, 40 + y);
	glVertex2i(40 + x, 100 + y);
	glVertex2i(100 + x, 40 + y);
	glVertex2i(100 + x, 100 + y);
	glVertex2i(40 + x, 40 + y);
	glVertex2i(100 + x, 40 + y);
	glEnd();
	//house roof
	glBegin(GL_LINES);
	glVertex2i(40 + x, 100 + y);
	glVertex2i(70 + x, 120 + y);
	glVertex2i(100 + x, 100 + y);
	glVertex2i(70 + x, 120 + y);
	glEnd();
	//door
	glBegin(GL_LINE_LOOP);
	glVertex2i(50 + x, 40 + y);
	glVertex2i(50 + x, 80 + y);
	glVertex2i(60 + x, 80 + y);
	glVertex2i(60 + x, 40 + y);
	glEnd();
	//window
	glBegin(GL_LINE_LOOP);
	glVertex2i(75 + x, 80 + y);
	glVertex2i(75 + x, 90 + y);
	glVertex2i(85 + x, 90 + y);
	glVertex2i(85 + x, 80 + y);
	glEnd();
	//chimney
	glBegin(GL_LINE_LOOP);
	glVertex2i(45 + x, 103 + y);
	glVertex2i(45 + x, 120 + y);
	glVertex2i(53 + x, 120 + y);
	glVertex2i(53 + x, 109 + y);
	glEnd();

	glFlush();
}
void buildVillage() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	houseBuild(-35, 1); 
	houseBuild(10, 100);
	houseBuild(100, 1);
	houseBuild(150, 100);
	
	glFlush();
}



void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutCreateWindow("ex2: village");

	init();
	glutDisplayFunc(buildVillage);
	glutMainLoop();

}