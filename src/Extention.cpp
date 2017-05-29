#include "Extention.hpp"
#include <GL/glut.h>

void drawString(void *font, const char *s){
    while(*s){
        glutBitmapCharacter(font, *s);
        s++;
    }
}
