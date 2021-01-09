#include "enemy.hpp"
#include <iostream>

Enemy::Enemy(float x_, float y_, float speed, RenderWindow& window)
{
  //graphic.loadFromFile("Raiden/Resources/images/pdogs.png");
  graphic.loadFromFile("../Resources/images/pdogs.png");
  pdogs.setPosition(Vector2f(x_, y_));
  pdogs.setScale(0.4, 0.4);
  window.draw(pdogs);
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
//寫一個random生成？

void Enemy::run(RenderWindow& window)
{
  Enemy dog(400, 300, 1, window);
  dog.update();
}
