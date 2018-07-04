#include "Marker.h"

Marker::Marker() :WritingInstrument()
{
	colour = nullptr;
}

Marker::Marker(const char * _colour, const char * _brand, unsigned int _year):WritingInstrument(_brand, _year)
{
	colour = new (std::nothrow) char[strlen(_colour) + 1];
	if (!colour)
	{
		std::cout << "Failed to allocate memory for colour.\n";
		return;
	}
	strcpy(colour, _colour);
}

Marker::~Marker()
{
	delete[] colour;
	colour = nullptr;
}

void Marker::init(const char * _colour, const char * _brand, unsigned int _year)
{
	delete[] colour;
	colour = new (std::nothrow) char[strlen(_colour) + 1];
	if (!colour)
	{
		std::cout << "Failed to allocate memory for colour.\n";
		return;
	}
	strcpy(colour, _colour);

	setBrand(_brand);
	setYear(_year);
}

void Marker::setColour(const char * str)
{
	delete[]colour;
	colour = new char[strlen(str) + 1];
	strcpy(colour, str);
}


const char * Marker::getColour() const
{
	return colour;
}

std::ostream & operator<<(std::ostream & ofs, const Marker & obj)
{
	ofs << "Colour: " << obj.colour << '\n';
	ofs << "Brand: " << obj.getBrand() << '\n';
	ofs << "Year: " << obj.getYear() << '\n';
	ofs << '\n';

	return ofs;
}

std::istream & operator>>(std::istream & ifs, Marker & obj)
{
	char buffer[128];
	std::cout << "enter value of objects: \n";
	ifs >> buffer;
	delete[] obj.colour;
	obj.colour = new char[strlen(buffer) + 1];
	strcpy(obj.colour, buffer);

	ifs >> (WritingInstrument)obj;
	return ifs;
}
