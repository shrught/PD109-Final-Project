//
//  enemy.cpp
//  
//
//  Created by 王彥普 on 2021/1/9.
//

#include "enemy.hpp"

Enemy::Enemy(float x_, float y_, float speed, RenderWindow* window) {
  //graphic.loadFromFile("Raiden/Resources/images/pdogs.png");
  graphic.loadFromFile("../Resources/images/pdogs.png");
    
    pdogs.setTexture(graphic);
    pdogs.setScale(0.4, 0.4);

  pdogs.setPosition(Vector2f(x_, y_));
  window->draw(pdogs);

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
