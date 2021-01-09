#include <ctime>
#include <iostream>

#include "config.h"
#include "game.hpp"
using namespace sf;

class Enemy {
 public:
  Enemy(float x_, float y_, float speed, RenderWindow&);
  Sprite pdogs;

  void run();

 private:
  float x_;
  float y_;
  float speed;
  Texture graphic;
  void update();

};

// const int MAX_ENTITES = 100;

// std::vector<Enemy *> v;

// Pdogs* pdogs = new Pdogs("pdogs.png");
