//
//  game.cpp
//  Raiden
//
//  Created by 王彥普 on 2021/1/8.
//  Copyright © 2021 !!!. All rights reserved.
//

#include "game.hpp"

#include <unistd.h>

#include <cstdlib>
#include <ctime>
#include <vector>

#include "Firebullet.hpp"
#include "enemy.hpp"

Game::Game() { ; }

Game::~Game() { window.create(VideoMode(WIDTH, HEIGHT), "RAIDEN"); }

void Game::tick() { ; }

void Game::run() {
  Texture t_vesta, t_plane;
  // t_vesta.loadFromFile("../Resources/images/Vesta.jpg");
  //  t_plane.loadFromFile("../Resources/images/plane.png");
  t_vesta.loadFromFile("Raiden/Resources/images/Vesta.jpg");
  t_plane.loadFromFile("Raiden/Resources/images/plane.png");
  RenderWindow window(VideoMode(WIDTH, HEIGHT), "RAIDEN");

  Sprite vesta(t_vesta);
  Sprite plane(t_plane);

  window.setKeyRepeatEnabled(true);
  Vector2u planeSize;
  plane.setScale(0.4, 0.4);
  vesta.setPosition(0, 0);
  plane.setPosition(WIDTH / 2, HEIGHT * 9 / 10);

  Clock clock;
  float timer = 0, delay = 0.1;
  double dt;
  float speed = 500;
  std::vector<FBullet> bulletvec;
  bool isFiring = false;

  while (window.isOpen()) {
    float dt = clock.restart().asSeconds();
    clock.restart();
    timer += dt;

    Event e;
    while (window.pollEvent(e)) {
      if (e.type == Event::Closed) window.close();
      if (e.type == Event::KeyPressed && e.key.code == Keyboard::Escape)
        window.close();
    }

    // random enemy
    /* 固定亂數種子 */
    srand(5);
    int pos_x = rand() % 100;
    srand(30);
    int pos_y = rand() % 300;
    Enemy dog(pos_x, pos_y, 1, window);
    time_t first = time(NULL) + 10;

    int seconds = 0;
    while (true) {
      if (time(NULL) >= first) {
        first = time(NULL) +
                10;  // Saves the time additional 10 seconds ahead from now!
        dog.run();
        seconds = 0;  // Resets the secondcounter.
      }
    }

    if (Keyboard::isKeyPressed(Keyboard::W)) {
      plane.move(0.f, -speed * dt);
      if (plane.getPosition().y <= 0)  // Left
        plane.setPosition(plane.getPosition().x, 0.f);
    }
    if (Keyboard::isKeyPressed(Keyboard::S)) {
      plane.move(0.f, speed * dt);
      if (plane.getPosition().y >=
          window.getSize().y - plane.getGlobalBounds().height)  // Bottom
        plane.setPosition(plane.getPosition().x,
                          window.getSize().y - plane.getGlobalBounds().height);
    }
    if (Keyboard::isKeyPressed(Keyboard::A)) {
      plane.move(-speed * dt * 1.2, 0.f);
      if (plane.getPosition().x <= 0)  // Left
        plane.setPosition(0.f, plane.getPosition().y);
    }
    if (Keyboard::isKeyPressed(Keyboard::D)) {
      plane.move(speed * dt * 1.2, 0.f);
      if (plane.getPosition().x >=
          window.getSize().x - plane.getGlobalBounds().width)  // Right
        plane.setPosition(window.getSize().x - plane.getGlobalBounds().width,
                          plane.getPosition().y);
    }

    if (Keyboard::isKeyPressed(Keyboard::Space)) {
      isFiring = true;
    }

    if (timer > delay) {
      timer = 0;
      tick();
    }

    window.clear();

    window.draw(vesta);
    window.draw(plane);

    if (isFiring == true) {
      FBullet newBullet(sf::Vector2f(10, 20));
      newBullet.setPos(sf::Vector2f(
          (plane.getPosition().x + (plane.getGlobalBounds().width) / 2),
          plane.getPosition().y));
      bulletvec.push_back(newBullet);
      isFiring = false;
    }

    for (int i = 0; i < bulletvec.size(); i++) {
      bulletvec[i].draw(window);
      bulletvec[i].fire(3);
    }
    window.display();
  }
}
