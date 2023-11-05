#include <iostream>
#include <glut.h>
#include <cstdlib> 

using namespace std;

struct rgb {
    float red;
    float green;
    float blue;
};

struct Car {
    float translateX;
    float translateY;
    rgb color;
};

rgb createColor(float r , float g , float b) {
    rgb newColor;
    newColor.red = r / 255;
    newColor.green = g / 255;
    newColor.blue = b / 255;
    return newColor;
}

Car createCar(float x , float y , rgb carColor) {
    Car newCar;
    newCar.translateX = x;
    newCar.translateY = y;
    newCar.color = carColor;
    return newCar;
}

rgb navyBlue = createColor(0.0f , 45.0f , 114.0f);
rgb limeGreen = createColor(0.0f , 177.0f , 64.0f);
rgb fireRed = createColor(200.0f, 16.0f, 46.0f);
rgb pink = createColor(189.0f, 0.0f, 126.0f);
rgb colors[] = {navyBlue , limeGreen , fireRed , pink};

float line1Y = 600;
float line2Y = 400;
float line3Y = 200;
float line4Y = 0;
float tree1TranslateY = 0;
float tree2TranslateY = 0;
Car playerCar = createCar(0.0f , 0.0f , navyBlue);

void trunk1() {
    glBegin(GL_POLYGON);
    glColor3f(0.91f, 0.17f, 0.0f);
    glVertex2d(55.0f, 150.0f);
    glVertex2d(55.0f, 50.0f);
    glVertex2d(95.0f, 50.0f);
    glVertex2d(95.0f, 150.0f);
    glEnd();
}

void tree1() {
;   glPushMatrix();
    glTranslated(0.0f, tree1TranslateY , 0);
    trunk1();
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, .5f, 0.0f);
    glVertex3f(35.0f, 150.0f, 0.0f);
    glVertex3f(115.0f, 150.0f, 0.0f);
    glVertex3f(75.0f, 250.0f, 0.0f);
    glEnd();
    glPopMatrix();

}

void trunk2() {
    glBegin(GL_POLYGON);
    glColor3f(0.91f, 0.17f, 0.0f);
    glVertex2d(705.0f, 350.0f);
    glVertex2d(705.0f, 250.0f);
    glVertex2d(745.0f, 250.0f);
    glVertex2d(745.0f, 350.0f);
    glEnd();
}

void tree2() {
    glPushMatrix();
    glTranslated(0.0f, tree2TranslateY, 0);
    trunk2();
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, .5f, 0.0f);
    glVertex3f(685.0f, 350.0f, 0.0f);
    glVertex3f(765.0f, 350.0f, 0.0f);
    glVertex3f(725.0f, 450.0f, 0.0f);
    glEnd();
    glPopMatrix();

}

void leftSideWalk() {
    glBegin(GL_POLYGON);
    glColor3f(0.6f, 0.9f, 0.6f);
    glVertex2d(0.0f, 600.0f);
    glVertex2d(0.0f, 0.0f);
    glVertex2d(150.0f, 0.0f);
    glVertex2d(150.0f, 600.0f);
    glEnd();
}

void rightSideWalk() {
    glBegin(GL_POLYGON);
    glColor3f(0.6f, 0.9f, 0.6f);
    glVertex2d(650.0f, 600.0f);
    glVertex2d(650.0f, 0.0f);
    glVertex2d(800.0f, 0.0f);
    glVertex2d(800.0f, 600.0f);
    glEnd();
}

void streetLine() {
    glBegin(GL_POLYGON);
    glColor3f(0.96f, 0.7f, 0.0f);
    glVertex2d(395.0f, line1Y);
    glVertex2d(395.0f, line1Y - 100);
    glVertex2d(405.0f, line1Y - 100);
    glVertex2d(405.0f, line1Y);
    glEnd();
    glBegin(GL_POLYGON);
    //glColor3f(0.96f, 0.7f, 0.0f);
    glVertex2d(395.0f, line2Y);
    glVertex2d(395.0f, line2Y - 100);
    glVertex2d(405.0f, line2Y - 100);
    glVertex2d(405.0f, line2Y);
    glEnd();
    glBegin(GL_POLYGON);
    //glColor3f(0.96f, 0.7f, 0.0f);
    glVertex2d(395.0f, line3Y);
    glVertex2d(395.0f, line3Y - 100);
    glVertex2d(405.0f, line3Y - 100);
    glVertex2d(405.0f, line3Y);
    glEnd();
    glBegin(GL_POLYGON);
    //glColor3f(0.96f, 0.7f, 0.0f);
    glVertex2d(395.0f, line4Y);
    glVertex2d(395.0f, line4Y - 100);
    glVertex2d(405.0f, line4Y - 100);
    glVertex2d(405.0f, line4Y);
    glEnd();
}

