#ifndef POINTS_COUNTER
#include "pointsCounter.hpp"
#define POINTS_COUNTER
#endif // !POINTS_COUNTER

void PointsCounter::update()
{
	if (points > 999 || points == 0) return;

	right_cell.setTextureRect({ points % 10 * 20 + 60,0,20,35 });

	if (points < 9) return;

	middle_cell.setTextureRect({ (points / 10) % 10 * 20 + 60,0,20,35 });

	if (points < 99) return;

	left_cell.setTextureRect({ (points / 100) % 10 * 20 + 60,0,20,35 });
}

void PointsCounter::add_point()
{
	++points;
}

void PointsCounter::nullify()
{
	points = 0;
	sprite.setTextureRect({ 0,0,60,35 });
	left_cell.setTextureRect({ 0,0,20,35 });
	middle_cell.setTextureRect({ 20,0,20,35 });
	right_cell.setTextureRect({ 40,0,20,35 });

}

PointsCounter::PointsCounter(std::pair<float, float> pos, std::pair<int, int> size, std::pair<int, int> scale, std::string texture_file):
	CounterObject(pos,size,scale,texture_file)
{
	nullify();
}
