#include <ctime>
#include <iostream>

#include "config.h"
#include "game.hpp"
using namespace sf;

class Enemy {
 public:
  Enemy(float x_, float y_, float speed, RenderWindow&);
  Sprite pdogs;

 private:
  Texture graphic;
  void update();

  // float distance;
  float speed;

  // void update(float dt);

  void render(sf::RenderTarget& target);
};

Enemy::Enemy(float x_, float y_, float speed, RenderWindow& window) {
  //graphic.loadFromFile("Raiden/Resources/images/pdogs.png");
  graphic.loadFromFile("../Resources/images/pdogs.png");
    
    pdogs.setTexture(graphic);

  pdogs.setPosition(Vector2f(x_, y_));
  window.draw(pdogs);

  for (int i = 0; i < 100; i++) {
    update();
  }
}

void Enemy::update() {
  Clock clock;
  double dt;
  dt = clock.restart().asSeconds();
  pdogs.move(0, speed * dt);
    
}

// const int MAX_ENTITES = 100;

// std::vector<Enemy *> v;

// Pdogs* pdogs = new Pdogs("pdogs.png");
