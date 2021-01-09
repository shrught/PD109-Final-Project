#include "enemy.hpp"

#include <iostream>

Enemy::Enemy(float x_, float y_, float speed, RenderWindow& window) {
  graphic.loadFromFile("Raiden/Resources/images/pdogs.png");
  pdogs(graphic);
  pdogs.setPosition(Vector2f(x_, y_));
  window.draw(pdogs);
}

void Enemy::update() {
  Clock clock;
  double dt;
  dt = clock.restart().asSeconds();
  pdogs.move(0, speed * dt);
}
//寫一個random生成？

int main() {
  Enemy dog(400, 300, 1, &window);
  for (int i = 0; i < 10; i++) {
    dog.update();
  }
}
