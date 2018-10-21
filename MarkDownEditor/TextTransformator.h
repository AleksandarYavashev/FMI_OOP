#ifndef _TEXT_TRANSFORMATOR_HEADER
#define _TEXT_TRANSFORMATOR_HEADER

#include "Line.h"

class Text
{
public:
	Text();
	Text(std::ifstream& ifs);
	Text(const Text& src);
	Text& operator=(const Text& src);
	~Text();

public:
	void makeHeading(int lineNumber);
	void makeItalic(int lineNumber, int from, int to);
	void makeBold(int lineNumber, int from, int to);
	void makeCombine(int lineNumber, int from, int to);
	void addLine(Line& line);
	void addLine(char* str);
	void removeLine(int lineNumber);
	void serialize(std::ofstream& ofs);

private:
	void resize();

private:
	Line* lines;
	int size;
	int capacity;
};



#endif // _TEXT_TRANSFORMATOR_HEADER_INCLUDED