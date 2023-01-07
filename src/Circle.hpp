#pragma once
#include "AbstractFractal.hpp"

class Circle : public AbstractFractal {
private:
    float x, y, r, angle = 0.01;

public:
    Circle(float x, float y, float r, int n) : AbstractFractal("Circle", n) {
        this->x = x;
        this->y = y;
        this->r = r;
    };

    void draw() {
        angle += 0.01;
        drawMode1(x, y, r, level); 
    };

    void drawMode1(float x, float y, float r, int n) {
        if (n == 0)
            return;
        ofSetColor(colores[n % colores.size()]);

        int delta = r * 0.35;

        ofDrawCircle(x, y, r);

        float angle1 = angle;
        float angle2 = PI / 3 + angle;
        float angle3 = PI + angle;
        float angle4 = 2 * PI / 3 + angle;
        float angle5 = 4 * PI / 3 + angle;
        float angle6 = 5 * PI / 3 + angle;
        drawMode1(x + r * cos(angle1), y + r * sin(angle1), delta, n - 1);
        drawMode1(x + r * cos(angle2), y + r * sin(angle2), delta, n - 1);
        drawMode1(x + r * cos(angle3), y + r * sin(angle3), delta, n - 1);
        drawMode1(x + r * cos(angle4), y + r * sin(angle4), delta, n - 1);
        drawMode1(x + r * cos(angle5), y + r * sin(angle5), delta, n - 1);
        drawMode1(x + r * cos(angle6), y + r * sin(angle6), delta, n - 1);
    };
};