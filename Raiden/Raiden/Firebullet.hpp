#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "config.h"

using namespace sf;

class FBullet{
    private:
    sf::RectangleShape bullet;


    public:
    FBullet(sf::Vector2f size);
    FBullet(sf::Vector2f size, sf::Color &bulletColor);

    void setDirection();
    void fire(int speed);
    int getRight();
    int getLeft();
    int getTop();
    int getBottom();
    void draw(sf::RenderWindow &window);
    void setPos(sf::Vector2f newPos);
};
