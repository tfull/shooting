#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__

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
};

#endif
