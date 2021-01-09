#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


class FBullet{
    private:
    sf::RectangleShape bullet;


    public:
    FBullet(sf::Vector2f size);

    void setDirection();
    void fire(int speed);
    int getRight();
    int getLeft();
    int getTop();
    int getBottom();
    void draw(sf::RenderWindow &window);
    void setPos(sf::Vector2f newPos);
};
