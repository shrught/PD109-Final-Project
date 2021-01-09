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

void Game::run() {
    
  t_vesta.loadFromFile("../Resources/images/Vesta.jpg");
  t_plane.loadFromFile("../Resources/images/plane.png");
  //t_vesta.loadFromFile("Raiden/Resources/images/Vesta.jpg");
  //t_plane.loadFromFile("Raiden/Resources/images/plane.png");
  RenderWindow window(VideoMode(WIDTH, HEIGHT), "RAIDEN");

  vesta.setTexture(t_vesta);
  plane.setTexture(t_plane);
  plane2.setTexture(t_plane);

  Color blue;
  window.setKeyRepeatEnabled(true);
  Vector2u planeSize;
  plane.setScale(0.4, 0.4);
  plane2.setScale(0.4, 0.4);
  plane2.setColor(blue);
  vesta.setPosition(0, 0);
  plane.setPosition(WIDTH / 2, HEIGHT * 9 / 10);
  plane2.setPosition(WIDTH / 2 + plane.getGlobalBounds().width / 2 + 50, HEIGHT * 9 / 10);

  Clock clock;
  float timer = 0, delay = 0.1;
  double dt;
  float speed = 500;
  std::vector<FBullet> bulletvecLeft;
    std::vector<FBullet> bulletvecRight;
    std::vector<FBullet> bulletvecLeft2;
    std::vector<FBullet> bulletvecRight2;
  bool isFiring = false;
    bool isFiring2 = false;


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
//    srand(5);
//    int pos_x = rand() % 100;
//    srand(30);
//    int pos_y = rand() % 300;
//    Enemy dog(pos_x, pos_y, 1, window);
//    time_t first = time(NULL) + 10;

//    int seconds = 0;
//    while (true) {
//      if (time(NULL) >= first) {
//        first = time(NULL) + 10;  // Saves the time additional 10 seconds ahead from now!
//        dog.run(window);
//        seconds = 0;  // Resets the secondcounter.
//      }
//    }

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

    if(Keyboard::isKeyPressed(Keyboard::LShift))
            isFiring = true;
    
      if (Keyboard::isKeyPressed(Keyboard::Enter))
      {
          std::cout << "player two";
          playerNum = 2;
      }
      
      if (playerNum == 2)
      {
          if (Keyboard::isKeyPressed(Keyboard::Up)) {
            plane2.move(0.f, -speed * dt);
            if (plane2.getPosition().y <= 0)  // Left
              plane2.setPosition(plane2.getPosition().x, 0.f);
          }
          if (Keyboard::isKeyPressed(Keyboard::Down)) {
            plane2.move(0.f, speed * dt);
            if (plane2.getPosition().y >=
                window.getSize().y - plane2.getGlobalBounds().height)  // Bottom
              plane2.setPosition(plane2.getPosition().x,
                                window.getSize().y - plane2.getGlobalBounds().height);
          }
          if (Keyboard::isKeyPressed(Keyboard::Left)) {
            plane2.move(-speed * dt * 1.2, 0.f);
            if (plane2.getPosition().x <= 0)  // Left
              plane2.setPosition(0.f, plane2.getPosition().y);
          }
          if (Keyboard::isKeyPressed(Keyboard::Right)) {
            plane2.move(speed * dt * 1.2, 0.f);
            if (plane2.getPosition().x >=
                window.getSize().x - plane2.getGlobalBounds().width)  // Right
              plane2.setPosition(window.getSize().x - plane2.getGlobalBounds().width,
                                plane2.getPosition().y);
          }

          if(Keyboard::isKeyPressed(Keyboard::M))
          {
                  isFiring2 = true;
          }
      }


    window.clear();
    window.draw(vesta);
    window.draw(plane);
      if (playerNum == 2)
          window.draw(plane2);
    Enemy dog(400, 400, 1, window);

    if(isFiring == true){
        FBullet newBulletLeft(sf::Vector2f(10,20));
        FBullet newBulletRight(sf::Vector2f(10,20));
        newBulletLeft.setPos(sf::Vector2f(plane.getPosition().x + plane.getGlobalBounds().width * (3/7),plane.getPosition().y));
        newBulletRight.setPos(sf::Vector2f(plane.getPosition().x + plane.getGlobalBounds() .width, plane.getPosition().y));
        bulletvecLeft.push_back(newBulletLeft);
        bulletvecRight.push_back(newBulletRight);
        isFiring = false;
        }

        for(int i = 0; i < bulletvecLeft.size();i += 40){
            bulletvecLeft[i].draw(window);
            bulletvecLeft[i].fire(2);
            bulletvecRight[i].draw(window);
            bulletvecRight[i].fire(2);

        }
    if(isFiring2 == true){
      FBullet newBulletLeft2(sf::Vector2f(10,20));
      FBullet newBulletRight2(sf::Vector2f(10,20));
      newBulletLeft2.setPos(sf::Vector2f(plane2.getPosition().x + plane2.getGlobalBounds().width * (3/7),plane2.getPosition().y));
      newBulletRight2.setPos(sf::Vector2f(plane2.getPosition().x + plane2.getGlobalBounds().width, plane2.getPosition().y));
      bulletvecLeft2.push_back(newBulletLeft2);
      bulletvecRight2.push_back(newBulletRight2);
      isFiring2 = false;
      }

      for(int i = 0; i < bulletvecLeft2.size();i += 40){
          bulletvecLeft2[i].draw(window);
          bulletvecRight2[i].draw(window);
          bulletvecLeft2[i].fire(2);
          bulletvecRight2[i].fire(2);

      }

    window.display();
  }
}
