#include "enemy.hpp"

#include <iostream>
using namespace std;
using namespace sf;

void Enemy::draw(sf::RenderWindow& window) {
  pdogs.setTexture(graphic);
  window.draw(pdogs);
}

Enemy::Enemy(float x_, float y_, RenderWindow& window, double size) {
  if (!graphic.loadFromFile("Raiden/Resources/images/pdogs.png")) {
    graphic.loadFromFile("../Resources/images/pdogs.png");
  }
  // graphic.loadFromFile("../Resources/images/pdogs.png");
  pdogs.setTexture(graphic);
  pdogs.setPosition(Vector2f(x_, y_));
  pdogs.setScale(size / 10, size / 10);
  life = 5;

}

void Enemy::fly(int speed) {
  pdogs.setTexture(graphic);
  pdogs.move(0, speed);
}

void Enemy::checkCollision(FBullet bullet) {
  if (bullet.getTop() <=
          pdogs.getPosition().y + pdogs.getGlobalBounds().height &&
      bullet.getRight() >= pdogs.getPosition().x &&
      bullet.getLeft() <= pdogs.getPosition().x) {
    life -= 1;
    bullet.setPos(Vector2f(104800, 104800));
    if (life <= 0) {
      pdogs.setPosition(Vector2f(104800, 104800));
    }
    cout << "life " << life << endl;
  }
}
