#include <GL/glut.h>
#include "Game.h"
#include "Keyboard.h"
#include <iostream>

const int screen_width = 640;
const int screen_height = 360;

namespace Object{
    static Game *game = new Game();
    static Keyboard *keyboard = new Keyboard();
}

void display(){
}

void keyboardDown(unsigned char c, int x, int y){
    Object::keyboard->charDown(c);
}

void keyboardUp(unsigned char c, int x, int y){
    Object::keyboard->charUp(c);
}

void specialDown(int i, int x, int y){
    Object::keyboard->specialDown(i);
}

void specialUp(int i, int x, int y){
    Object::keyboard->specialUp(i);
}

void operate(int value){
    Object::keyboard->update();

    std::cout << "a: " << Object::keyboard->getCharCount('a') << std::endl;

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
