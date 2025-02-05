#ifndef DOPPELGANGERS
#include "doppengangers.hpp"
#define DOPPELGANGERS
#endif // !DOPPELGANGERS


Doppelgagners::Doppelgagners(unsigned int height)
{
	window_height = height;
	window_width = window_height / 1.24;

	point_counter = new PointsCounter({ 0,0 }, { 60,35 }, { window_width * 3 / 5 ,window_width / 5 }, "counters/defolt.png");
	background = new Object({0,0},{1025,825},{window_width,window_height},"background/defolt.png");

}
