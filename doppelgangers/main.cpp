#include<iostream>

#ifndef CARD
#include"card.hpp"
#define CARD
#endif // !CARD

#ifndef FIELD
#include "field.hpp"
#define FIELD
#endif // !FIELD

int main()
{
    sf::RenderWindow window(sf::VideoMode(2000, 1750), "SFML works!");

    Field field({50,50}, {825,860}, {825,860}, "fields/defolt.png", "cards/memes.png");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonReleased) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    field.open_all();
                }
                else {
                    field.close_all();
                }
            }
        }

        window.clear();
        field.draw(window);
        window.display();
    }

    return 0;

}