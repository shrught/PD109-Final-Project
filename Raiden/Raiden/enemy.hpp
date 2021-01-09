#pragma once

#include <ctime>
#include <iostream>

#include "config.h"
#include "game.hpp"
using namespace sf;

class Enemy {
 public:
  Enemy(float x_, float y_, float speed, RenderWindow&);
  Sprite pdogs;

  void run(RenderWindow& window);

 private:
  float x_;
  float y_;
  float speed;
  Texture graphic;
    void update();

};

