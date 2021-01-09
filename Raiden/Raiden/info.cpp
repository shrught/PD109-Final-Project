//
//  info.cpp
//  Raiden
//
//  Created by 王彥普 on 2021/1/8.
//  Copyright © 2021 !!!. All rights reserved.
//

#include "info.hpp"
#include <iostream>


Info::Info(float width, float height)
{
    // if (!font.loadFromFile("resources/fonts/prstartk.ttf"))
    // {
    //     // handle error
    // }

    if (!pages_texture[0].loadFromFile("../Resources/images/instra1.png"))
    {
        // handle error
    }
    if (!pages_texture[1].loadFromFile("../Resources/images/instra2.png"))
    {
        // handle error
    }
    if (!pages_texture[2].loadFromFile("../Resources/images/instra3.png"))
    {
        // handle error
    }

    pages[0].setTexture(pages_texture[0]);
    pages[1].setTexture(pages_texture[1]);
    pages[2].setTexture(pages_texture[2]);
    

    selectedPageIndex = 0;
}

Info::~Info()
{
}

void Info::info_state()
{
    const int SIZE = 15; // default: 15 --> Do not modify
    const int W = 60, H = 50; // 60, 50
    const int WIDTH = SIZE * W;
    const int HEIGHT = SIZE * H;
    
    
    SoundBuffer buffer;
    if (!buffer.loadFromFile("../Resources/audio/pop.wav"))
        return;
    Sound pop;
    pop.setVolume(50);
    pop.setBuffer(buffer);
    SoundBuffer bLeave;
    if (!bLeave.loadFromFile("../Resources/audio/option.wav"))
        return;
    Sound leave;
    leave.setVolume(50);
    leave.setBuffer(bLeave);
    RenderWindow window(VideoMode(WIDTH, HEIGHT), "A CNAKE");
    // int pageIndex = 1;
    while(window.isOpen())
    {
        Event event;
        Clock clock;
        float timer = 0, limit = 0.3;
        

        while(window.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::KeyReleased:
                switch (event.key.code)
                {
                case Keyboard::Left:
                case Keyboard::Up:
                    pop.play();
                    if (selectedPageIndex - 1 >= 0) selectedPageIndex--;
                    break;
                case Keyboard::Right:
                case Keyboard::Down:
                    pop.play();
                    if (selectedPageIndex + 1 < MAX_NUM_OF_PAGES) selectedPageIndex++;
                    break;
                case Keyboard::Space:
                case Keyboard::Return:
                    leave.play();
                    while (timer < limit)
                    {
                        float time = clock.getElapsedTime().asSeconds();
                        clock.restart();
                        timer += time;
                    }
                            
                    window.close();
                    break;
                }
                break;
            case Event::Closed:
                window.close();
                break;
            }
        }
        
        window.clear();
        draw(window, pages[selectedPageIndex]);
        window.display();
    
    }
}

void Info::draw(RenderWindow &window, Sprite &page)
{
    // window.clear();
    window.draw(page);
    
    // for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    // {
    //     window.draw(pages[i]);
    // }
}

void Info::prevPage()
{
    if (selectedPageIndex - 1 >= 0)
    {
        selectedPageIndex--;
        std::cout << selectedPageIndex << std::endl;
        // return selectedPageIndex;
    }
    // else return selectedPageIndex;
}

void Info::nextPage()
{
    if (selectedPageIndex + 1 < MAX_NUM_OF_PAGES)
    {
        // pages[selectedItemIndex].setColor(Color(255, 255, 255, 180));
        // selectedItemIndex++;
        // pages[selectedItemIndex].setColor(Color(254, 255, 212, 255));
        selectedPageIndex++;
        std::cout << selectedPageIndex << std::endl;
        return;
        // return selectedPageIndex;
    }
    // else return selectedPageIndex;
}

