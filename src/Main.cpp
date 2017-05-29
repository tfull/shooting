#include <GL/glut.h>
#include "Game.hpp"
#include "Keyboard.hpp"
#include "Constant.hpp"
#include "Extention.hpp"
#include <iostream>
#include <cstdio>
#include <cstdlib>

const int SCENE_COUNT_MAX = 1000000;

enum Scene{
    S_START, S_SHOP, S_SELECT, S_GAME
};

namespace object{
    Scene scene = S_START;
    int scene_count = 0;
    static Game *game = new Game();
    static Keyboard *keyboard = new Keyboard();
    int selected_stage = 1;
    int opened_stage = 10;
}

void changeScene(Scene scene){
    object::scene = scene;
    object::scene_count = 0;
}

void displayStart(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    //glColor4f(0.7, 0.2, 0.2, 0.0);
    //glRectf(-0.5, 0.5, 0.5, -0.5);
    glColor4f(1.0, 1.0, 1.0, 0.0);
    glRasterPos2d(0.0, 0.0);
    drawString(GLUT_BITMAP_HELVETICA_18, (char*)"Shooting");
    glFlush();
}

void displayShop(){
}

void displaySelect(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor4f(0.4, 0.1, 0.2, 0.0);
    glRectf(-0.5, 0.5, 0.5, -0.5);
    glColor4f(1.0, 1.0, 1.0, 0.0);
    glRasterPos2d(0.0, 0.0);
    char s[10];
    std::sprintf(s, "%d", object::selected_stage);
    drawString(GLUT_BITMAP_HELVETICA_18, s);
    glFlush();
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
    if(object::scene_count > 5 && object::keyboard->getCharCount(KEYBOARD_ENTER) > 0){
        changeScene(S_SELECT);
    }
}

void operateShop(){
}

void operateSelect(){
    if(object::scene_count > 5 && object::keyboard->getCharCount(KEYBOARD_ENTER) > 0){
        // select 
        changeScene(S_GAME);
    }else if(object::scene_count > 5 && object::keyboard->getSpecialCount(GLUT_KEY_UP) % 5 == 1){
        if(object::selected_stage > 1){
            object::selected_stage -= 1;
        }
    }else if(object::scene_count > 5 && object::keyboard->getSpecialCount(GLUT_KEY_DOWN) % 5 == 1){
        if(object::selected_stage < object::opened_stage){
            object::selected_stage += 1;
        }
    }
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