void background() {
    rightSideWalk();
    leftSideWalk();
    streetLine();
    tree1();
    tree2();
}

void car(Car newCar) {

    glPushMatrix();
    glTranslated(newCar.translateX, newCar.translateY , 0);
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(0.0f, 100.0f);
    glVertex2d(10.0f, 130.0f);
    glVertex2d(20.0f, 150.0f);
    glVertex2d(80.0f, 150.0f);
    glVertex2d(90.0f, 130.0f);
    glVertex2d(100.0f, 100.0f);
    glVertex2d(100.0f, 20.0f);
    glVertex2d(90.0f, 0.0f);
    glVertex2d(10.0f, 0.0f);
    glVertex2d(0.0f, 20.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(newCar.color.red, newCar.color.green, newCar.color.blue);
    glVertex2d(2.0f, 100.0f);
    glVertex2d(12.0f, 130.0f);
    glVertex2d(22.0f, 148.0f);
    glVertex2d(78.0f, 148.0f);
    glVertex2d(88.0f, 130.0f);
    glVertex2d(98.0f, 100.0f);
    glVertex2d(98.0f, 20.0f);
    glVertex2d(88.0f, 2.0f);
    glVertex2d(12.0f, 2.0f);
    glVertex2d(2.0f, 20.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(10.0f, 100.0f);
    glVertex2d(20.0f, 130.0f);
    glVertex2d(30.0f, 150.0f);
    glVertex2d(70.0f, 150.0f);
    glVertex2d(80.0f, 130.0f);
    glVertex2d(90.0f, 100.0f);
    glVertex2d(90.0f, 20.0f);
    glVertex2d(80.0f, 6.0f);
    glVertex2d(20.0f, 6.0f);
    glVertex2d(10.0f, 20.0f);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(newCar.color.red, newCar.color.green, newCar.color.blue);
    glVertex2d(12.0f, 100.0f);
    glVertex2d(22.0f, 130.0f);
    glVertex2d(32.0f, 148.0f);
    glVertex2d(68.0f, 148.0f);
    glVertex2d(78.0f, 130.0f);
    glVertex2d(88.0f, 100.0f);
    glVertex2d(88.0f, 20.0f);
    glVertex2d(78.0f, 8.0f);
    glVertex2d(22.0f, 8.0f);
    glVertex2d(12.0f, 20.0f);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(15.0f, 100.0f);
    glVertex2d(85.0f, 100.0f);
    glVertex2d(75.0f, 75.0f);
    glVertex2d(25.0f, 75.0f);
    glEnd();
   
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(12.0f, 95.0f);
    glVertex2d(25.0f, 65.0f);
    glVertex2d(25.0f, 55.0f);
    glVertex2d(12.0f, 55.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(88.0f, 95.0f);
    glVertex2d(75.0f, 65.0f);
    glVertex2d(75.0f, 55.0f);
    glVertex2d(88.0f, 55.0f);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(15.0f, 20.0f);
    glVertex2d(85.0f, 20.0f);
    glVertex2d(75.0f, 35.0f);
    glVertex2d(25.0f, 35.0f);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(12.0f, 25.0f);
    glVertex2d(25.0f, 40.0f);
    glVertex2d(25.0f, 50.0f);
    glVertex2d(12.0f, 50.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(88.0f, 25.0f);
    glVertex2d(75.0f, 40.0f);
    glVertex2d(75.0f, 50.0f);
    glVertex2d(88.0f, 50.0f);
    glEnd();
    
    glPopMatrix();
}

void timer1(int valu) {
    line1Y -= 10;
    line2Y -= 10;
    line3Y -= 10;
    line4Y -= 10;
    tree1TranslateY -= 10;
    tree2TranslateY -= 10;
    if (line1Y <= 0) line1Y = 800;
    if (line2Y <= 0) line2Y = 800;
    if (line3Y <= 0) line3Y = 800;
    if (line4Y <= 0) line4Y = 800;
    if (tree1TranslateY <= -350) tree1TranslateY = 550;
    if (tree2TranslateY <= -450) tree2TranslateY = 350;
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
    background();
    car(playerCar);
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
    glClearColor(0.2f, 0.2f, 0.2f, 0.9f);
    gluOrtho2D(0.0, 800, 0.0, 600);



    glutMainLoop();
}
