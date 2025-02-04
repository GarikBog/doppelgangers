#include<iostream>

#ifndef CARD
#include"card.hpp"
#define CARD
#endif // !CARD

#ifndef CARDFIELD
#include "CardField.hpp"
#define CARDFIELD
#endif // !CardField


#ifndef POINTS_COUNTER
#include "pointsCounter.hpp"
#define POINTS_COUNTER
#endif // !POINTS_COUNTER

int main()
{
    sf::RenderWindow window(sf::VideoMode(2000, 1750), "SFML works!");
    Log log;
    CardField cardField({50,50}, {825,860}, {825,860}, "fields/defolt.png", "cards/memes.png",log);

    PointsCounter counter({50,50},{60,35},{600,350},"counters/defolt.png");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonReleased) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    //cardField.click(sf::Mouse::getPosition(window));
                    counter.add_point();
                }
                else {
                    cardField.close_all();
                }
            }
        }

        window.clear();
        counter.draw(window);
        //cardField.draw(window);
        window.display();
    }

    return 0;

}