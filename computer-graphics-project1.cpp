#include <iostream>
#include <glut.h>
using namespace std;

int direction = 1;

void timer1(int valu) {
    

    glutPostRedisplay();

    glutTimerFunc(50, timer1, 0);		//1000 milliseconds
}


void specFunc(int key, int x, int y) {
    glutPostRedisplay();
}

void my_mouse_function(int button, int state, int x, int y) {

    glutPostRedisplay();
}



void Display()
{
    // Clear the screen buffer
    glClear(GL_COLOR_BUFFER_BIT);
    // Sends all output to display
    glFlush();
}

int main(int argc, char** argr) {
    glutInit(&argc, argr);

    glutInitWindowPosition(0, 0);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Car Race");
    glutDisplayFunc(Display);
    glutTimerFunc(0, timer1, 0);
    glutSpecialFunc(specFunc);
    glutMouseFunc(my_mouse_function);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glClearColor(0.0f, 0.89f, 0.89f, 0.0f);
    gluOrtho2D(0.0, 800, 0.0, 600);



    glutMainLoop();
}
