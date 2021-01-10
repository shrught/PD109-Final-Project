#include "enemy.hpp"
#include <iostream>
using namespace std;

void Enemy::draw(sf::RenderWindow& window) {
  pdogs.setTexture(graphic);
  window.draw(pdogs);
}

Enemy::Enemy(float x_, float y_, RenderWindow& window,double size) {
  if (!graphic.loadFromFile("Raiden/Resources/images/pdogs.png")) {
    graphic.loadFromFile("../Resources/images/pdogs.png");
  }
  // graphic.loadFromFile("../Resources/images/pdogs.png");
  pdogs.setTexture(graphic);
  pdogs.setPosition(Vector2f(x_, y_));
  pdogs.setScale(size/10, size/10);
  life = 10;
  this->size = size;
  // window.draw(pdogs);
}

void Enemy::fly(int speed) {
  pdogs.setTexture(graphic);
  pdogs.move(0, speed);
}

void Enemy::checkCollision(FBullet bullet)
{
  if (bullet.getBottom() >= pdogs.getPosition().y &&
      bullet.getLeft() >= pdogs.getPosition().x + (size/10) &&
      bullet.getRight() <= pdogs.getPosition().x + (size/10))
    life -= 1;
    // life -= 1;
    // plane.setPosition(Vector2f(4234432, 4234423));
  
}



  
