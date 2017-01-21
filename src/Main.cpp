#include <GL/glut.h>
#include "Game.h"
#include "Keyboard.h"
#include <iostream>

const int screen_width = 640;
const int screen_height = 360;

enum Mode{
    M_START, M_SHOP, M_SELECT, M_GAME
};

namespace object{
    Mode mode = M_START;
    static Game *game = new Game();
    static Keyboard *keyboard = new Keyboard();
}

void displayStart(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor4f(0.7, 0.2, 0.2, 0.0);
    glRectf(-0.5, 0.5, 0.5, -0.5);
    glFlush();
}

void displayShop(){
}

void displaySelect(){
}

void displayGame(){
}

void display(){
    if(object::mode == M_START){
        displayStart();
    }else if(object::mode == M_SHOP){
        displayShop();
    }else if(object::mode == M_SELECT){
        displaySelect();
    }else if(object::mode == M_GAME){
        displayGame();
    }
}

void keyboardDown(unsigned char c, int x, int y){
    object::keyboard->charDown(c);
}

void keyboardUp(unsigned char c, int x, int y){
    object::keyboard->charUp(c);
}

void specialDown(int i, int x, int y){
    object::keyboard->specialDown(i);
}

void specialUp(int i, int x, int y){
    object::keyboard->specialUp(i);
}

void operateStart(){
}

void operateShop(){
}

void operateSelect(){
}

void operateGame(){
}

void operate(int value){
    object::keyboard->update();

    // std::cout << "a: " << object::keyboard->getCharCount('a') << std::endl;

    if(object::mode == M_START){
        operateStart();
    }else if(object::mode == M_SHOP){
        operateShop();
    }else if(object::mode == M_SELECT){
        operateSelect();
    }else if(object::mode == M_GAME){
        operateGame();
    }

    glutPostRedisplay();

    glutTimerFunc(50, operate, 0);
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(screen_width, screen_height);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Shoot!");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboardDown);
    glutKeyboardUpFunc(keyboardUp);
    glutSpecialFunc(specialDown);
    glutSpecialUpFunc(specialUp);
    glutTimerFunc(100, operate, 0);
    glutMainLoop();

    return 0;
}
