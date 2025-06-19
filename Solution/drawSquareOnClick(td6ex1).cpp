#include <gl/glut.h>
#include <iostream>
#include <vector>
using namespace std;

float l = 0.02;
vector<pair<float, float>> squarePositions;

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-2, 2, -2, 2);
    glMatrixMode(GL_MODELVIEW);
}

void mouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        float xpos = (float)x / glutGet(GLUT_WINDOW_WIDTH) * 4.0 - 2.0;
        float ypos = (float)(glutGet(GLUT_WINDOW_HEIGHT) - y) / glutGet(GLUT_WINDOW_HEIGHT) * 4.0 - 2.0;
        squarePositions.push_back(make_pair(xpos, ypos));
        glutPostRedisplay();
    }
}

void drawSquare() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);


    for (const auto& pos : squarePositions) {
        glBegin(GL_QUADS);
        glVertex2f(pos.first - l, pos.second + l);
        glVertex2f(pos.first - l, pos.second - l);
        glVertex2f(pos.first + l, pos.second - l);
        glVertex2f(pos.first + l, pos.second + l);
        glEnd();
    }

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Square drawing");

    init();
    glutDisplayFunc(drawSquare);
    glutMouseFunc(mouseClick);
    glutMainLoop();

    return 0;
}
