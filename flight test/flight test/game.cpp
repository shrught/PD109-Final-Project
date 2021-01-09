//
//  game.cpp
//  flight test
//
//  Created by 王彥普 on 2021/1/5.
//  Copyright © 2021 !!!. All rights reserved.
//

#include "game.hpp"

Game::Game()
{
    // init
}
Game::~Game()
{
    // endgame
}

void Game::tick()
{
    static int tickCnt = 0;
    static SoundBuffer b1, b2, b3, b4, b5, b6, b7, b8;
    static Sound explosion, wallHit, drink1, drink2, drink3, potionCreated, water, collision;
    if (tickCnt == 0)
    {
        if (!b1.loadFromFile("resources/audio/explode.wav")) return;
        explosion.setVolume(50);
        explosion.setBuffer(b1);
        if (!b2.loadFromFile("resources/audio/wall-hit.wav")) return;
        wallHit.setVolume(50);
        wallHit.setBuffer(b2);

        if (!b3.loadFromFile("resources/audio/potion-drinking.wav")) return;
        potionCreated.setVolume(50);
        potionCreated.setBuffer(b3);
        if (!b4.loadFromFile("resources/audio/water.wav")) return;
        water.setVolume(90);
        water.setBuffer(b4);
        if (!b5.loadFromFile("resources/audio/collision.wav")) return;
        collision.setVolume(90);
        collision.setBuffer(b5);
        if (!b6.loadFromFile("resources/audio/drink1.wav")) return;
        drink1.setVolume(90);
        drink1.setBuffer(b6);
        if (!b7.loadFromFile("resources/audio/drink2.wav")) return;
        drink2.setVolume(90);
        drink2.setBuffer(b7);
        if (!b8.loadFromFile("resources/audio/drink3.wav")) return;
        drink3.setVolume(90);
        drink3.setBuffer(b8);
        

        

        tickCnt++;
    }
    
    
    for(int i = s1.len; i > 0; i--)
    {
        s1.x[i] = s1.x[i - 1];
        s1.y[i] = s1.y[i - 1];
    }
    for(int i = s2.len; i > 0; i--)
    {
        s2.x[i] = s2.x[i - 1];
        s2.y[i] = s2.y[i - 1];
    }
    
    if(s1.dir == down) s1.y[0] += 1; // down
    if(s1.dir == left) s1.x[0] -= 1; // left
    if(s1.dir == right) s1.x[0] += 1; // right
    if(s1.dir == up) s1.y[0] -= 1; // up
    
    if(s2.dir == down) s2.y[0] += 1;
    if(s2.dir == left) s2.x[0] -= 1;
    if(s2.dir == right) s2.x[0] += 1;
    if(s2.dir == up) s2.y[0] -= 1;
    
    
    // eat portion_1stType
    for (int j = 0;j < 3;j++)
    {
        if((s1.x[0] == f.x[j]) && (s1.y[0] == f.y[j]))
        {
            s1.len++;
            drink1.play();
            // generate new portion_1stType
            bool overlap = true;
            while(overlap)
            {
                bool flag = false;
                f.x[j] = rand() % W;
                f.y[j] = rand() % H;
                for (int i = 0; i < 300;i++)
                {
                    if (f.x[j] == b.x[i] && f.y[j] == b.y[i])
                    {
                        flag = true;
                        break;
                    }
                }
                for (int i = 0; i < 36;i++)
                {
                    if (f.x[j] == br.x[i] && f.y[j] == br.y[i])
                    {
                        flag = true;
                        break;
                    }
                }
                for (int i = 0; i < 25;i++)
                {
                    if (f.x[j] == w.x[i] && f.y[j] == w.y[i])
                    {
                        flag = true;
                        break;
                    }
                }
                if (!flag)
                {
                    overlap = false;
                }
            }
        }
    }
    for (int j = 0;j < 3;j++)
    {
        if((s2.x[0] == f.x[j]) && (s2.y[0] == f.y[j]))
        {
            s2.len++;
            drink1.play();
            // generate new portion_1stType
            bool overlap = true;
            while(overlap)
            {
                bool flag = false;
                f.x[j] = rand() % W;
                f.y[j] = rand() % H;
                for (int i = 0; i < 300;i++)
                {
                    if (f.x[j] == b.x[i] && f.y[j] == b.y[i])
                    {
                        flag = true;
                        break;
                    }
                }
                for (int i = 0; i < 36;i++)
                {
                    if (f.x[j] == br.x[i] && f.y[j] == br.y[i])
                    {
                        flag = true;
                        break;
                    }
                }
                for (int i = 0; i < 25;i++)
                {
                    if (f.x[j] == w.x[i] && f.y[j] == w.y[i])
                    {
                        flag = true;
                        break;
                    }
                }
                if (!flag)
                {
                    overlap = false;
                }
            }
        }
    }
    // eat portion_2ndType
    for (int j = 0;j < 2;j++)
    {
        if((s1.x[0] == f2.x[j]) && (s1.y[0] == f2.y[j]))
        {
            s1.len++;
            drink2.play();
            // generate new portion_1stType
            bool overlap = true;
            while(overlap)
            {
                bool flag = false;
                f2.x[j] = rand() % W;
                f2.y[j] = rand() % H;
                for (int i = 0; i < 300;i++)
                {
                    if (f2.x[j] == b.x[i] && f2.y[j] == b.y[i])
                    {
                        flag = true;
                        break;
                    }
                }
                for (int i = 0; i < 36;i++)
                {
                    if (f2.x[j] == br.x[i] && f2.y[j] == br.y[i])
                    {
                        flag = true;
                        break;
                    }
                }
                for (int i = 0; i < 25;i++)
                {
                    if (f2.x[j] == w.x[i] && f2.y[j] == w.y[i])
                    {
                        flag = true;
                        break;
                    }
                }
                if (!flag)
                {
                    overlap = false;
                }
            }
        }
    }
    for (int j = 0;j < 2;j++)
    {
        if((s2.x[0] == f2.x[j]) && (s2.y[0] == f2.y[j]))
        {
            s2.len++;
            drink2.play();
            // generate new portion_2ndType
            bool overlap = true;
            while(overlap)
            {
                bool flag = false;
                f2.x[j] = rand() % W;
                f2.y[j] = rand() % H;
                for (int i = 0; i < 300;i++)
                {
                    if (f2.x[j] == b.x[i] && f2.y[j] == b.y[i])
                    {
                        flag = true;
                        break;
                    }
                }
                for (int i = 0; i < 36;i++)
                {
                    if (f2.x[j] == br.x[i] && f2.y[j] == br.y[i])
                    {
                        flag = true;
                        break;
                    }
                }
                for (int i = 0; i < 25;i++)
                {
                    if (f2.x[j] == w.x[i] && f2.y[j] == w.y[i])
                    {
                        flag = true;
                        break;
                    }
                }
                if (!flag)
                {
                    overlap = false;
                }
            }
        }
    }
    // eat portion_3rdType
    if((s1.x[0] == f3.x) && (s1.y[0] == f3.y))
    {
        s1.len++;drink3.play();
        // generate new portion_3rdType
        bool overlap = true;
        while(overlap)
        {
            bool flag = false;
            f3.x = rand() % W;
            f3.y = rand() % H;
            for (int i = 0; i < 300;i++)
            {
                if (f3.x == b.x[i] && f3.y == b.y[i])
                {
                    flag = true;
                    break;
                }
            }
            for (int i = 0; i < 36;i++)
            {
                if (f3.x == br.x[i] && f3.y == br.y[i])
                {
                    flag = true;
                    break;
                }
            }
            for (int i = 0; i < 25;i++)
            {
                if (f3.x == w.x[i] && f3.y == w.y[i])
                {
                    flag = true;
                    break;
                }
            }
            if (!flag)
            {
                overlap = false;
            }
        }
    }
    if((s2.x[0] == f3.x) && (s2.y[0] == f3.y))
    {
        s2.len++;
        drink3.play();
        // generate new portion_3rdType
        bool overlap = true;
        while(overlap)
        {
            bool flag = false;
            f3.x = rand() % W;
            f3.y = rand() % H;
            for (int i = 0; i < 300;i++)
            {
                if (f3.x == b.x[i] && f3.y == b.y[i])
                {
                    flag = true;
                    break;
                }
            }
            for (int i = 0; i < 36;i++)
            {
                if (f3.x == br.x[i] && f3.y == br.y[i])
                {
                    flag = true;
                    break;
                }
            }
            for (int i = 0; i < 25;i++)
            {
                if (f3.x == w.x[i] && f3.y == w.y[i])
                {
                    flag = true;
                    break;
                }
            }
            if (!flag)
            {
                overlap = false;
            }
        }
    }
    
    // generate bomb from snake's bottom
    static bool bomb_created = false;
    if(s1.bomb == true)
    {
        if (bomb_created == false && s1.len > 1)
        {
            b.x[b.index] = s1.x[s1.len - 1];
            b.y[b.index] = s1.y[s1.len - 1];
            b.index++;
        }
        s1.bomb = false;
    }
    if(s2.bomb == true)
    {
        // static bool bomb_created = false;
        if (bomb_created == false && s2.len > 1)
        {
            b.x[b.index] = s2.x[s2.len - 1];
            b.y[b.index] = s2.y[s2.len - 1];
            b.index++;
            //            bomb_created = true;
        }
        s2.bomb = false;
    }
    
    // collided with bomb
    for (int i = 0;i < b.index;i++)
    {
        if((s1.x[0] == b.x[i]) && (s1.y[0] == b.y[i]))
        {
            if(s1.len >=3)
                s1.len -= 3;
            else
                s1.len = 0;
            b.x[i] = -1;
            b.y[i] = -1;
            bomb_created = false;
            explosion.play();
        }
    }
    for (int i = 0;i < b.index;i++)
    {
        if((s2.x[0] == b.x[i]) && (s2.y[0] == b.y[i]))
        {
            if(s2.len >=3)
                s2.len -= 3;
            else
                s2.len = 0;
            b.x[i] = -1;
            b.y[i] = -1;
            bomb_created = false;
            explosion.play();
        }
    }
    // collided with water
    for(int i = 0; i < 25 ;i++)
    {
        if ((s1.x[0] == w.x[i]) && (s1.y[0] == w.y[i]))
        {
            s1.len = 0;
            water.play();
        }
    }
    for(int i = 0;i < 25;i++)
    {
        if((s2.x[0] == w.x[i]) && (s2.y[0] == w.y[i]))
        {
            s2.len = 0;
            water.play();
        }
    }
    // collided with brick
    for(int i = 0;i < 36;i++)
    {
        if((s1.x[0] == br.x[i]) && (s1.y[0] == br.y[i]))
        {
            s1.len = 0;
            wallHit.play();
        }
    }
    for(int i = 0;i < 36;i++)
    {
        if((s2.x[0] == br.x[i]) && (s2.y[0] == br.y[i]))
        {
            s2.len = 0;
            wallHit.play();
        }
    }
    // over map size
    if(s1.x[0] >= W) s1.x[0] = 0;
    if(s1.x[0] < 0) s1.x[0] = W - 1;
    if(s1.y[0] >= H) s1.y[0] = 0;
    if(s1.y[0] < 0) s1.y[0] = H - 1;
    
    if(s2.x[0] >= W) s2.x[0] = 0;
    if(s2.x[0] < 0) s2.x[0] = W - 1;
    if(s2.y[0] >= H) s2.y[0] = 0;
    if(s2.y[0] < 0) s2.y[0] = H - 1;
    
    // self-collision
    for(int i = 1; i < s1.len; i++)
        if(s1.x[0] == s1.x[i] && s1.y[0] == s1.y[i])
            {
                s1.len = 0;
                collision.play();
            }
    for(int i = 1; i < s2.len; i++)
        if(s2.x[0] == s2.x[i] && s2.y[0] == s2.y[i])
            {
                s2.len = 0;
                collision.play();
            }
    // mutual collision
    for(int i = 1; i < s2.len; i++)
        if(s1.x[0] == s2.x[i] && s1.y[0] == s2.y[i])
            {
                s1.len = 0;
                collision.play();
            }
    for(int i = 1; i < s1.len; i++)
        if(s2.x[0] == s1.x[i] && s2.y[0] == s1.y[i])
            {
                s2.len = 0;
                collision.play();
            }
    // 頭撞頭
    if(s1.x[0] == s2.x[0] && s1.y[0] == s2.y[0])
    {
        // 相撞
        if( (s1.dir == 1 && s2.dir == 2) || (s1.dir == 2 && s2.dir == 1) || (s1.dir == 3 && s2.dir == 0) || (s1.dir == 0 && s2.dir == 3))
        {
            if(s1.len > s2.len) s2.len = 0;
            else if (s1.len < s2.len) s1.len = 0;
            else
            {
                // 平手
                s1.len = 0;
                s2.len = 0;
                collision.play();
            }
        }
        // 側面撞頭
        else
        {
            s1.len = 0;
            s2.len = 0;
            collision.play();
        }
    }
}


