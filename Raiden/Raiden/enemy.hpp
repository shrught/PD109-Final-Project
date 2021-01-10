#pragma once
#include <ctime>
#include <iostream>

#include "Firebullet.hpp"
#include "config.h"
#include "game.hpp"
using namespace sf;

class Enemy {
 public:
  Enemy(float x_, float y_, RenderWindow&,double size);
  int collision;
  // void run();
  void update(RenderWindow& window);
  void draw(RenderWindow& window);
  void destroy();
  void fly(int speed);
  void checkCollision(FBullet bullet);

 private:
  float x_;

  float y_;
  Sprite pdogs;
  Texture graphic;
  int life;
};
