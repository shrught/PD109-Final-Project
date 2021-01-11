#pragma once
#include <ctime>
#include <iostream>

#include "Firebullet.hpp"
#include "config.h"
//#include "game.hpp"
using namespace sf;

class Enemy {
    friend class Fighter;
 public:
  Enemy(float x_, float y_, RenderWindow&,double size);
  void draw(RenderWindow& window);
  void fly(int speed);
  void setPos(float x, float y);
  float getTop() const;
  float getBottom() const;
  float getLeft() const;
  float getRight() const;
  int life;
  void checkCollision(FBullet& bullet);
  

 private:
  float x_;
  float y_;
  double size;
  Sprite pdogs;
  Texture graphic;
  
};
