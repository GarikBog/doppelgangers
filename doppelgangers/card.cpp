

#ifndef CARD
#include"card.hpp"
#define CARD
#endif // !CARD



void Card::open_card()
{
	open = !open;
}

bool Card::is_open() const
{
	return open;
}



Card::Card(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file, int id, unsigned int suit) :
	Object(pos, size, scale, texture_file),
	id(id),
	suit(suit),
	open(false)
{
}
