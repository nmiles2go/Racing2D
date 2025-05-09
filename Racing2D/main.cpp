﻿#include<iostream>
#include<math.h>

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
    S_Car.setPosition({ 200.0f,500.0f });
    S_Car.scale({ 0.95f, 0.95f });

    // Car movement variables
    float speed = 0.0f;
    float angle = 0.0f;
    float maxSpeed = 1.0f; // changes made for testing revert back to 8.0 later
    float accelaration = 0.01f;// changes made for testing revert back to 0.3 later
    float deaccelaration = 0.2f;
    float turnSpeed = 0.08f;

    float carPositionX = S_Car.getPosition().x;
    float carPositionY = S_Car.getPosition().y;


    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // Getting input from keyboard


        //   ██╗    ██╗ █████╗ ███████╗██████╗
        //   ██║    ██║██╔══██╗██╔════╝██╔══██╗
        //   ██║ █╗ ██║███████║███████╗██║  ██║     for car movement.
        //   ██║███╗██║██╔══██║╚════██║██║  ██║
        //   ╚███╔███╔╝██║  ██║███████║██████╔╝
        //    ╚══╝╚══╝ ╚═╝  ╚═╝╚══════╝╚═════╝


        // W to Move Forward
        // S to Move Backward
        // A to Turn Left
        // D to Turn Right

        // When key pressed (WASD), boolean values change to true

        bool goUp = 0;
        bool goDown = 0;
        bool turnLeft = 0;
        bool turnRight = 0;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) goUp = 1;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) goDown = 1;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) turnLeft = 1;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) turnRight = 1;

        // std::cout << goLeft << "\t" << goRight << "\t" << goUp << "\t" << goDown << "\n"; // DEBUG_LINE

        // Adding Car movement

        // Bug: When the velocity reaches above max speed (how?), then the car speed does not increase in the other direction.

       
        if (goUp && speed > -maxSpeed)
        {
            speed -= accelaration;
            std::cout << speed << "\n";

            // if((speed - maxSpeed) > 0.0001 && 
        }

        /*if (goDown && speed > -maxSpeed)
        {
            speed += accelaration;
            std::cout << (goDown && speed > -maxSpeed) << "\t\t" << speed << "\n";
        }*/

        else if (!goUp)
        {
            speed += deaccelaration;
            if (speed > 0.0f)
            {
                speed = 0.0f;
            }
            std::cout << speed << "\n";
        }



        









            carPositionY += speed;
            S_Car.setPosition({carPositionX,carPositionY});
            //S_Background.setPosition({ -carPositionX, -carPositionY }); // Linking "camera" background speed with speed of car!
                                                                                          // BAD I THINK?


            window.clear(sf::Color(158, 123, 123, 0));
            window.draw(S_Background);
            window.draw(S_Car);


            window.display();
        
    }
}
	

