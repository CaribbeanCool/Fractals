#pragma once

#include <cmath>
#include <vector>
#include "ofMain.h"
#include "Fractal.hpp"
#include "AbstractFractal.hpp"

#include "Circle.hpp"
#include "Tree.hpp"
#include "Triangle.hpp"
#include "BarnsleyFern.hpp"
#include "SnowFlake.hpp"
#include "Square.hpp"
class ofApp : public ofBaseApp {
private:
  char mode = '1';
  float angle = 0;
  unsigned int fullscreen;

  ofTrueTypeFont font1;
  ofTrueTypeFont font2;

  int i = 0;

  vector<Fractal *> fractals;

  bool pressSpaceBar = false;
  int fpsCounter = 0;
  int maxLevel = 5;

public:
  void setup();
  void update();
  void draw();

  void keyPressed(int key);
  void keyReleased(int key);
  void mouseMoved(int x, int y);
  void mouseDragged(int x, int y, int button);
  void mousePressed(int x, int y, int button);
  void mouseReleased(int x, int y, int button);
  void mouseEntered(int x, int y);
  void mouseExited(int x, int y);
  void windowResized(int w, int h);
  void dragEvent(ofDragInfo dragInfo);
  void gotMessage(ofMessage msg);

  void drawMode1(float x, float y, float r, int n);
  void drawMode2(float x, float y, int n, float length, float rad);
  void drawMode3(float x, float y, float size, int n);
  void drawMode4(float x, float y, float n);
  void drawMode6(float x, float y, float width, float height, int n);
};
