#include "enemy.hpp"

#include <iostream>
using namespace std;
using namespace sf;

void Enemy::draw(sf::RenderWindow& window)
{
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
  life = 1;

}

void Enemy::setPos(float x, float y)
{
    pdogs.setPosition(x, y);
}

float Enemy::getTop() const
{
    return pdogs.getPosition().y;
}

float Enemy::getBottom() const
{
    return pdogs.getPosition().y + pdogs.getGlobalBounds().height;
}
float Enemy::getLeft() const
{
    return pdogs.getPosition().x;
}

float Enemy::getRight() const
{
    return pdogs.getPosition().x + pdogs.getGlobalBounds().width;
}

void Enemy::fly(int speed) {
  pdogs.setTexture(graphic);
  pdogs.move(0, speed);
}

void Enemy::checkCollision(FBullet& bullet)
{
  if (bullet.getTop() <= pdogs.getPosition().y + pdogs.getGlobalBounds().height &&
      bullet.getBottom() >= pdogs.getPosition().y &&
      bullet.getLeft() >= pdogs.getPosition().x &&
      bullet.getRight() <= pdogs.getPosition().x + pdogs.getGlobalBounds().width )
  {
    life -= 1;
    bullet.setPos(Vector2f(104800, 104800));
    if (life <= 0) {
      pdogs.setPosition(Vector2f(104800, 104800));
    }
    cout << "life " << life << endl;
  }
}
