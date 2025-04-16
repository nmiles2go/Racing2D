#include<iostream>
#include"SFML/Graphics.hpp"
#include"SFML/Audio.hpp"




int main()
{
    // Creating window for our game
    sf::RenderWindow window(sf::VideoMode({ 1080, 720 }), "2D TWO PLAYER RACER!");
    window.setFramerateLimit(60);

    // Importing 2D Textures for the car and Background
    sf::Texture T_Background, T_Car, t3;
    sf::RectangleShape Rect({ 2.0f,2.0f });

    // Importing textures and converting them to sprites
    T_Background.loadFromFile("images/background.png");
    T_Car.loadFromFile("images/car.png");
    T_Background.setSmooth(false);
    T_Car.setSmooth(false);

    sf::Sprite S_Background = sf::Sprite(T_Background);
    S_Background.scale({ 1.5f,1.5f });

    sf::Sprite S_Car = sf::Sprite(T_Car);
    S_Car.setOrigin({ 22.0f, 22.0f });
    S_Car.setPosition({200.0f,200.0f});
    S_Car.scale({ 0.95f, 0.95f });
    
    // Car movement variables
    float speed = 0.0f;
    float accelaration = 0.3f;
    
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // Getting input from keyboard

        //////////////////////////////////////////////////////////


        //   ██╗    ██╗ █████╗ ███████╗██████╗
        //   ██║    ██║██╔══██╗██╔════╝██╔══██╗
        //   ██║ █╗ ██║███████║███████╗██║  ██║     for car movement.
        //   ██║███╗██║██╔══██║╚════██║██║  ██║
        //   ╚███╔███╔╝██║  ██║███████║██████╔╝
        //    ╚══╝╚══╝ ╚═╝  ╚═╝╚══════╝╚═════╝

        // When key pressed (WASD), boolean values change to true

        bool up    = 0;
        bool down  = 0;
        bool left  = 0;
        bool right = 0;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            
            
            S_Car.setPosition({ 0.0f,0.0f });
        }
        

        window.clear(sf::Color(158,123,123,0));
        window.draw(S_Background);
        window.draw(S_Car);
        window.display();
    }
}
	

