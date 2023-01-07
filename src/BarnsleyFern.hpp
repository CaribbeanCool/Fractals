#pragma once
#include "AbstractFractal.hpp"
#include <cmath>

class Fern : public AbstractFractal {
private:
    float x, y;

public:
    Fern(float x, float y, int n) : AbstractFractal("Barnsley Fern", n) {
        this->x = x;
        this->y = y;
    }

    void draw() {
        drawMode4(x, y, (level * 500));
    };

    void drawMode4(float x, float y, int n) {
        if (n == 0)
            return;
        
        float r = ofRandom(1);

        float px = ofMap(x, -2.1820, 2.6558, 0, ofGetWidth());
        float py = ofMap(y, 0, 9.9983, ofGetHeight(), 0);

        ofFill();
        ofSetColor(ofColor::green);
        ofSetColor(colores[n % colores.size()]);
        ofDrawCircle(px, py, 0.6);
        ofSetColor(ofColor::white);
        

        if (r < 0.01)
            drawMode4(0, 0.16 * y, n - 1);

        else if (r < 0.86)
            drawMode4(0.85 * x + 0.04 * y, -0.04 * x + 0.85 * y + 1.6, n - 1);

        else if (r < 0.93)
            drawMode4(0.2 * x - 0.26 * y, 0.23 * x + 0.22 * y + 1.6, n - 1);

        else
            drawMode4(-0.15 * x + 0.28 * y, 0.26 * x + 0.24 * y + 0.44, n - 1);
    }
};