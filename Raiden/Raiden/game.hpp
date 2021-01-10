//
//  game.hpp
//  Raiden
//
//  Created by 王彥普 on 2021/1/8.
//  Copyright © 2021 !!!. All rights reserved.
//

#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <ctime>
#include <iostream>
#include<unistd.h>
#include <vector>

#include "config.h"
#include "fighter.hpp"
#include "enemy.hpp"
#include "Firebullet.hpp"
#include "professor.hpp"

using namespace sf;


class Game
{
    friend class FBullet;
    friend class Enemy;
    
private:
    Texture t_vesta;
    Sprite vesta;
    Texture t_victory;
    Sprite victory;
    RenderWindow window;
    
    Fighter player1;
    Fighter player2;
    Boss LCK;
    int playerNum = 1;
public:
    Game(); // init
    ~Game();
    void run();
};

