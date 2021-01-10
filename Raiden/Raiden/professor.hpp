//
//  professor.hpp
//  
//
//  Created by 王彥普 on 2021/1/10.
//

#pragma once
#include "config.h"
#include <SFML/Graphics.hpp>
#include "Firebullet.hpp"

class Boss
{
private:
    int health = 100000;
    Texture t_plane;
    Sprite plane;
    bool alive = 1;
    int moveType = 1;
    
public:
    Boss();
    float getX() const;
    float getY() const;
    void setPosition(float x, float y);
    void move();
    float planeWidth() const;
    float planeHeight() const;
    int getPlayerNum() const;
    void checkCollision(FBullet bullet);
    void draw(RenderWindow& window);
    
};
