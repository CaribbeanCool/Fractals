#pragma once

#include "ofMain.h"
#include "AbstractFractal.hpp"
#include <cmath>

/**
 * @brief Koch SnowFlake Fractal
 *
 */

class SnowFlake : public AbstractFractal {
private:
  glm::vec2 start;
  glm::vec2 end;

public:
  SnowFlake();
  SnowFlake(glm::vec2 start, glm::vec2 end);

  glm::vec2 getStart() const { return start; }
  glm::vec2 getEnd() const { return end; }
  void setStart(glm::vec2 start) { this->start = start; }
  void setEnd(glm::vec2 end) { this->end = end; }

  void draw();
  void draw(int n, SnowFlake *flake);

  glm::vec2 getA();
  glm::vec2 getB();
  glm::vec2 getC();
  glm::vec2 getD();
  glm::vec2 getE();
};