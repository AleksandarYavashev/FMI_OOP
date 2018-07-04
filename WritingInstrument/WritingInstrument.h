#ifndef WRITINGINSTRUMENT_INCLUDED
#define WRITINGINSTRUMENT_INCLUDED

#include <iostream>
#include <fstream>
#include <cstring>

class WritingInstrument
{
private:
	char* brand;
	unsigned int year;

private:
	void clear();
	void copy(const WritingInstrument&);

public:
	WritingInstrument();
	WritingInstrument(const char* str, unsigned int num);
	~WritingInstrument();
	WritingInstrument(const WritingInstrument&);
	WritingInstrument& operator=(const WritingInstrument&);

public:
	const char* getBrand() const;
	unsigned int getYear() const;

	void setBrand(const char* str);
	void setYear(unsigned int num);

	friend std::ostream& operator<<(std::ostream& ofs, const WritingInstrument& obj);
	friend std::istream& operator>>(std::istream& ifs, WritingInstrument& obj);
};
#endif // !WRITINGINSTRUMENT_INCLUDED

