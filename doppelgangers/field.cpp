#ifndef FIELD
#include "field.hpp"
#define FIELD
#endif // !FIELD


void Field::recombinate()
{
	indent_between_widht = width / 40;
	indent_between_height = height / 40; 

}

void Field::create_cards()
{
	
}

Field::Field(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file, std::string cards_texture)
{
}
