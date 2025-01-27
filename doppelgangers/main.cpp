#include<iostream>

#include <SFML/Graphics.hpp>

int main()
{
    std::string args = " test arguments";
    std::vector<std::string> arguments;
    std::string tmp;
    for (int i = 0; i < args.size(); ++i) {
        if (args[i] == ' ') {
            if (i != 0) {
                tmp.push_back(args[i]);
                arguments.push_back(tmp);
                tmp.clear();
            }
            while (args[i] == ' ') ++i;
        }
        tmp.push_back(args[i]);
    }
    arguments.push_back(tmp);



    for (std::string str : arguments) {
        std::cout << '\n';
        for (char i : str) {
            std::cout << i;
        }
    }
    //sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!", sf::Style::Default);
    //sf::CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Green);

    //while (window.isOpen())
    //{
    //    sf::Event event;
    //    while (window.pollEvent(event))
    //    {
    //        if (event.type == sf::Event::Closed)
    //            window.close();
    //    }

    //    window.clear();
    //    window.draw(shape);
    //    window.display();
    //}

    return 0;
}