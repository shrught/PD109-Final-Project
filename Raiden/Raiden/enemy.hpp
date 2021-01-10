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
  void draw(RenderWindow& window);
  void fly(int speed);
  int life;
  void checkCollision(FBullet bullet);

 private:
  float x_;
  float y_;
  Sprite pdogs;
  Texture graphic;
  
};
