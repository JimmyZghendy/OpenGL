#include<gl/glut.h>
#include<string>
using namespace std;
string month[12] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
float monthdata[12] = { 18.754, 145.234, 78.567, 92.001, 6.789, 123.456, 199.999, 54.321, 167.89, 33.678, 88.432, 177.654 };



void init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 20.0, 0.0, 300.0);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3i(1, 1, 1);
	for (int i = 0; i < 12; i++) {
		glRasterPos2d(i*1.5+1,5);
		for (char monthName : month[i]) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,monthName);
		}
	}

	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < 12; i++) {
		glVertex2d(i * 1.5 + 1.3, monthdata[i]+5);
	}
	glEnd();

	for (int i = 0; i < 12; i++) {
		glRasterPos2d(i*1.5+1.22,monthdata[i]+0.5);
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '*');
	}
	glFlush();
}


void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Graph");

	init();
	glutDisplayFunc(display);
	glutMainLoop();
}