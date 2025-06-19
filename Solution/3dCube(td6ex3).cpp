#include <GL/glut.h>

GLfloat vertices[][3] = {
    {-1.0, -1.0, 1.0},   // Front bottom-left
    {1.0, -1.0, 1.0},    // Front bottom-right
    {1.0, 1.0, 1.0},     // Front top-right
    {-1.0, 1.0, 1.0},    // Front top-left
    {-1.0, -1.0, -1.0},  // Back bottom-left
    {1.0, -1.0, -1.0},   // Back bottom-right
    {1.0, 1.0, -1.0},    // Back top-right
    {-1.0, 1.0, -1.0}    // Back top-left
};

int faces[][4] = {
    {0, 1, 2, 3},   // Front face
    {4, 5, 6, 7},   // Back face
    {3, 2, 6, 7},   // Top face
    {0, 1, 5, 4},   // Bottom face
    {1, 2, 6, 5},   // Right face
    {0, 3, 7, 4}    // Left face
};

void drawCube() {
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 4; ++j) {
            glVertex3fv(vertices[faces[i][j]]);
        }
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glTranslatef(0.0, 0.0, -5.0);
    glRotatef(45, 1, 1, 1);

    drawCube();
    glutSwapBuffers();
}

void init() {
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0, 0.0, 0.0, 1.0);

    glMatrixMode(GL_PROJECTION);
    gluPerspective(60, 1.0, 1.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("3D Cube");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
