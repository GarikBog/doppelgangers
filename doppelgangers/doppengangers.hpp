#ifndef SFML_GRAPHICS
#include <SFML/Graphics.hpp>
#define SFML_GRAPHICS
#endif // !SFML_GRAPHICS

#ifndef FIELD
#include"CardField.hpp"
#define FIELD
#endif // !FIELD


#ifndef IOSTREAM
#include<iostream>
#define IOSTREAM
#endif // !IOSTREAM

#ifndef OBJECTS
#include "objects.hpp"
#define OBJECTS
#endif // !OBJECTS


#ifndef LOG
#include "log.hpp"
#define LOG
#endif // !LOG



class Doppelgagners {


private:
	unsigned int window_width = 0, window_height = 0;
	bool run = false;
	std::string name = "Doppelgangers";
	sf::RenderWindow* window;
	CardField* field;
	Object* background;
	Log log;

	std::vector<Object*> tmp_objects;
	std::vector<ClickableObject*> tmp_buttons;

	void draw();

	void restart();

public:

	void start();


	Doppelgagners(unsigned int height);
	~Doppelgagners();
};