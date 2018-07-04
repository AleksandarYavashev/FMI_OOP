#ifndef MARKER_INCLUDED
#define MARKER_INCLUDED
#include "WritingInstrument.h"


class Marker: public WritingInstrument
{
private:
	char* colour;
	

public:
	Marker();
	Marker(const char* _colour, const char* _brand, unsigned int _year);
	~Marker();

	void init(const char* _colour, const char* _brand, unsigned int _year);
	void setColour(const char* str);
	const char* getColour() const;

public:
	friend std::ostream& operator<<(std::ostream& ofs, const Marker& obj);
	friend std::istream& operator>>(std::istream& ifs, Marker& obj);

};
#endif // !MARKER_INCLUDED

