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
#include <string>
#include <vector>

#include "Firebullet.hpp"
#include "enemy.hpp"
using namespace std;
Game::Game() { ; }

Game::~Game() { ; }

void Game::run() {
    
  // t_vesta.loadFromFile("../Resources/images/Vesta.jpg");
  if (!t_vesta.loadFromFile("Raiden/Resources/images/Vesta.jpg")) {
    t_vesta.loadFromFile("../Resources/images/Vesta.jpg");
  }
    
  if (!t_victory.loadFromFile("Raiden/Resources/images/victory.jpg")) {
        t_victory.loadFromFile("../Resources/images/victory.jpg");
    }
    
    if (!t_defeated.loadFromFile("Raiden/Resources/images/defeated.png")) {
          t_defeated.loadFromFile("../Resources/images/defeated.png");
      }
    

    
  SoundBuffer bExplode;
  if (!bExplode.loadFromFile("Raiden/Resources/audio/explode.wav"))
  {
      bExplode.loadFromFile("../Resources/audio/explode.wav");
  }
  Sound explode;
  explode.setVolume(80);
  explode.setBuffer(bExplode);
  bool boom = 0;
  bool boomP2 = 0;
  bool boomBoss = 0;
    
  SoundBuffer bAngry;
  if (!bAngry.loadFromFile("Raiden/Resources/audio/angry.wav"))
  {
      bAngry.loadFromFile("../Resources/audio/angry.wav");
  }
  Sound angry;
  angry.setVolume(80);
  angry.setBuffer(bAngry);
  bool bossAngry = 0;
    
  playerNum = 1;
  player1 = new Fighter;
  player2 = new Fighter;
  LCK = new Boss;
    
  RenderWindow window(VideoMode(WIDTH, HEIGHT), "RAIDEN");
  window.setFramerateLimit(60);
  vesta.setTexture(t_vesta);
  vesta.setPosition(0, 0);
  victory.setTexture(t_victory);
  victory.setPosition(0, 0);
  defeated.setTexture(t_defeated);
  defeated.setScale(1.69, 1.69);
  defeated.setPosition(0, 0);

  //window.setKetRepeatEnabled = true;

  

  RectangleShape playerHpBar;
  RectangleShape playerHpBarBack;
  playerHpBar.setSize(sf::Vector2f(300.f, 25.f));
  playerHpBar.setFillColor(sf::Color::Blue);
  playerHpBar.setPosition(sf::Vector2f(20.f, 20.f));

  RectangleShape playerHpBar2;
  RectangleShape playerHpBarBack2;
  playerHpBarBack2 = playerHpBar2;
  playerHpBarBack2.setFillColor(sf::Color(0, 25, 25, 200));

  playerHpBar2.setSize(sf::Vector2f(300.f, 25.f));
  playerHpBar2.setFillColor(sf::Color::Green);
  playerHpBar2.setPosition(sf::Vector2f(580.f, 20.f));

  playerHpBarBack2 = playerHpBar2;
  playerHpBarBack2.setFillColor(sf::Color(25, 25, 25, 200));

  Clock clock;
  float timer = 0, delay = 0.1;
  double dt;
  float speed = 500;
  std::vector<FBullet> bulletvecLeft;
  std::vector<FBullet> bulletvecRight;
  std::vector<FBullet> bulletvecLeft2;
  std::vector<FBullet> bulletvecRight2;
  std::vector<FBullet> bulletvecLeftLCK;
  std::vector<FBullet> bulletvecRightLCK;
  std::vector<FBullet> bulletvecAngry;
  std::vector<Enemy> dogs;
  std::vector<Enemy> biggerDogs;
  bool isFiring = false;
  bool isFiring2 = false;
  int WinTime = 0;

  while (window.isOpen()) {
    float dt = clock.restart().asSeconds();
    clock.restart();
    timer += dt;

    Event e;
    while (window.pollEvent(e))
    {
      if (e.type == Event::Closed)
      {
          window.close();
      }
      if (e.type == Event::KeyPressed && e.key.code == Keyboard::Escape)
      {
          window.close();
      }
    }

    if (Keyboard::isKeyPressed(Keyboard::W)) {
      player1->move(0.f, -speed * dt);
      if (player1->getY() <= 0)  // Left
        player1->setPosition(player1->getX(), 0.f);
    }
    if (Keyboard::isKeyPressed(Keyboard::S)) {
      player1->move(0.f, speed * dt);
      if (player1->getY() >=
          window.getSize().y - player1->planeHeight())  // Bottom
        player1->setPosition(player1->getX(),
                            window.getSize().y - player1->planeHeight());
    }
    if (Keyboard::isKeyPressed(Keyboard::A)) {
      player1->move(-speed * dt * 1.2, 0.f);
      if (player1->getX() <= 0)  // Left
        player1->setPosition(0.f, player1->getY());
    }
    if (Keyboard::isKeyPressed(Keyboard::D)) {
      player1->move(speed * dt * 1.2, 0.f);
      if (player1->getX() >= window.getSize().x - player1->planeWidth())  // Right
        player1->setPosition(window.getSize().x - player1->planeWidth(),
                            player1->getY());
    }

    if (Keyboard::isKeyPressed(Keyboard::LShift)) isFiring = true;

    if (Keyboard::isKeyPressed(Keyboard::Enter)) {
      // std::cout << "player two";
      playerNum = 2;
    }

    if (playerNum == 2) {
      if (Keyboard::isKeyPressed(Keyboard::Up)) {
        player2->move(0.f, -speed * dt);
        if (player2->getY() <= 0)  // Left
          player2->setPosition(player2->getX(), 0.f);
      }
      if (Keyboard::isKeyPressed(Keyboard::Down)) {
        player2->move(0.f, speed * dt);
        if (player2->getY() >=
            window.getSize().y - player2->planeHeight())  // Bottom
          player2->setPosition(player2->getX(),
                              window.getSize().y - player2->planeHeight());
      }
      if (Keyboard::isKeyPressed(Keyboard::Left)) {
        player2->move(-speed * dt * 1.2, 0.f);
        if (player2->getX() <= 0)  // Left
          player2->setPosition(0.f, player2->getY());
      }
      if (Keyboard::isKeyPressed(Keyboard::Right)) {
        player2->move(speed * dt * 1.2, 0.f);
        if (player2->getX() >=
            window.getSize().x - player2->planeWidth())  // Right
          player2->setPosition(window.getSize().x - player2->planeWidth(),
                              player2->getY());
      }

      if (Keyboard::isKeyPressed(Keyboard::M)) isFiring2 = true;
    }

    LCK->move();
    window.clear();
    window.draw(vesta);
    player1->draw(window);
    LCK->draw(window);

    /* 固定亂數種子 */
    srand(time(NULL));

    if (time(NULL) % 2 == 1) {
      int pos_x = (rand() + 67) % 500;
      Enemy dog(pos_x, 0, window, 5);
      dogs.push_back(dog);
    }
    if (time(NULL) % 7 == 1) {
      int pos_x = (rand() + 91) % 500;
      Enemy biggerDog(pos_x, 0, window, 7.5);
      biggerDogs.push_back(biggerDog);
    }

      if (WinTime <= 0)
      {
        for (int i = 0; i < dogs.size(); i += 120) {
          dogs[i].draw(window);
          dogs[i].fly(3);
          if (dogs[i].life <= 0)
            break;
        }

        for (int i = 0; i < biggerDogs.size(); i += 120) {
          biggerDogs[i].draw(window);
          biggerDogs[i].fly(5);
          if (biggerDogs[i].life <= 0)
            break;
        }
      }

    // dog.update(window);
    // seconds = 0;  // Resets the secondcounter.

    for (int i = 0; i < bulletvecLeft.size(); i += bulletSpacing)
    {
      bulletvecLeft[i].fire(2);
      bulletvecRight[i].draw(window);
      bulletvecRight[i].fire(2);
    }


    if (isFiring == true) {
      FBullet newBulletLeft(sf::Vector2f(10, 20));
      FBullet newBulletRight(sf::Vector2f(10, 20));
      newBulletLeft.setPos(sf::Vector2f(
          player1->getX() + player1->planeWidth() * (3 / 7), player1->getY()));
      newBulletRight.setPos(
          sf::Vector2f(player1->getX() + player1->planeWidth(), player1->getY()));
      bulletvecLeft.push_back(newBulletLeft);
      bulletvecRight.push_back(newBulletRight);
      isFiring = false;
      
    }

    for (int i = 0; i < bulletvecLeft.size(); i += bulletSpacing)
    {
        LCK->checkCollision(bulletvecLeft[i]);
        LCK->checkCollision(bulletvecRight[i]);
      for (int j = 0; j < dogs.size(); j++)
      {
          dogs[j].checkCollision(bulletvecLeft[i]);
          dogs[j].checkCollision(bulletvecRight[i]);
      }
      for (int j = 0; j < biggerDogs.size(); j++)
      {
          biggerDogs[j].checkCollision(bulletvecLeft[i]);
          biggerDogs[j].checkCollision(bulletvecRight[i]);
      }
          bulletvecLeft[i].draw(window);
          bulletvecLeft[i].fire(speed * dt * 1.2);
          bulletvecRight[i].draw(window);
          bulletvecRight[i].fire(speed * dt * 1.2);
    }
//      deleteBullet(bulletvecLeft, bulletSpacing);
//      deleteBullet(bulletvecRight, bulletSpacing);
      
      for (int i = 0; i < dogs.size(); i++)
      {
          player1->checkCollisionEnemy(dogs[i]);
          player2->checkCollisionEnemy(dogs[i]);
      }
      for (int i = 0; i < biggerDogs.size(); i++)
      {
          player1->checkCollisionEnemy(biggerDogs[i]);
          player2->checkCollisionEnemy(biggerDogs[i]);
      }

    if (isFiring2 == true) {
      sf::Color p2B = sf::Color::Green;
      FBullet newBulletLeft2(sf::Vector2f(10, 20), p2B);
      FBullet newBulletRight2(sf::Vector2f(10, 20), p2B);
      newBulletLeft2.setPos(sf::Vector2f(
          player2->getX() + player2->planeWidth() * (3 / 7), player2->getY()));
      newBulletRight2.setPos(
          sf::Vector2f(player2->getX() + player2->planeWidth(), player2->getY()));
      bulletvecLeft2.push_back(newBulletLeft2);
      bulletvecRight2.push_back(newBulletRight2);
      isFiring2 = false;
    }
      
      // LCK Bullet
      sf::Color pR = sf::Color::Red;
      FBullet newBulletLeftLCK(sf::Vector2f(20,50), pR);
      FBullet newBulletRightLCK(sf::Vector2f(20,50), pR);
      newBulletLeftLCK.setPos(sf::Vector2f(LCK->getX() + LCK->planeWidth() * (3/7), LCK->getY()));
      newBulletRightLCK.setPos(sf::Vector2f(LCK->getX() + LCK->planeWidth(), LCK->getY()));
      bulletvecLeftLCK.push_back(newBulletLeftLCK);
      bulletvecRightLCK.push_back(newBulletRightLCK);
      
      if (LCK->getHealth() < 3000)
      {
          if (bossAngry == 0)
          {
              angry.play();
              bossAngry = 1;
          }
          FBullet newBulletAngry(sf::Vector2f(50,50), pR);
          newBulletAngry.setPos(sf::Vector2f(LCK->getX() + LCK->planeWidth() * (1/2), LCK->getY()));
          bulletvecAngry.push_back(newBulletLeftLCK);
          for (int i = 0; i < bulletvecAngry.size(); i += bosebulSpacing / 2)
          {
              player1->checkCollision(bulletvecAngry[i]);
              if (playerNum == 2)
              {
                  player2->checkCollision(bulletvecAngry[i]);
              }
              bulletvecAngry[i].draw(window);
              bulletvecAngry[i].fire(-20);
          }
      }
      
      for (int i = 0; i < bulletvecLeftLCK.size(); i += bosebulSpacing)
      {
          player1->checkCollision(bulletvecLeftLCK[i]);
          player1->checkCollision(bulletvecRightLCK[i]);
          if (playerNum == 2)
          {
              player2->checkCollision(bulletvecLeftLCK[i]);
              player2->checkCollision(bulletvecRightLCK[i]);
          }
          bulletvecLeftLCK[i].draw(window);
          bulletvecRightLCK[i].draw(window);
          bulletvecLeftLCK[i].fire(-10);
          bulletvecRightLCK[i].fire(-10);
      }



    for (int i = 0; i < bulletvecLeft2.size(); i += bulletSpacing)
    {
        LCK->checkCollision(bulletvecLeft2[i]);
        LCK->checkCollision(bulletvecRight2[i]);
        bulletvecLeft2[i].draw(window);
        bulletvecRight2[i].draw(window);
        bulletvecLeft2[i].fire(speed * dt * 1.2);
        bulletvecRight2[i].fire(speed * dt * 1.2);
        
    }
      //deleteBullet(bulletvecLeft2, bulletSpacing);
      //deleteBullet(bulletvecRight2, bulletSpacing);
      
      
    if (playerNum == 2) {
      player2->draw(window);
      float hpPercent2 = static_cast<float>(player2->health) / player2->maxHealth;
      playerHpBar2.setSize(
          sf::Vector2f(300.f * hpPercent2, playerHpBar2.getSize().y));
      window.draw(playerHpBarBack2);
      window.draw(playerHpBar2);
    }

    float hpPercent = static_cast<float>(player1->health) / player1->maxHealth;
    playerHpBar.setSize(
        sf::Vector2f(300.f * hpPercent, playerHpBar.getSize().y));
    window.draw(playerHpBarBack);
    window.draw(playerHpBar);
      
    if (LCK->getAlive() == 0)
    {
        if (boomBoss == 0)
        {
            explode.play();
            boomBoss = 1;
        }
        WinTime++;
        if (WinTime > 200)
        {
            window.clear();
            window.draw(victory);
        }
    }
    
    
    if (player1->alive == 0 && boom == 0)
    {
        boom = 1;
        explode.play();
    }
    
    if (playerNum == 2)
    {
        if (player2->alive == 0 && boomP2 == 0)
        {
            boomP2 = 1;
            explode.play();
        }
    }
    
    // Game Over
    if (playerNum == 1 && player1->alive == 0)
    {
        WinTime++;
        if (WinTime > 100)
        {
            window.clear();
            window.draw(defeated);
        }
    }
    else if (playerNum == 2 && player1->alive == 0 && player2->alive == 0)
    {
        WinTime++;
        if (WinTime > 100)
        {
            window.clear();
            window.draw(defeated);
        }
    }

    window.display();
  }
    reset();
}

void Game::reset()
{
    delete player1;
    delete player2;
    delete LCK;
}

void Game::deleteBullet(std::vector<FBullet>& bulletVec, int spacing)
{
    int counter = -10 * spacing;
    if (bulletVec.size() % spacing == 1 && bulletVec.size() != 1)
    {

        for ( int i = 0; i < bulletVec.size(); i += spacing)
            {
                //Bullet culling (top of screen)
                if (bulletVec[i].getBottom() < 0 || bulletVec[i].getTop() > HEIGHT )
                    counter = i;
            }
        counter = counter / spacing + 1;
        if (counter > 0)
            bulletVec.erase(bulletVec.begin(), bulletVec.begin() + counter * spacing + 1);
    }
}
