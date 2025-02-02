#include<iostream>

#ifndef CARD
#include"card.hpp"
#define CARD
#endif // !CARD

#ifndef CARDFIELD
#include "CardField.hpp"
#define CARDFIELD
#endif // !CardField

int main()
{
    sf::RenderWindow window(sf::VideoMode(2000, 1750), "SFML works!");
    Log log;
    CardField cardField({50,50}, {825,860}, {825,860}, "CardFields/defolt.png", "cards/memes.png",log);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonReleased) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    cardField.click(sf::Mouse::getPosition(window));
                }
                else {
                    cardField.close_all();
                }
            }
        }

        window.clear();
        cardField.draw(window);
        window.display();
    }

    return 0;

}