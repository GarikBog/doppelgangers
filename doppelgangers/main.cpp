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
#include "doppenlgangers_objects.hpp"
#define POINTS_COUNTER
#endif // !POINTS_COUNTER

int main()
{

    int window_height = 1025, window_width = window_height / 1.24;
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "SFML works!",0);
    Log log;
    CardField cardField({0,window_width * 0.2 }, {825,860}, {window_width,window_height - window_width * 0.2 }, "fields/defolt.png", "cards/memes.png",log);
    std::cout <<"\n\n"<<window_width <<"\n" << window_width * 0.6<<"\n\n\n";
    Object background({ 0,0 }, { 825,1060 }, { window_width,window_height }, "backgrounds/defolt.png");

    RestartButton restart_button({ window_width * 0.6,0 }, { 100,100 }, { window_width / 5 ,window_width / 5 }, "", log);
    CloseButton close_button({ window_width * 0.8,0 }, { 100,100 }, { window_width / 5 ,window_width / 5 }, "",log);

    PointsCounter points_counter({ 0,0 }, { 60,35 }, { window_width - window_width* 2 / 5 ,window_width /5 }, "counters/defolt.png");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonReleased) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
                    points_counter.add_point();
                    cardField.click(mouse_pos);
                    restart_button.click(mouse_pos);
                    close_button.click(mouse_pos);
                }
                else {
                    cardField.close_all();
                }
            }
        }

        window.clear();
        background.draw(window);
        points_counter.draw(window);
        close_button.draw(window);
        restart_button.draw(window);
        cardField.draw(window);
        window.display();
    }

    return 0;

}