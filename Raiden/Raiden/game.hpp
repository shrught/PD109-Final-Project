//
//  game.hpp
//  Raiden
//
//  Created by 王彥普 on 2021/1/8.
//  Copyright © 2021 !!!. All rights reserved.
//

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "config.h"
#include <ctime>
#include <iostream>
using namespace sf;


class Game
{
private:
public:
    Game(); // init
    ~Game();

    void run();
};

