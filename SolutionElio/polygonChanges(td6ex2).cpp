#include<gl/glut.h>
#include<iostream>
#include<cmath>
using namespace std;

struct wcPt2d {
	float x, y;
};

wcPt2d* verts = nullptr,pivot;
float l=50.0,theta= 3.14159/4;

void init() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 800.0, 0.0,800.0);
	glMatrixMode(GL_MODELVIEW);
}	

void translate(float dx, float dy) {
	for (int i = 0; i < sizeof(verts); i++) {
		verts[i].x = verts[i].x + dx;
		verts[i].y = verts[i].y + dy;
	}
	pivot.x += dx;
	pivot.y += dy;
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < sizeof(verts); i++) {
		glVertex2f(verts[i].x, verts[i].y);
	}
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glPointSize(5.0);
	glBegin(GL_POINTS);
	glVertex2f(pivot.x, pivot.y);
	glEnd();
}

void rotate() {
	for (int i = 0; i < sizeof(verts); i++) {
		float dx = verts[i].x - pivot.x;
		float dy = verts[i].y - pivot.y;
		verts[i].x = pivot.x + dx * cos(theta) - dy * sin(theta);
		verts[i].y = pivot.y + dx * sin(theta) + dy * cos(theta);
	}
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < sizeof(verts); i++) {
		glVertex2f(verts[i].x, verts[i].y);
	}
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glPointSize(5.0);
	glBegin(GL_POINTS);
	glVertex2f(pivot.x, pivot.y);
	glEnd();
}

void scale(float sx,float sy) {
	for (int i = 0; i < sizeof(verts); i++) {
		verts[i].x = verts[i].x * sx + pivot.x * (1 - sx);
		verts[i].y = verts[i].y * sy + pivot.y * (1 - sy);
	}
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < sizeof(verts); i++) {
		glVertex2f(verts[i].x, verts[i].y);
	}
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glPointSize(5.0);
	glBegin(GL_POINTS);
	glVertex2f(pivot.x, pivot.y);
	glEnd();
}

void drawAxis() {
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2d(400, 0);
	glVertex2d(400, 800);
	glVertex2d(0, 400);
	glVertex2d(800, 400);
	glEnd();
}

wcPt2d* drawPolygon() {
	float x = pivot.x;
	float y = pivot.y;
	wcPt2d* polygonVerts = new wcPt2d[4];
	glBegin(GL_POLYGON);
	glVertex2f(x, y);
	polygonVerts[0].x = x;
	polygonVerts[0].y = y;
	glVertex2f(x, y + l);
	polygonVerts[1].x = x;
	polygonVerts[1].y = y+l;
	glVertex2f(x + l, y + l);
	polygonVerts[2].x = x+l;
	polygonVerts[2].y = y+l;
	glVertex2f(x + l, y);
	polygonVerts[3].x = x+l;
	polygonVerts[3].y = y;
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glPointSize(5.0);
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();

	return polygonVerts;
}
void keyboard(unsigned char key, int mouseX, int mouseY) {
	if (key == 'M' || key == 'm') {
		float x = (float)mouseX;
		float y = (float)(glutGet(GLUT_WINDOW_HEIGHT) - mouseY);

		float distance = sqrt(pow((x - 400), 2) + pow((y - 400), 2));

		float scale_factor = 1.0f;
		if (distance > 200) {
			scale_factor = distance / 400;
		}
		else { 
			scale_factor = 200 / distance; 
		}
		glClear(GL_COLOR_BUFFER_BIT);
		translate(-pivot.x, -pivot.y);
		glClear(GL_COLOR_BUFFER_BIT);
		rotate();
		glClear(GL_COLOR_BUFFER_BIT);
		scale(scale_factor, scale_factor);
		glClear(GL_COLOR_BUFFER_BIT);
		drawAxis();
		translate(x,y);
	}
	glFlush();
}


void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	drawAxis();
	pivot.x = 420.0;
	pivot.y = 450.0;
	verts=drawPolygon();
	glFlush();
}





int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutCreateWindow("polygon");

	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);

	glutMainLoop();
	return 0;
}