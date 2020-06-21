#include <iostream>
#include <GL\glut.h>
#include "Cubik.hpp"
#include "Display.hpp"
#define GL_SILENCE_DEPRECATION

double rotate_x = 0;
double rotate_y = 0;
CubikRubik temp;

void SpecialKeys(int key, int x, int y) {
    if (key == GLUT_KEY_RIGHT)
        rotate_y += 4;
    else if (key == GLUT_KEY_LEFT)
        rotate_y -= 4;
    else if (key == GLUT_KEY_F5)
        temp.cross_iteration();
    else if (key == GLUT_KEY_UP)
        rotate_x += 4;
    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 4;
    else if (key == GLUT_KEY_F1)
        temp.pif_paf();
    else if (key == GLUT_KEY_F2)
        temp.assembler();
    else if (key == GLUT_KEY_F3)
        temp.disassembler();
    else if (key == GLUT_KEY_F4) {
        std::cout << "EXIT\n";
        exit(EXIT_SUCCESS);
    }
    glutPostRedisplay();
}

void display() {
    glClearColor(0.4, 0.7, 0.3, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);
    glScalef(0.2, 0.2, 0.2);
    temp.draw();
    glFlush();
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(GLUT_INIT_WINDOW_WIDTH / 2, GLUT_INIT_WINDOW_HEIGHT / 2);
    glutCreateWindow("Cubik Rubik");
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glutDisplayFunc(display);
    glutSpecialFunc(SpecialKeys); 
    glutMainLoop(); 
    return 0;
}
