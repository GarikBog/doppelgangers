

#ifndef OBJECTS
#include "objects.hpp"
#define OBJECTS
#endif // !OBJECTS





class Card : public Object {
private:

	int id;
	unsigned int suit;
	bool open;



public:
	//TECH
	void open_card();
	bool is_open() const;

	Card(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file, int id, unsigned int suit);

};



