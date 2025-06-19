#include<gl/glut.h>
#include<iostream>
using namespace std;
#include<cmath>
#include<windows.h>

class wcPt2d {
public:
	float x, y;
};
wcPt2d* verts = nullptr, pivot,origin;


void init() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-2, 2, -2, 2);
}
void drawAxis() {
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2f(-1.5, 0);
	glVertex2f(1.5, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0, -1.5);
	glVertex2f(0, 1.5);
	glEnd();
}
wcPt2d* drawTriangle() {
	float x = pivot.x, y = pivot.y;
	wcPt2d* triangleVerts = new wcPt2d[3];
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(x - 0.5, y - 0.5);
	triangleVerts[0].x = x - 0.5;
	triangleVerts[0].y = y - 0.5;
	glVertex2f(x + 0.5, y - 0.5);
	triangleVerts[1].x = x + 0.5;
	triangleVerts[1].y = y - 0.5;
	glVertex2f(x, y + 0.5);
	triangleVerts[2].x = x;
	triangleVerts[2].y = y + 0.5;
	glEnd();

	glPointSize(5.0);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();

	return triangleVerts;
}
void translate(float tx, float ty) {
	for (int k = 0; k < sizeof(verts); k++) {
		verts[k].x = verts[k].x + tx;
		verts[k].y = verts[k].y + ty;
	}
	pivot.x += tx;
	pivot.y += ty;
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);
	for (int k = 0; k < sizeof(verts); k++) {
		glVertex2f(verts[k].x, verts[k].y);
	}
	glEnd();
	glPointSize(5.0);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POINTS);
	glVertex2f(pivot.x, pivot.y);
	glEnd();
}
void rotate(float theta) {
	for (int k = 0; k < sizeof(verts); k++) {
		float dx = verts[k].x - pivot.x;
		float dy = verts[k].y - pivot.y;
		verts[k].x = pivot.x + dx * cos(theta) - dy * sin(theta);
		verts[k].y = pivot.y + dx * sin(theta) + dy * cos(theta);
	}

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);
	for (int k = 0; k < sizeof(verts); k++) {
		glVertex2f(verts[k].x, verts[k].y);
	}
	glEnd();

	glPointSize(5.0);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POINTS);
	glVertex2f(pivot.x, pivot.y);
	glEnd();
}

void drawAndRotate() {
	int n;
	glClear(GL_COLOR_BUFFER_BIT);
	drawAxis();
	cout << "enter x:";
	cin >> pivot.x;
	cout << "enter y:";
	cin >> pivot.y;
	origin = pivot;
	verts = drawTriangle();
	glClear(GL_COLOR_BUFFER_BIT);
	drawAxis();
	translate(-origin.x, -origin.y);
	glClear(GL_COLOR_BUFFER_BIT);
	drawAxis();
	rotate(3.14159265358979323846 / 2);
	glClear(GL_COLOR_BUFFER_BIT);
	drawAxis();
	translate(origin.x, origin.y);
	glFlush();
}


void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Triangle drawing");

	init();
	glutDisplayFunc(drawAndRotate);
	glutMainLoop();
}