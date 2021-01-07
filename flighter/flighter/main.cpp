
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// In order to load the resources like cute_image.png, you have to set up
// your target scheme:
//
// - Select "Edit Scheme…" in the "Product" menu;
// - Check the box "use custom working directory";
// - Fill the text field with the folder path containing your resources;
//        (e.g. your project folder)
// - Click OK.
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(2000, 1500), "SFML window");

    // Set the Icon
//    sf::Image icon;
//    if (!icon.loadFromFile("icon.png")) {
//        return EXIT_FAILURE;
//    }
//    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
//
//    // Load a sprite to display
//    sf::Texture texture;
//    if (!texture.loadFromFile("cute_image.jpg")) {
//        return EXIT_FAILURE;
//    }
//    sf::Sprite sprite(texture);
//
//    // Create a graphical text to display
//    sf::Font font;
//    if (!font.loadFromFile("sansation.ttf")) {
//        return EXIT_FAILURE;
//    }
//    sf::Text text("Hello SFML", font, 50);
//    text.setFillColor(sf::Color::Black);
//
    // Load a music to play
    sf::Music music;
    if (!music.openFromFile("nice_music.ogg")) {
        return EXIT_FAILURE;
    }

    // Play the music
    music.play();

    sf::Clock clock;
    double dt;
    
    sf::Sprite player;
    sf::Texture playerTexture;
    float speed = 500.f;
    
    if(!playerTexture.loadFromFile("plane.png")) //load the texture from an image
    {
        cout << "ERROR: FILE COULDN'T BE LOADED" << endl; //falback message
    }
    player.setPosition(5, 0);
    player.setTexture(playerTexture);
    player.setScale(1, 1);
    
    // Start the game loop
    while (window.isOpen())
    {
        dt = clock.restart().asSeconds();
        
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            player.move(0.f, -speed * dt);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            player.move(0.f, speed * dt);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            player.move(-speed * dt, 0.f);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
             player.move(speed * dt, 0.f);
        }

        // Clear screen
        window.clear();

//        // Draw the sprite
//        window.draw(sprite);
//
//        // Draw the string
//        window.draw(text);

        // Update the window
        window.draw(player);
        window.display();
    }

    return EXIT_SUCCESS;
}
