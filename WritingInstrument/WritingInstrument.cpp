#include "WritingInstrument.h"

void WritingInstrument::clear()
{
	delete[] brand;
	brand = nullptr;
}

void WritingInstrument::copy(const WritingInstrument & src)
{
	brand = new char[strlen(src.brand) + 1];
	strcpy(brand, src.brand);
	year = src.year;
}

WritingInstrument::WritingInstrument()
{
	brand = nullptr;
	year = 0;
}

WritingInstrument::WritingInstrument(const char * str = nullptr, unsigned int num = 0)
{
	if (str)
	{
		brand = new (std::nothrow) char[strlen(str) + 1];
		if (!brand)
		{
			std::cout << "Failed to allocate memory for brand.\n";
			return;
		}
		strcpy(brand, str);
	}

	year = num;
}

WritingInstrument::~WritingInstrument()
{
	clear();
}

WritingInstrument::WritingInstrument(const WritingInstrument &src)
{
	copy(src);
}

WritingInstrument & WritingInstrument::operator=(const WritingInstrument &src)
{
	if (this != &src)
	{
		clear();
		copy(src);
	}

	return *this;
}

const char * WritingInstrument::getBrand() const
{
	return brand;
}

unsigned int WritingInstrument::getYear() const
{
	return year;
}

void WritingInstrument::setBrand(const char * str)
{
	delete[] brand;
	brand = new (std::nothrow) char[strlen(str) + 1];
	if (!brand)
	{
		std::cout << "Failed to allocate memory for brand.\n";
		return;
	}
	strcpy(brand, str);
}

void WritingInstrument::setYear(unsigned int num)
{
	year = num;
}

std::ostream & operator<<(std::ostream & ofs, const WritingInstrument & obj)
{
	if (obj.brand == nullptr)
	{
		ofs << "Object not initialized.\n";
		ofs << '\n';
		return ofs;
	}
	ofs << "Brand: " << obj.brand << '\n';
	ofs << "Year: " << obj.year << '\n';
	ofs << '\n';

	return ofs;
}

std::istream & operator>>(std::istream & ifs, WritingInstrument & obj)
{
	char buffer[128];
	int tempYear;
	std::cout << "Enter name: ";
	ifs >> buffer;
	std::cout << "Enter year: ";
	ifs >> tempYear;
	delete[] obj.brand;
	obj.brand = new char[strlen(buffer) + 1];
	strcpy(obj.brand, buffer);
	obj.year = tempYear;

	return ifs;
}
