//
//  game.cpp
//  Raiden
//
//  Created by 王彥普 on 2021/1/8.
//  Copyright © 2021 !!!. All rights reserved.
//

#pragma once
#include "game.hpp"

Game::Game()
{
    ;
}

Game::~Game()
{
    ;
}

void Game::run()
{
    Texture t_vesta, t_plane;
    t_vesta.loadFromFile("../Resources/images/Vesta.jpg");
    t_plane.loadFromFile("../Resources/images/plane.png");
    RenderWindow window(VideoMode(WIDTH, HEIGHT), "RAIDEN");
    
    Sprite vesta(t_vesta);
    Sprite plane(t_plane);
    
    Vector2u planeSize;
    plane.setScale(0.4, 0.4);
    vesta.setPosition(0, 0);
    plane.setPosition(WIDTH/2, HEIGHT * 9 / 10);
    
    Clock clock;
    double dt;
    float speed = 500;
    
    while(window.isOpen())
    {
        dt = clock.restart().asSeconds();
        Event e;
        while(window.pollEvent(e))
        {
            if(e.type == Event::Closed)
                window.close();
            if (e.type == Event::KeyPressed && e.key.code == Keyboard::Escape)
                window.close();
        }
        
        
        if(Keyboard::isKeyPressed(Keyboard::W))
        {
            std::cout << "W";
            plane.move(0.f, -speed * dt);
        }
        if(Keyboard::isKeyPressed(Keyboard::S))
        {
            std::cout << "S";
            plane.move(0.f, speed * dt);
        }
        if(Keyboard::isKeyPressed(Keyboard::A))
        {
            std::cout << "A";
            plane.move(-speed * dt * 1.2, 0.f);
        }
        if(Keyboard::isKeyPressed(Keyboard::D))
        {
            std::cout << "D";
            plane.move(speed * dt * 1.2, 0.f);
        }
        
        window.clear();
        
        
        window.draw(vesta);
        window.draw(plane);
        window.display();
        
    }
}
