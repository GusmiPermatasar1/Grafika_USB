#include <iostream>
#include <GL/freeglut.h>
#include <cmath>


void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);

    // Gambar kotak di atas
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(100.0, 140.0);
    glVertex2f(360.0, 140.0);
    glVertex2f(360.0, 350.0);
    glVertex2f(100.0, 350.0);
    glEnd();

    // Gambar lingkaran di dalam kotak di atas
    glColor3f(1.0, 0.0, 0.0); // Warna merah
    glBegin(GL_TRIANGLE_FAN);
    float centerX = 230.0;
    float centerY = 245.0;
    float radius = 50.0;
    int segments = 100;
    glVertex2f(centerX, centerY); // Titik tengah lingkaran
    for (int i = 0; i <= segments; i++) {
        float theta = 2.0 * 3.1415926 * float(i) / float(segments);
        float x = centerX + radius * cos(theta);
        float y = centerY + radius * sin(theta);
        glVertex2f(x, y);
    }
    glEnd();

    glFlush();
}


void myinit() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 499.0, 0.0, 499.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700, 500);
    glutInitWindowPosition(5, 10);
    glutCreateWindow("BENDERA JEPANG");
    glutDisplayFunc(display);

    myinit();
    glutMainLoop();

    return 0;
}
