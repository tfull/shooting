#ifndef __GAME_H__
#define __GAME_H__

#include "Keyboard.h"

enum Mode{
    M_STAGE, M_PLAY
};

class Game{
    Mode mode;
    void operate();
    void run();
public:
    Game();
    ~Game();
    void start();
};

#endif
