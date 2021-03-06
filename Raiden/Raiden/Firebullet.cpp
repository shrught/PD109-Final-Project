#include "Firebullet.hpp"
#include <SFML/GpuPreference.hpp>
#include <iostream>

using namespace sf;


FBullet::FBullet(sf::Vector2f size){
    bullet.setSize(size);
    bullet.setFillColor(sf::Color::Blue);
}

FBullet::FBullet(sf::Vector2f size,sf::Color &bulletColor){
    bullet.setSize(size);
    bullet.setFillColor(bulletColor);
}

void FBullet::fire(int speed){
//    if (getBottom() >= 0 && getTop() <= HEIGHT)
//        bullet.move(0,-speed);
    bullet.move(0,-speed);
}



int FBullet::getRight(){
    return bullet.getPosition().x + bullet.getSize().x;
}

int FBullet::getLeft(){
    return bullet.getPosition().x;
}

int FBullet::getTop(){
    return bullet.getPosition().y;
}

int FBullet::getBottom(){
    return bullet.getPosition().y + bullet.getSize().y;
}

void FBullet::draw(sf::RenderWindow &window)
{
    if (getBottom() >= 0 && getTop() <= HEIGHT + 200)
        window.draw(bullet);
}

void FBullet::setPos(sf::Vector2f newPos){
    bullet.setPosition(newPos);
}





