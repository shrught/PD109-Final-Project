//
//  props.cpp
//  flight test
//
//  Created by 王彥普 on 2021/1/6.
//  Copyright © 2021 !!!. All rights reserved.
//

#include "props.hpp"

void Water::init()
{
    for(int i = 0;i < 25;i++)
    {
        if(i < 5)
        {
            x[i] = 28 + i;
            y[i] = 23;
        }
        else if(i >= 5 && i < 10)
        {
            x[i] = 23 + i;
            y[i] = 24;
        }
        else if(i >= 10 && i < 15)
        {
            x[i] = 18 + i;
            y[i] = 25;
        }
        else if(i >= 15 && i < 20)
        {
            x[i] = 13 + i;
            y[i] = 26;
        }
        else if(i >= 20 && i < 25)
        {
            x[i] = 8 + i;
            y[i] = 27;
        }
    }
}


void Portion_1stType::init()
{
    x[0] = 10;
    y[0] = 14;
    x[1] = 20;
    y[1] = 27;
    x[2] = 30;
    y[2] = 5;
}

void Portion_2ndType::init()
{
    x[0] = 15;
    y[0] = 35;
    x[1] = 31;
    y[1] = 40;
}

void Portion_3rdType::init()
{
    x = 4;
    y = 30;
}

void Bomb::init()
{
    for(int i = 0;i < 300;i++)
    {
        x[i] = -1;
        y[i] = -1;
    }
    index = 0;
}

void Brick::init()
{
    for(int i = 0; i < 36;i++)
    {
        if(i < 5)
        {
            x[i] = 7 + i;
            y[i] = 7;
        }
        else if (i >= 5 && i < 10)
        {
            x[i] = 44 + i;
            y[i] = 7;
        }
        else if (i >= 10 && i < 15)
        {
            x[i] = -3 + i;
            y[i] = 43;
        }
        else if (i >= 15 && i < 20)
        {
            x[i] = 34 + i;
            y[i] = 43;
        }
        else if (i >= 20 && i < 24)
        {
            x[i] = 7;
            y[i] = -12 + i;
        }
        else if (i >= 24 && i < 28)
        {
            x[i] = 7;
            y[i] = 15 + i;
        }
        else if (i >= 28 && i < 32)
        {
            x[i] = 53;
            y[i] = -20 + i;
        }
        else if (i >= 32 && i < 36)
        {
            x[i] = 53;
            y[i] = 7 + i;
        }
    }
}
