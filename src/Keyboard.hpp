#ifndef __KEYBOARD_HPP__
#define __KEYBOARD_HPP__

class Keyboard{
private:
    struct Property;
    Property *property;
public:
    Keyboard();
    ~Keyboard();
    void update();
    void charDown(unsigned char);
    void charUp(unsigned char);
    void specialDown(int);
    void specialUp(int);
    int getCharCount(unsigned char);
    int getSpecialCount(int);
    void printDebug();
};

#endif
