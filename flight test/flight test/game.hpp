//
//  game.hpp
//  flight test
//
//  Created by 王彥普 on 2021/1/5.
//  Copyright © 2021 !!!. All rights reserved.
//

#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Config.h"
#include "snake.hpp"
#include "props.hpp"
#include <ctime>
#include <iostream>
using namespace sf;


class Game
{
private:
    Snake s1, s2;
    Water w;
    Portion_1stType f;
    Portion_2ndType f2;
    Portion_3rdType f3;
    Bomb b;
    Brick br;
public:
    Game(); // init
    ~Game();
    void tick();
    int check(Snake s1, Snake s2);
    void dead(int playerID, RenderWindow &window);
    void run();
};
