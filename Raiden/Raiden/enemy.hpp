#pragma once

#include <ctime>
#include <iostream>

#include "config.h"
#include "game.hpp"
using namespace sf;

class Enemy {
 public:
  Enemy(float x_, float y_, float speed, RenderWindow*);
  Sprite pdogs;

 private:
  Texture graphic;
  void update();

  // float distance;
  float speed;

  // void update(float dt);

  void render(sf::RenderTarget& target);
};

