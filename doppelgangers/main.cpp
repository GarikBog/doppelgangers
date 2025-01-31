#include<iostream>

#ifndef CARD
#include"card.hpp"
#define CARD
#endif // !CARD


int main()
{
    sf::RenderWindow window(sf::VideoMode(2000, 1750), "SFML works!");


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        card.draw(window);
        window.display();
    }

    return 0;

}