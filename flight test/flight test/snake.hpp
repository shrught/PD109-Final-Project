//
//  snake.hpp
//  flight test
//
//  Created by 王彥普 on 2021/1/6.
//  Copyright © 2021 !!!. All rights reserved.
//

#pragma once
#include "Config.h"

struct Snake
{
    int x[SNAKE_MAX_LEN];
    int y[SNAKE_MAX_LEN];
    int dir;
    int len;
    void init1();
    void init2();
    bool bomb;
};
