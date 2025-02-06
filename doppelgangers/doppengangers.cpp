#ifndef DOPPELGANGERS
#include "doppengangers.hpp"
#define DOPPELGANGERS
#endif // !DOPPELGANGERS


void Doppelgagners::draw()
{
	background->draw(*window);
	field->draw(*window);
	restart_button->draw(*window);
	close_button->draw(*window);
}

void Doppelgagners::restart()
{
	point_counter->nullify();
	field->close_all();
	field->recombinate();
	field->recombinate();

}

void Doppelgagners::process_log()
{
    Request next = log.get_request();
    while (next.data().first != "OPEN_CARD" && next.data().first != "EMPTY")
    {
        process_request(next);
        next = log.get_request();
    }
    log.add(next);
}

void Doppelgagners::process_request(Request& request)
{
    if (request.data().first == "RESTART") restart();
    if (request.data().first == "CLOSE") window->close();
    if (request.data().first == "ADD_POINT") point_counter->add_point();
}

void Doppelgagners::start()
{
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
            if (event.type == sf::Event::MouseButtonReleased) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mouse_pos = sf::Mouse::getPosition(*window);
                    close_button->click(mouse_pos);
                    restart_button->click(mouse_pos);
                    field->click(mouse_pos);

                    process_log();
                    
                }
                else {
                    field->close_all();
                }
            }
        }

        window->clear();

        background->draw(*window);
        point_counter->draw(*window);
        close_button->draw(*window);
        restart_button->draw(*window);
        field->draw(*window);

        window->display();
    }
}

Doppelgagners::Doppelgagners(unsigned int height)
{
	window_height = height;
	window_width = window_height / 1.24;

	window = new sf::RenderWindow(sf::VideoMode{ window_width,window_height }, name, 0);
	field =  new CardField({ 0,window_width * 0.2 }, { 825,860 }, { window_width,window_height - window_width * 0.2 }, "fields/defolt.png", "cards/memes.png", log);

	point_counter = new PointsCounter({ 0,0 }, { 60,35 }, { window_width * 3 / 5 ,window_width / 5 }, "counters/defolt.png");
	background = new Object({0,0},{1025,825},{window_width,window_height},"background/defolt.png");

	restart_button = new RestartButton({ window_width * 0.6,0 }, { 100,100 }, { window_width / 5 ,window_width / 5 }, "", log);
	close_button = new CloseButton({ window_width * 0.8,0 }, { 100,100 }, { window_width / 5 ,window_width / 5 }, "", log);

}

Doppelgagners::~Doppelgagners()
{
	delete restart_button;
	delete close_button;
	delete point_counter;
	delete field;
	delete background;
	delete window;
}