int Game::check(Snake s1, Snake s2)
{
    int playerID = 0;
    if (s1.len == 0 && s2.len == 0) return playerID = 3;
    else if (s2.len == 0) return playerID = 1;
    else if (s1.len == 0) return playerID = 2;
    else return playerID;

}

void Game::dead(int playerID, RenderWindow &window)
{
    SoundBuffer buffer;
     if (!buffer.loadFromFile("resources/audio/cheering.wav")) return;

    Sound cheer;
    cheer.setVolume(50);
    cheer.setBuffer(buffer);
    cheer.play();
    Texture texture_p1win, texture_p2win, texture_tie;
    texture_p1win.loadFromFile("resources/images/player1wins.png");
    texture_p2win.loadFromFile("resources/images/player2wins.png");
    texture_tie.loadFromFile("resources/images/tie.png");

    Sprite p1(texture_p1win);
    Sprite p2(texture_p2win);
    Sprite tie(texture_tie);

    if (playerID == 1) window.draw(p1);
    else if (playerID == 2) window.draw(p2);
    else if (playerID == 3) window.draw(tie);
    
    window.display();
    Clock clock;
    float timer = 0, limit = 1.5;
    while (timer < limit)
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;
    }
    
}


void Game::run()
{
    RenderWindow window(VideoMode(WIDTH, HEIGHT), "A CNAKE");
    s1.init1();
    s2.init2();
    b.init();
    f.init();
    br.init();
    f2.init();
    f3.init();
    w.init();

    Texture texture_background, texture_player1, texture_player2, texture_fruit, texture_bomb, texture_brick, texture_fruit2, texture_fruit3, texture_water;
    texture_background.loadFromFile("/Users/wangyanpu/Desktop/台灣大學/大二上/程設設計/期末報告/A-Cnake/resources/images/grass.png");
    texture_player1.loadFromFile("/Users/wangyanpu/Desktop/台灣大學/大二上/程設設計/期末報告/A-Cnake/resources/images/blue.png");
    texture_player2.loadFromFile("/Users/wangyanpu/Desktop/台灣大學/大二上/程設設計/期末報告/A-Cnake/resources/images/yellow.png");
    texture_fruit.loadFromFile("/Users/wangyanpu/Desktop/台灣大學/大二上/程設設計/期末報告/A-Cnake/resources/images/purple-potion.png");
    texture_bomb.loadFromFile("/Users/wangyanpu/Desktop/台灣大學/大二上/程設設計/期末報告/A-Cnake/resources/images/bomb.png");
    texture_brick.loadFromFile("/Users/wangyanpu/Desktop/台灣大學/大二上/程設設計/期末報告/A-Cnake/resources/images/brick.png");
    texture_fruit2.loadFromFile("/Users/wangyanpu/Desktop/台灣大學/大二上/程設設計/期末報告/A-Cnake/resources/images/white-potion.png");
    texture_fruit3.loadFromFile("/Users/wangyanpu/Desktop/台灣大學/大二上/程設設計/期末報告/A-Cnake/resources/images/pink-potion.png");
    texture_water.loadFromFile("/Users/wangyanpu/Desktop/台灣大學/大二上/程設設計/期末報告/A-Cnake/resources/images/water.png");
    
    Sprite background(texture_background);
    Sprite player1(texture_player1);
    Sprite player2(texture_player2);
    Sprite portion_1stType(texture_fruit);
    Sprite bomb(texture_bomb);
    Sprite brick(texture_brick);
    Sprite portion_2ndType(texture_fruit2);
    Sprite portion_3rdType(texture_fruit3);
    Sprite water(texture_water);
    
    Clock clock;
    float timer = 0, delay = 0.07; // adjusting delay will affect the speed // default = 0.07
    s1.bomb = false;
    s2.bomb = false;
    SoundBuffer buffer;
    if (!buffer.loadFromFile("/Users/wangyanpu/Desktop/台灣大學/大二上/程設設計/期末報告/A-Cnake/resources/audio/bomb-planted.wav")) return;
    Sound bombPlanted;
    bombPlanted.setVolume(50);
    bombPlanted.setBuffer(buffer);
    SoundBuffer buffer2;
    if (!buffer2.loadFromFile("/Users/wangyanpu/Desktop/台灣大學/大二上/程設設計/期末報告/A-Cnake/resources/audio/pop.wav"))
        return;
    Sound pop;
    pop.setVolume(50);
    pop.setBuffer(buffer2);


    
    while(window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;
        
        Event e;
        while(window.pollEvent(e))
        {
            if(e.type == Event::Closed)
                window.close();
        }
        
        // should be modified
        if(Keyboard::isKeyPressed(Keyboard::Left))
        {if(s1.dir != right) s1.dir = left;}
        else if(Keyboard::isKeyPressed(Keyboard::Right))
            if(s1.dir != left) s1.dir = right;
        if(Keyboard::isKeyPressed(Keyboard::Up))
            if(s1.dir != down) s1.dir = up;
        if(Keyboard::isKeyPressed(Keyboard::Down))
            if(s1.dir != up) s1.dir = down;
        
        
        if(Keyboard::isKeyPressed(Keyboard::A))
            {if(s2.dir != right) s2.dir = left;}
        else if(Keyboard::isKeyPressed(Keyboard::D))
            if(s2.dir != left) s2.dir = right;
        if(Keyboard::isKeyPressed(Keyboard::W))
            if(s2.dir != down) s2.dir = up;
        if(Keyboard::isKeyPressed(Keyboard::S))
            if(s2.dir != up) s2.dir = down;
        
        //place bomb
        
        if(Keyboard::isKeyPressed(Keyboard::L))
            if(b.x[b.index] == -1 && b.y[b.index] == -1)
            {
                bombPlanted.play();
                s1.bomb = true;
            }
                
        if(Keyboard::isKeyPressed(Keyboard::LShift))
            if(b.x[b.index] == -1 && b.y[b.index] == -1)
            {
                bombPlanted.play();
                s2.bomb = true;
            }
        // ===== until here =====
        bool pause = false;
        if(Keyboard::isKeyPressed(Keyboard::BackSpace)) {
            pause = true;
            pop.play();
        }
            
        int checkFlag = check(s1, s2);
        if(timer > delay)
        {
            timer = 0;
            tick();
            if (checkFlag)
            {
                dead(checkFlag, window);
                window.close();
                // window.close();
            }
        }
        
        window.clear();
        for(int i = 0; i < W; i++)
        {
            for(int j = 0; j < H; j++)
            {
                background.setPosition(i * SIZE, j * SIZE);
                window.draw(background);
            }
        }
        for(int i = 0; i < s1.len; i++)
        {
            player1.setPosition(s1.x[i] * SIZE, s1.y[i] * SIZE);
            window.draw(player1);
        }
        
        for(int i = 0; i < s2.len; i++)
        {
            player2.setPosition(s2.x[i] * SIZE, s2.y[i] * SIZE);
            window.draw(player2);
        }
        
        //draw water
        for (int i = 0;i < 25;i++)
        {
            water.setPosition(w.x[i] * SIZE,  w.y[i] * SIZE);
            window.draw(water);
        }
        // draw brick
        for (int i = 0;i < 36;i++)
        {
            brick.setPosition(br.x[i] * SIZE,  br.y[i] * SIZE);
            window.draw(brick);
        }
        // draw portion_1stType
        for(int i = 0;i < 3;i++)
        {
            portion_1stType.setPosition(f.x[i] * SIZE,  f.y[i] * SIZE);
            window.draw(portion_1stType);
        }
        // draw portion_2ndType
        for(int i = 0;i < 2;i++)
        {
            portion_2ndType.setPosition(f2.x[i] * SIZE,  f2.y[i] * SIZE);
            window.draw(portion_2ndType);
        }
        // draw portion_3rdType
        portion_3rdType.setPosition(f3.x * SIZE,  f3.y * SIZE);
        window.draw(portion_3rdType);

        // draw bomb
        for (int i = 0;i < b.index;i++)
        {
            bomb.setPosition(b.x[i] * SIZE, b.y[i] * SIZE);
            window.draw(bomb);
        }
        
        while (pause)
        {
            std::cout << "Game paused" << std::endl;
            static bool first_time = true;
            time = clock.getElapsedTime().asSeconds();
            clock.restart();
            timer += time;
            static int cnt = 1;
            
            // 轉成 case 會比較好 目前這種寫法有點問題
            if(Keyboard::isKeyPressed(Keyboard::BackSpace)){
                pause = false;
                pop.play();
            }

            if(timer > delay)
            {
                timer = 0;
                if (pause == false) break;
            }
            
        }
        window.display();
    }
}
