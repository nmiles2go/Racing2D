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
    float speed = 1.0f;
    float maxSpeed = 12.0f;
    float accelaration = 0.3f;
    
    float x = 300.0f;
    float y = 300.0f;

    float angle = 0.0f;
    float turnSpeed = 0.08f;

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

        bool goUp    = 0;
        bool goDown  = 0;
        bool goLeft  = 0;
        bool goRight = 0;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) goLeft = 1;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) goRight = 1;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) goUp = 1;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) goDown = 1;
        
        // std::cout << goLeft << "\t" << goRight << "\t" << goUp << "\t" << goDown << "\n"; // DEBUG_LINE

        // Adding Car movement
        if (goLeft && speed)// < maxSpeed) 
        {
            speed += accelaration;
            
        }
        
        x = speed;
        std::cout << speed << "\t\n";
        S_Car.setPosition({x,y});

        
        window.clear(sf::Color(158,123,123,0));
        window.draw(S_Background);
        window.draw(S_Car);


        window.display();
    }
}
	

