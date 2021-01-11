//
//  fighter.cpp
//  Raiden
//
//  Created by 王彥普 on 2021/1/9.
//  Copyright © 2021 !!!. All rights reserved.
//

#include "fighter.hpp"

int Fighter::playerNum = 0;

int Fighter::getPlayerNum() const
{
    return playerNum;
}


Fighter::Fighter()
{
    Fighter::playerNum ++;
    if (playerNum == 1)
    {
        if (!t_plane.loadFromFile("../Resources/images/plane.png"))
        {
            t_plane.loadFromFile("Raiden/Resources/images/plane.png");
        }
    }
    
    else if (playerNum == 2)
    {
        if (!t_plane.loadFromFile("../Resources/images/plane2.png"))
        {
            t_plane.loadFromFile("Raiden/Resources/images/plane2.png");
        }
    }
    //t_plane.loadFromFile("Raiden/Resources/images/plane.png");
    plane.setTexture(t_plane);
    plane.setScale(0.4, 0.4);
    if (playerNum == 1)
        plane.setPosition(WIDTH / 2, HEIGHT * 9 / 10);
    else if (playerNum == 2)
        plane.setPosition(WIDTH / 2 + planeWidth() + 50, HEIGHT * 9 / 10);
}

Fighter::~Fighter()
{
    Fighter::playerNum--;
}

float Fighter::getX() const
{
    return plane.getPosition().x;
}

float Fighter::getY() const
{
    return plane.getPosition().y;
}

float Fighter::planeWidth() const
{
    return plane.getGlobalBounds().width;
}

float Fighter::planeHeight() const
{
    return plane.getGlobalBounds().height;
}

void Fighter::setPosition(float x, float y)
{
    plane.setPosition(x, y);
}

void Fighter::move(float x, float y)
{
    plane.move(x, y);
}

void Fighter::checkCollision(FBullet& bullet)
{
    if (bullet.getBottom() >= getY() && bullet.getTop() <= getY() + planeHeight() && bullet.getLeft() >= getX() && bullet.getRight() <= getX() + planeWidth())
    {
        health -= 50;
        std::cout << "collision";
        bullet.setPos(Vector2f(10580, 10580));
    }
    if (health <= 0)
    {
        alive = 0;
        plane.setPosition(Vector2f(4234432, 4234423));
    }
}

void Fighter::checkCollisionEnemy(Enemy& enemy)
{
    if (enemy.getBottom() >= getY() && enemy.getTop() <= getY() + planeHeight())
    {
        if (enemy.getRight() > getX() && enemy.getLeft() < getX())
        {
            health -= 200;
            std::cout << "collision dog";
            enemy.setPos(10580, 10580);
        }
        else if (enemy.getRight() > getX() + planeWidth() && enemy.getLeft() < getX() + planeWidth())
        {
            health -= 200;
            std::cout << "collision dog";
            enemy.setPos(10580, 10580);
        }
    }
}

void Fighter::draw(RenderWindow& window)
{
    window.draw(plane);
}

void Fighter::reset()
{
    health = maxHealth;
    plane.setPosition(WIDTH / 2, HEIGHT * 9 / 10);
}

