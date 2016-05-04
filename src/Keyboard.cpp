#include "Keyboard.h"
#include <map>
#include <iostream>

struct Keyboard::Property{
    bool char_down[256];
    int char_count[256];
    std::map<int, bool> special_down;
    std::map<int, int> special_count;

    Property(){
        for(int i = 0; i < 256; i++){
            this->char_down[i] = false;
            this->char_count[i] = 0;
        }
    }
};

Keyboard::Keyboard(){
    this->property = new Keyboard::Property();
}

Keyboard::~Keyboard(){
    delete this->property;
}

void Keyboard::charDown(unsigned char c){
    this->property->char_down[c] = true;
}

void Keyboard::charUp(unsigned char c){
    this->property->char_down[c] = false;
}

void Keyboard::specialDown(int i){
    this->property->special_down[i] = true;
}

void Keyboard::specialUp(int i){
    this->property->special_down[i] = false;
}

int Keyboard::getCharCount(unsigned char c){
    return this->property->char_count[c];
}

int Keyboard::getSpecialCount(int i){
    std::map<int, int>::iterator it = this->property->special_count.find(i);

    if(it == this->property->special_count.end()){
        return 0;
    }else{
        return it->second;
    }
}

void Keyboard::update(){
    for(int i = 0; i < 256; i++){
        if(this->property->char_down[i]){
            this->property->char_count[i] += 1;
        }else{
            this->property->char_count[i] = 0;
        }
    }

    for(std::map<int, bool>::iterator it = this->property->special_down.begin(); it != this->property->special_down.end(); it++){
        if(this->property->special_count.find(it->first) == this->property->special_count.end()){
            this->property->special_count[it->first] = it->second ? 1 : 0;
        }else{
            if(it->second){
                this->property->special_count[it->first] += 1;
            }else{
                this->property->special_count[it->first] = 0;
            }
        }
    }
}
