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

#ifndef POINTS_COUNTER
#include "doppenlgangers_objects.hpp"
#define POINTS_COUNTER
#endif // !POINTS_COUNTER

class Doppelgagners {


private:
	unsigned int window_width = 0, window_height = 0;
	bool run = false;
	std::string name = "Doppelgangers";
	sf::RenderWindow* window;
	CardField* field;
	Object* background;
	PointsCounter* point_counter;
	CloseButton* close_button;
	RestartButton* restart_button;

	
	Log log;


	void draw();

	void restart();

	void process_log();

	void process_request(Request& request);
public:

	void start();


	Doppelgagners(unsigned int height);
	~Doppelgagners();
};