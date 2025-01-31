#ifndef SFML_GRAPHICS
#include <SFML/Graphics.hpp>
#define SFML_GRAPHICS
#endif // !SFML_GRAPHICS

#ifndef LOG
#include "log.hpp"
#define LOG
#endif // !LOG

#ifndef OBJECTS
#include "objects.hpp"
#define OBJECTS
#endif // !OBJECTS

#ifndef CARD
#include"card.hpp"
#define CARD
#endif // !CARD


class Field : public Object{

private:
	//SIZE POS
	int card_width = 0, card_height = 0,indent_width = 0,indent_height = 0,indent_between_widht = 0,indent_between_height = 0;

	//TECH
	std::vector<Card*> cards;

public:
	
	 
	//TECH
	void recombinate();
	void create_cards();

	Field(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file, std::string cards_texture);


};



