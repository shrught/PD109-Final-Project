//
//  professor.cpp
//  
//
//  Created by 王彥普 on 2021/1/10.
//

#include "professor.hpp"


Boss::Boss()
{
    if (!t_plane.loadFromFile("../Resources/images/LCK.png"))
    {
        t_plane.loadFromFile("Raiden/Resources/images/LCK.png");
    }
    
    //t_plane.loadFromFile("Raiden/Resources/images/plane.png");
    plane.setTexture(t_plane);
    plane.setScale(0.4, 0.4);
    plane.setPosition(WIDTH / 2, HEIGHT * 1 / 10);
    
    planeHit.setTexture(t_plane);
    planeHit.setScale(0.4, 0.4);
    planeHit.setColor(sf::Color::Red);
}

float Boss::getX() const
{
    return plane.getPosition().x;
}

float Boss::getY() const
{
    return plane.getPosition().y;
}

float Boss::planeWidth() const
{
    return plane.getGlobalBounds().width;
}

float Boss::planeHeight() const
{
    return plane.getGlobalBounds().height;
}

void Boss::setPosition(float x, float y)
{
    plane.setPosition(x, y);
}

void Boss::move()
{
    if (moveType == 1)
    {
        plane.move(-10, 0);
        if (getX() <= 0)
        {
            moveType = 2;
            plane.setPosition(0, getY());
        }
    }
    else if (moveType == 2)
    {
        plane.move(10, 5);
        if (getX() + planeWidth() >= WIDTH)
        {
            moveType = 3;
            plane.setPosition(WIDTH - planeWidth(), getY());
        }
    }
    else if (moveType == 3)
    {
        plane.move(-10, 0);
        if (getX() <= 0)
        {
            moveType = 4;
            plane.setPosition(0, getY());
        }
    }
    else
    {
        plane.move(10, -5);
        if (getX() + planeWidth() >= WIDTH)
        {
            moveType = 1;
            plane.setPosition(WIDTH - planeWidth(), getY());
        }
    }
    
}

void Boss::checkCollision(FBullet& bullet)
{
    if (bullet.getTop() <= getY() + planeHeight() && bullet.getBottom() >= getY() && bullet.getLeft() >= getX() && bullet.getRight() <= getX() + planeWidth())
    {
        health -= 50;
        planeHit.setPosition(getX(), getY());
        showHit = 1;
        bullet.setPos(Vector2f (100000,100390));
    }
    if (health <= 0)
    {
        alive = 0;
        plane.setPosition(Vector2f(4234432, 4234423));
    }
}

void Boss::draw(RenderWindow& window)
{
    if (showHit == 0)
        window.draw(plane);
    else
    {
        window.draw(planeHit);
        showHit = 0;
    }
}

bool Boss::getAlive() const
{
    return alive;
}

int Boss::getHealth() const
{
    return health;
}

void Boss::reset()
{
    plane.setPosition(WIDTH / 2, HEIGHT * 1 / 10);
    health = 10000;
    alive = 1;
    moveType = 1;
}
