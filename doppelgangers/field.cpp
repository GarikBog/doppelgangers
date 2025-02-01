#ifndef FIELD
#include "field.hpp"
#define FIELD
#endif // !FIELD

#ifndef IOSTREAM
#include<iostream>
#define IOSTREAM
#endif // !IOSTREAM

#ifndef CTIME
#include<ctime>
#define CTIME
#endif // !CTIME



void Field::recombinate()
{
	srand(time(0));
	int repeate = rand() % 200 + 1, rnd_card_f, rnd_card_s;
	for (int i = 0; i < repeate; ++i) {
		rnd_card_f = rand() % cards.size();
		rnd_card_s = rand() % cards.size();
		cards[rnd_card_f]->swap_suit(cards[rnd_card_s]);
		std::cout << "\nSWAP :" << rnd_card_f << " AND " << rnd_card_s;
	}

}

void Field::create_cards()
{
	card_width = (width - width / 8 - width * 5 / 33) / 6;
	indent_width = (width - card_width * 6)/4;
	indent_between_width = (width - card_width * 6) / 12;
	std::cout << "CARD_WIDTH: " << card_width << "\nINDENT_WIDTH: " << indent_width << "\nINDENT_BETWEEN_WIDHT: " << indent_between_width;

	card_height = (height - height * 3 / 83 - height / 8) / 4;
	indent_height = (height - card_height * 4) / 3;
	indent_between_height = (height - card_height*4 - indent_height*2) / 3;
	std::cout << "\n\nCARD_HEIGHT: " << card_height << "\nINDENT_HEIGHT: " << indent_height << "\nINDENT_BETWEEN_HEIGHT: " << indent_between_height;



	for (int i = 0; i < 6; ++i)
		for(int j = 0;j<4;++j){
			Card* tmp_card = new Card(
				{ (x + indent_width + (card_width + indent_between_width) * i),(y + indent_height + (card_height + indent_between_height )*j )},
				{100,175},
				{card_width,card_height},
				cards_textures,
				(1  + 6 * j + i)%12);
			std::cout << "\nPOS: " << (1 + j *i);
			cards.push_back(tmp_card);
		}
	
}

void Field::draw(sf::RenderWindow& window)
{
	Object::draw(window);
	for (Card* card : cards) {
		card->draw(window);
	}
}

void Field::open_all()
{
	for (Card* card : cards) {
		card->open_card();
	}
}

void Field::close_all()
{
	for (Card* card : cards) {
		card->close();
	}
}

Field::Field(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file, std::string cards_textures) :
	Object(pos, size, scale, texture_file),
	cards_textures(cards_textures)
{
	create_cards();
	recombinate();
}
