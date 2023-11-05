#include <iostream>
#include <glut.h>
#include <cstdlib> 
#include<cmath>

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
float positions[] = {222.5 , 477.5};
float winLineY = 600;
float line1Y = 600;
float line2Y = 400;
float line3Y = 200;
float line4Y = 0;
float tree1TranslateY = 0;
float tree2TranslateY = 0;
bool crashed = false;
bool win = false;
Car playerCar = createCar(222.5 , 10.0f , navyBlue);
Car obstacleCar = createCar(477.5, 750.0f, fireRed);
int cnt = 0;
int gameTime = 200;
float gap = 25;

void black(float x , float y) {
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(x, y);
    glVertex2d(x + gap, y);
    glVertex2d(x + gap, y - gap);
    glVertex2d(x , y - gap);
    glEnd();
}

void white(float x, float y) {
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2d(x, y);
    glVertex2d(x + gap, y);
    glVertex2d(x + gap, y - gap);
    glVertex2d(x, y - gap);
    glEnd();
}

void displayWinLine() {
    glPushMatrix();
    glTranslated(150.0f, winLineY + gap , 0);
    bool isBlack = true;
    for (float i = 0; i < 500; i+= gap) {
        if (isBlack) black(i, gap);
        else white(i, gap);
        isBlack = !isBlack;
    }
    isBlack = false;
    for (float i = 0; i < 500; i += gap) {
        if (isBlack) black(i, gap * 2);
        else white(i, gap * 2);
        isBlack = !isBlack;
    }
    glPopMatrix();
}

void loseMessage() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // Set text color to white

    // Set the position for the text
    glRasterPos2f(250, 300);

    // Display the text
    std::string text = "Game Over XD! press r to play again";
    for (char c : text) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }

    glutSwapBuffers();
}
void winMessage() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // Set text color to white

    // Set the position for the text
    glRasterPos2f(170, 300);

    // Display the text
    std::string text = "Winner Winner Chicken Dinner ! press r to play again ";
    for (char c : text) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }

    glutSwapBuffers();
}

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

void showObstacleCar() {
    if (obstacleCar.translateY <= -150.0) {
        obstacleCar.translateY = 750;
        obstacleCar.translateX = positions[rand() % 2];
        obstacleCar.color = colors[rand() % 4];
    }
    glPushMatrix();
    glTranslated(50 + obstacleCar.translateX, 75.5 + obstacleCar.translateY, 0);
    glRotated(180, 0, 0, 1);
    glTranslated(-(50 + obstacleCar.translateX), -(75 + obstacleCar.translateY), 0);
    car(obstacleCar);
    glPopMatrix();
}

void timer1(int valu) {

    if (!crashed && !win) {
        cnt += 1;
        if (cnt >= gameTime) {
            winLineY -= 10;
        }
        line1Y -= 10;
        line2Y -= 10;
        line3Y -= 10;
        line4Y -= 10;
        tree1TranslateY -= 10;
        tree2TranslateY -= 10;
        obstacleCar.translateY -= 10;
        if (line1Y <= 0) line1Y = 800;
        if (line2Y <= 0) line2Y = 800;
        if (line3Y <= 0) line3Y = 800;
        if (line4Y <= 0) line4Y = 800;
        if (tree1TranslateY <= -350) tree1TranslateY = 550;
        if (tree2TranslateY <= -450) tree2TranslateY = 350;
        glutPostRedisplay();

        glutTimerFunc(50, timer1, 0);		//1000 milliseconds
    }
}

void playAgain() {
    playerCar = createCar(222.5, 10.0f, navyBlue);
    obstacleCar = createCar(477.5, 750.0f, fireRed);
     line1Y = 600;
     winLineY = 600;
     cnt = 0;
     line2Y = 400;
     line3Y = 200;
     line4Y = 0;
     win = false;
     tree1TranslateY = 0;
     tree2TranslateY = 0;
     crashed = false;
     glutTimerFunc(0, timer1, 0);
     
     cout << crashed;
}

void my_keyboard(unsigned char key, int x, int y) {
    if (crashed || win) {
        switch (key) {
        case 'r':
            playAgain();
            break;

        default:
            break;
        }
        glutPostRedisplay();
    }
}

void specFunc(int key, int x, int y) {
    if (!crashed && !win) {
        switch (key)
        {
        case GLUT_KEY_RIGHT:
            playerCar.translateX += 10;
            break;
        case GLUT_KEY_LEFT:
            playerCar.translateX -= 10;
            break;
        case GLUT_KEY_DOWN:
            obstacleCar.translateY -= 10;
            break;
        default:
            break;
        }
        if (playerCar.translateX < 150)
            playerCar.translateX = 150;
        if (playerCar.translateX > 550)
            playerCar.translateX = 550;
        glutPostRedisplay();
    }
}

void checkCrash() {
    float playerCarRightXPoint = playerCar.translateX + 50;
    float playerCarLeftXPoint = playerCar.translateX - 50;
    float obstacleCarRightXPoint = obstacleCar.translateX + 50;
    float obstacleCarLeftXPoint = obstacleCar.translateX - 50;

    float playerCarTopYPoint = playerCar.translateY + 150;
    float playerCarBottomYPoint = playerCar.translateY;
    float obstacleCarTopYPoint = obstacleCar.translateY + 150;
    float obstacleCarBottomYPoint = obstacleCar.translateY;

    if (playerCarRightXPoint >= obstacleCarLeftXPoint &&
        playerCarRightXPoint <= obstacleCarRightXPoint &&
        (
            playerCarBottomYPoint <= obstacleCarTopYPoint && playerCarBottomYPoint >= obstacleCarBottomYPoint ||
            playerCarTopYPoint <= obstacleCarTopYPoint && playerCarTopYPoint >= obstacleCarBottomYPoint
            )
        )
    {
        crashed = true;
    }

    if (playerCarLeftXPoint >= obstacleCarLeftXPoint &&
        playerCarLeftXPoint <= obstacleCarRightXPoint &&
        (
            playerCarBottomYPoint <= obstacleCarTopYPoint && playerCarBottomYPoint >= obstacleCarBottomYPoint ||
            playerCarTopYPoint <= obstacleCarTopYPoint && playerCarTopYPoint >= obstacleCarBottomYPoint
            )
        ){
        crashed = true;
        }
}

void checkWin() {
    if (winLineY <= -75)
        win = true;
}




void Display()
{
    // Clear the screen buffer
    glClear(GL_COLOR_BUFFER_BIT);
   
    background();
    checkCrash();
    checkWin();
    if (!crashed && cnt >= gameTime)
        displayWinLine();
    car(playerCar);
    showObstacleCar();
    if (crashed && !win)
        loseMessage();
    if (!crashed && win)
        winMessage();
  
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
    glutKeyboardFunc(my_keyboard);
    //glutMouseFunc(my_mouse_function);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glClearColor(0.2f, 0.2f, 0.2f, 0.9f);
    gluOrtho2D(0.0, 800, 0.0, 600);



    glutMainLoop();
}
