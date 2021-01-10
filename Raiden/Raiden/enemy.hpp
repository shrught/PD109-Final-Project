#pragma once

#include <ctime>
#include <iostream>

#include "config.h"
#include "game.hpp"
using namespace sf;

class Enemy{
 public:
  Enemy(float x_, float y_, RenderWindow&);
  Sprite pdogs;

  //void run();
   void update(RenderWindow& window);

 private:
  float x_;
  float y_;

  Texture graphic;
   

};

