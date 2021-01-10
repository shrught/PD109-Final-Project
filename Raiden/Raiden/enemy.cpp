#include "enemy.hpp"
using namespace std;
#include <iostream>

Enemy::Enemy(float x_, float y_, RenderWindow& window) {
  graphic.loadFromFile("Raiden/Resources/images/pdogs.png");
  // graphic.loadFromFile("../Resources/images/pdogs.png");
  pdogs.setTexture(graphic);
  pdogs.setPosition(Vector2f(x_, y_));
  pdogs.setScale(0.4, 0.4);
  window.draw(pdogs);

}

void Enemy::update(RenderWindow& window) {
 
 
  int dt = (time(NULL) % 10) + 1;
  //cout << dt << endl;
  pdogs.move(0, 50);
  // cout << "move";
  window.draw(pdogs);
}

// const int MAX_ENTITES = 100;

// std::vector<Enemy *> v;

// Pdogs* pdogs = new Pdogs("pdogs.png");
//寫一個random生成？
