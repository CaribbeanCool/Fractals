#include "ofApp.hpp"
#include "Fractal.hpp"
#include "AbstractFractal.hpp"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetEscapeQuitsApp(false);
    fullscreen = 0;
    font1.load("Monocraft.otf", 28);
    font2.load("Monocraft.otf", 16);
    Circle *circle = new Circle(ofGetWidth() / 2, ofGetHeight() / 2, 0.31 * ofGetHeight(), 1);
    Tree *tree = new Tree(ofGetWidth() / 2, ofGetHeight() - 20, 1, 0.31 * ofGetHeight(), 1.5 * PI);
    Triangle *triangle = new Triangle((ofGetWidth() - 0.88 * ofGetHeight()) / 2, ofGetHeight() / 2 - 0.4 * 0.88 * ofGetHeight(), 0.88 * ofGetHeight(), 1);
    Fern *fern = new Fern(0, 0, 10);
    SquareFractal *square = new SquareFractal(ofGetWidth()/2, ofGetHeight()/ 2, 0);
    SnowFlake *koch = new SnowFlake();
    fractals = {circle, tree, triangle, fern, koch, square};
}

//--------------------------------------------------------------
void ofApp::update() {
    if (pressSpaceBar == true && fpsCounter < 30*2) {
        fpsCounter++;
        if (fpsCounter == 30*2 && fractals[i]->getLevel() < maxLevel) {
            fractals[i]->setLevel(fractals[i]->getLevel() + 1);
            fpsCounter = 0;
            if (fractals[i]->getLevel() == maxLevel) {
                maxLevel = 0;
            }
        }
        if (fpsCounter == 30*2 && fractals[i]->getLevel() > maxLevel) {
            fractals[i]->setLevel(fractals[i]->getLevel() - 1);
            fpsCounter = 0;
            if (fractals[i]->getLevel() == maxLevel) {
                maxLevel = 5;
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofBackgroundGradient(ofColor(65), ofColor(0), OF_GRADIENT_BAR);

    ofSetColor(ofColor::white);
    if (pressSpaceBar == true)
        font2.drawString("ANIMATION: ON ", 25, 160);
    else
        font2.drawString("ANIMATION: OFF ", 25, 160);
    font2.drawString("LEFT - DECREASE RECURSION DEPTH", 25, 100);
    font2.drawString("RIGHT - INCREASE RECURSION DEPTH", 25, 130);
    font2.drawString("Current Level :" + to_string(fractals[i]->getLevel()), 25,190);
    ofNoFill();
    switch (mode) {
    case '1': {
        //! Circle
        i = 0;
        ofSetColor(ofColor::white);
        font1.drawString("Circle", 25, 40);
    } break;
    case '2': {
        //! Tree
        i = 1;
        ofSetColor(ofColor::white);
        font1.drawString("Tree", 25, 40);
    } break;
    case '3': {
        //! Sierpinski Triangle
        i = 2;
        ofSetColor(ofColor::white);
        font1.drawString("Sierpinski Triangle", 25, 40);
    } break; 
    case '4':
        //! Barnsley Fern
        i = 3;
        ofSetColor(ofColor::white);
        font1.drawString("Barnsley Fern", 25, 40);
        break;
    case '5':
        //! Koch SnowFlake
        i = 4;
        ofSetColor(ofColor::white);
        font1.drawString("Koch Snowflake", 25, 40);
        break;
    case '6':
        //! New Fractal
        i = 5;
        ofSetColor(ofColor::white);
        font1.drawString("Square Fractal", 25, 40);
        break;
    }
    fractals[i]->draw();
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    if (key >= '1' && key <= '6') {
        mode = key;
        fractals[i]->setLevel(1);
    }
    else if (key == OF_KEY_F11)
        ofSetFullscreen(fullscreen++ % 2 == 0);
    else if (key == OF_KEY_ESC)
        ofSetFullscreen(false);
    else if (key == ' ') {
        if (pressSpaceBar == false) {
            fractals[i]->setLevel(0);
            pressSpaceBar = true;
            maxLevel = 5;
        }
        else if (pressSpaceBar == true) { //* THIS STOPS THE ANIMATION
            pressSpaceBar = false;
            fpsCounter = 0;
            fractals[i]->setLevel(0);
        }
    }
    if (pressSpaceBar == false) {
        if (key == OF_KEY_LEFT) {
            if (fractals[i]->getLevel() <= 0) {
                fractals[i]->setLevel(0);
            } else {
                fractals[i]->setLevel(fractals[i]->getLevel() - 1); // * subtract recursion depth
            }
        }
        else if (key == OF_KEY_RIGHT) {
            fractals[i]->setLevel(fractals[i]->getLevel() + 1); // * add recursion depth
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {
}