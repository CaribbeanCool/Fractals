#pragma once
#include "AbstractFractal.hpp"
#include <cmath>

class Tree : public AbstractFractal {
private:
    float x, y, length, rad;
public:
    Tree(float x, float y, int n, float length, float rad) : AbstractFractal("Tree", n) {
        this->x = x;
        this->y = y;
        this->length = length;
        this->rad = rad;
    };

    void draw() {
        drawMode2(x, y, level, length, rad);
        drawMode2(ofGetWidth() / 7, ofGetHeight() - 20, level, length * 0.25, 1.5 * PI); //*LEFT-SIDE TREE
        drawMode2(ofGetWidth() * 0.83, ofGetHeight() - 20, level, length * 0.25, 1.5 * PI); //*RIGHT-SIDE TREE
    }

    void drawMode2(float x, float y, int n, float length, float rad) {
        if (n == 0)
            return;
        ofSetColor(colores[n % colores.size()]);

        float x2 = x + length * cos(rad);
        float y2 = y + length * sin(rad);

        ofDrawLine(x, y, x2, y2);

        drawMode2(x2, y2, n - 1, 0.7 * length, rad + 0.2 * PI);
        drawMode2(x2, y2, n - 1, 0.7 * length, rad - 0.2 * PI);
    }
};