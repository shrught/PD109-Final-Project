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
    
  //t_vesta.loadFromFile("../Resources/images/Vesta.jpg");
  if (!t_vesta.loadFromFile("Raiden/Resources/images/Vesta.jpg"))
  {
      t_vesta.loadFromFile("../Resources/images/Vesta.jpg");
  }
  RenderWindow window(VideoMode(WIDTH, HEIGHT), "RAIDEN");

  vesta.setTexture(t_vesta);

  window.setKeyRepeatEnabled(true);
  Vector2u planeSize;
  vesta.setPosition(0, 0);
    
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

    if (Keyboard::isKeyPressed(Keyboard::W)) // Up
    {
      player1.move(0.f, -speed * dt);
      if (player1.getY() <= 0)
        player1.setPosition(player1.getX(), 0.f);
    }
    if (Keyboard::isKeyPressed(Keyboard::S))
    {
      player1.move(0.f, speed * dt);
      if (player1.getY() >= window.getSize().y - player1.planeHeight())  // Bottom
        player1.setPosition(player1.getX(), window.getSize().y - player1.planeHeight());
    }
    if (Keyboard::isKeyPressed(Keyboard::A)) // Left
    {
      player1.move(-speed * dt * 1.2, 0.f);
      if (player1.getX() <= 0)
        player1.setPosition(0.f, player1.getY());
    }
    if (Keyboard::isKeyPressed(Keyboard::D)) // Right
    {
      player1.move(speed * dt * 1.2, 0.f);
      if (player1.getX() >= window.getSize().x - player1.planeWidth())
          player1.setPosition(window.getSize().x - player1.planeWidth(), player1.getY());
    }

    if(Keyboard::isKeyPressed(Keyboard::LShift))
            isFiring = true;
    
      if (Keyboard::isKeyPressed(Keyboard::Enter))
      {
          //std::cout << "player two";
          playerNum = 2;
      }
      
      if (playerNum == 2)
      {
          if (Keyboard::isKeyPressed(Keyboard::Up))
          {
            player2.move(0.f, -speed * dt);
            if (player2.getY() <= 0)  // Left
              player2.setPosition(player2.getX(), 0.f);
          }
          if (Keyboard::isKeyPressed(Keyboard::Down))
          {
            player2.move(0.f, speed * dt);
            if (player2.getY() >= window.getSize().y - player2.planeHeight())  // Bottom
              player2.setPosition(player2.getX(), window.getSize().y - player2.getY());
          }
          if (Keyboard::isKeyPressed(Keyboard::Left))
          {
            player2.move(-speed * dt * 1.2, 0.f);
            if (player2.getX() <= 0)  // Left
              player2.setPosition(0.f, player2.getY());
          }
          if (Keyboard::isKeyPressed(Keyboard::Right))
          {
            player2.move(speed * dt * 1.2, 0.f);
            if (player2.getX() >= window.getSize().x - player2.planeWidth())  // Right
              player2.setPosition(window.getSize().x - player2.planeWidth(), player2.getY());
          }

          if(Keyboard::isKeyPressed(Keyboard::M))
                  isFiring2 = true;
      }


    window.clear();
    window.draw(vesta);
    player1.draw(window);
    if (playerNum == 2)
        player2.draw(window);
    Enemy dog(400, 400, 1, window);

    if(isFiring == true){
        FBullet newBulletLeft(sf::Vector2f(10,20));
        FBullet newBulletRight(sf::Vector2f(10,20));
        newBulletLeft.setPos(sf::Vector2f(player1.getX() + player1.planeWidth() * (3/7),player1.getY()));
        newBulletRight.setPos(sf::Vector2f(player1.getX() + player1.planeWidth(), player1.getY()));
        bulletvecLeft.push_back(newBulletLeft);
        bulletvecRight.push_back(newBulletRight);
        isFiring = false;
        }

        for(int i = 0; i < bulletvecLeft.size();i += 45){
            bulletvecLeft[i].draw(window);
            bulletvecLeft[i].fire(2);
            bulletvecRight[i].draw(window);
            bulletvecRight[i].fire(2);

        }
    if(isFiring2 == true)
    {
      sf::Color p2B = sf::Color::Green;
      FBullet newBulletLeft2(sf::Vector2f(10,20),p2B);
      FBullet newBulletRight2(sf::Vector2f(10,20),p2B);
      newBulletLeft2.setPos(sf::Vector2f(player2.getX() + player2.planeWidth() * (3/7), player2.getY()));
      newBulletRight2.setPos(sf::Vector2f(player2.getX() + player2.planeWidth(), player2.getY()));
      bulletvecLeft2.push_back(newBulletLeft2);
      bulletvecRight2.push_back(newBulletRight2);
      isFiring2 = false;
    }

      for(int i = 0; i < bulletvecLeft2.size();i += 45)
      {
          bulletvecLeft2[i].draw(window);
          bulletvecRight2[i].draw(window);
          bulletvecLeft2[i].fire(2);
          bulletvecRight2[i].fire(2);
      }

    window.display();
  }
}
