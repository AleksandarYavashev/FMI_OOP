#include <iostream>

#include "WritingInstrument.h"
#include "Marker.h";

int main()
{
	WritingInstrument wr;
	std::cout << wr;

	WritingInstrument wr1("nike", 1996);
	std::cout << wr1;

	Marker mrk("yellow", "addidas", 1997);
	std::cout << mrk;

	Marker mrk1;
	std::cin >> mrk1;
	/*mrk1.setBrand("puma");
	mrk1.setColour("green");
	mrk1.setYear(1995);*/
	std::cout << mrk1;

	return 0;
}