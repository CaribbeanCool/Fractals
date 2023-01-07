#pragma once
#include "Fractal.hpp"
#include "ofMain.h"
#include <iostream>
#include <vector>
using namespace std;

class AbstractFractal : public Fractal {
public:    
    string name;
    int level;

    vector <ofColor> colores = {ofColor::white, ofColor::red, ofColor::yellowGreen,ofColor::greenYellow};

    AbstractFractal(){};
    AbstractFractal(string name, int level) {this->name = name; this->level = level;};

    //Getters
    string getName() { return this->name; };
    int getLevel() { return this->level; };

    //Setters
    void setLevel(int n) { this->level = n; };

    //Method/s
    virtual void draw() = 0;
};