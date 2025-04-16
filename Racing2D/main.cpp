#include<iostream>
#include"SFML/Graphics.hpp"



int main()
{   
    // Creating window for our game
    sf::RenderWindow window(sf::VideoMode({1080, 720}), "2D TWO PLAYER RACER!");
    window.setFramerateLimit(60);

    // Importing 2D Textures for the car and Background
    sf::Texture T_background, T_car, t3;

    T_background.loadFromFile("images/background.png");
    T_car.loadFromFile("images/car.png");
    T_background.setSmooth(true);
    T_car.setSmooth(true);

    sf::Sprite S_Background = sf::Sprite(T_background, sf::RectangleShape({2.0f, 30.0f})); //TODO figure out the correct methods
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear(sf::Color(158,123,123,0));
       
        window.display();
    }
}
	

