

#ifndef OBJECTS
#include "objects.hpp"
#define OBJECTS
#endif // !OBJECTS





class Card : public Object {
private:


	int suit;
	bool open;



public:
	//SETTERS
	void set_suit(int suit);

	//GETTES
	int get_suit() const;

	//TECH
	void open_card();
	void close();
	bool is_open() const;
	void swap_suit(Card* card);


	Card(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file, unsigned int suit);

};



