#pragma once
#include "AbstractFractal.hpp"

class SquareFractal : public AbstractFractal {
private:
    float x, y;

public:
    SquareFractal(float x, float y, int n) : AbstractFractal("Square Fractal", n) {
        this->x = x;
        this->y = y;
    }

    void draw() {
        drawSquare(x, y, (level * 85) + 5);
    }

    void drawSquare(float x, float y, int n) {
        ofDrawRectangle(x - n / 2, y - n / 2, n, n);

        if (n <= 10)
            return;
        
        ofSetColor(colores[n % colores.size()]);
        drawSquare(x - n / 2, y - n / 2, n / 2);
        drawSquare(x + n / 2, y - n / 2, n / 2);
        drawSquare(x - n / 2, y + n / 2, n / 2);
        drawSquare(x + n / 2, y + n / 2, n / 2);
        
    }
};
