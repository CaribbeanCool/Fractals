#pragma once
#include "AbstractFractal.hpp"
#include <cmath>

class Triangle : public AbstractFractal {
private:
    float x, y, size;

public:
    Triangle(float x, float y, float size, int n) : AbstractFractal("Sierpinski Triangle", n) {
        this->x = x;
        this->y = y;
        this->size = size;
    }

    void draw() {
        drawMode3(x, y, size, level);
    };

    void drawMode3(float x, float y, float size, int n) {
        if (n == 0) {
            return;
        }
        
        ofPoint a(x, y);
        ofPoint b(x + size, y);
        ofPoint c(x + size / 2, y + ((sqrt(3) * size) / 2));
        
        ofDrawTriangle(a, b, c);
        drawMode3(x, y, size / 2, n - 1);
        drawMode3((a.x + b.x) / 2, (a.y + b.y) / 2, size / 2, n - 1);
        drawMode3((a.x + c.x) / 2, (a.y + c.y) / 2, size / 2, n - 1);
        ofSetColor(colores[n % colores.size()]);
    }
};
