#pragma once
#include <iostream>
using namespace std;

class Fractal {
public:
    virtual void draw() = 0;
    virtual string getName() = 0;
    virtual int getLevel() = 0;
    virtual void setLevel(int n) = 0;
};