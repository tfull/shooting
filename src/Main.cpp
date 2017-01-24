#include <GL/glut.h>
#include "Game.h"
#include "Keyboard.h"
#include <iostream>

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

const int SCENE_COUNT_MAX = 1000000;

enum Scene{
    S_START, S_SHOP, S_SELECT, S_GAME
};

namespace object{
    Scene scene = S_START;
    int scene_count = 0;
    static Game *game = new Game();
    static Keyboard *keyboard = new Keyboard();
}

void changeScene(Scene scene){
    object::scene = scene;
    object::scene_count = 0;
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
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor4f(0.1, 0.4, 0.5, 0.0);
    glRectf(-0.5, 0.5, 0.5, -0.5);
    glFlush();
}

void display(){
    if(object::scene == S_START){
        displayStart();
    }else if(object::scene == S_SHOP){
        displayShop();
    }else if(object::scene == S_SELECT){
        displaySelect();
    }else if(object::scene == S_GAME){
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
  if(object::scene_count > 5 && object::keyboard->getCharCount('n') > 0){
      changeScene(S_GAME);
  }
}

void operateShop(){
}

void operateSelect(){
}

void operateGame(){
    if(object::scene_count > 5 && object::keyboard->getCharCount('a') > 0){
        changeScene(S_START);
    }
}

void operate(int value){
    object::keyboard->update();
    object::scene_count += 1;
    if(object::scene_count > SCENE_COUNT_MAX){
        object::scene_count = SCENE_COUNT_MAX;
    }

    std::cout << "a: " << object::keyboard->getCharCount('a') << std::endl;

    if(object::scene == S_START){
        operateStart();
    }else if(object::scene == S_SHOP){
        operateShop();
    }else if(object::scene == S_SELECT){
        operateSelect();
    }else if(object::scene == S_GAME){
        operateGame();
    }

    glutPostRedisplay();

    glutTimerFunc(50, operate, 0);
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
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
