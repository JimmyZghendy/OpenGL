#include<gl/glut.h>
#include<iostream>
#include<cmath>
using namespace std;

void init() {
	glClearColor(1, 1, 1,0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,800.0,0.0, 600);
}
pair<int, int> newPoint(pair<int, int> p) {
	pair<int, int> q;
	int qx, qy,M=40,L=3;
	qx = M * (1 + 2 * L) - p.second + abs(p.first - L * M);
	qy = p.first;
	q = make_pair(qx, qy);
	return q;
}
void gingerBread(pair<int,int> p) {
	int x, y;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3i(0, 0, 0);
	glBegin(GL_POINTS);
	for (int i = 0; i < 5000; i++) {
		x = p.first;
		y = p.second;
		glVertex2d(x, y);
		p = newPoint(p);
	}
	glEnd();
	glFlush();
}

void display() {
	int x, y;
	pair<int,int> p;
	cout << "Enter x:";
	cin >> x;
	cout << "Enter y:";
	cin >> y;
	p = make_pair(x, y);
	gingerBread(p);
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Gingerbread Man");

	init();
	glutDisplayFunc(display);
	glutMainLoop();
}