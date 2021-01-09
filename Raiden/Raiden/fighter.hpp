//
//  fighter.hpp
//  Raiden
//
//  Created by 王彥普 on 2021/1/9.
//  Copyright © 2021 !!!. All rights reserved.
//

#pragma once
#include "config.h"

class Fighter
{
    friend class Game;
public:
    int health = 100;
    int life = 3;
    int bulletType = 1;
    bool alive = 1;
};
