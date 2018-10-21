#include "TextTransformator.h"

const int STR_SIZE = 1024;
const int INIT_SIZE = 10;

Text::Text() : lines(nullptr), size(0), capacity(0)
{
	// ...
}

Text::Text(std::ifstream& ifs) : lines(nullptr), size(0), capacity(0)
{
	lines = new (std::nothrow) Line[INIT_SIZE];
	if (!lines)
	{
		std::cout << "Failed to aquire memory for initializing lines.\n";
		return;
	}
	capacity = INIT_SIZE;

	char tempString[STR_SIZE];
	while (ifs)
	{
		ifs.getline(tempString, STR_SIZE);
		//Line myLine(tempString);
		addLine(tempString);
	}
}

Text::Text(const Text & src)
{
	lines = new Line[src.size];
	for (int i = 0; i < src.size; ++i)
	{
		lines[i] = src.lines[i];
	}

	size = src.size;
	capacity = src.capacity;
}

Text & Text::operator=(const Text & src)
{
	if (this != &src)
	{
		delete[] lines;

		lines = new (std::nothrow) Line[src.size];
		if (!lines)
		{
			std::cout << "Memory allocation problem. (TT operator=)\n";
			return *this;
		}

		for (int i = 0; i < src.size; ++i)
		{
			lines[i] = src.lines[i];
		}

		size = src.size;
		capacity = src.capacity;
	}

	return *this;
}

Text::~Text()
{
	delete[] lines;
}

void Text::makeHeading(int lineNumber)
{
	lines[lineNumber - 1].add("#", 1);
}

void Text::makeItalic(int lineNumber, int from, int to)
{
	lines[lineNumber - 1].add("*", from, to);
}

void Text::makeBold(int lineNumber, int from, int to)
{
	lines[lineNumber - 1].add("**", from, to);
}

void Text::makeCombine(int lineNumber, int from, int to)
{
	lines[lineNumber - 1].add("***", from, to);
}

void Text::addLine(Line& line)
{
	if (size == capacity)
		resize();

	lines[size] = line;
	++size;
}

void Text::addLine(char* str)
{
	if (size == capacity)
		resize();

	Line myLine(str);

	lines[size] = myLine;
	++size;
}

void Text::removeLine(int lineNumber)
{
	while (lineNumber < size)
	{
		lines[lineNumber - 1] = lines[lineNumber];
		++lineNumber;
	}

	//delete &lines[size];
	--size;
}

void Text::serialize(std::ofstream & ofs)
{
	for (int i = 0; i < size; ++i)
	{
		lines[i].serialize(ofs);
	}
}

void Text::resize()
{
	Line* temp = new Line[size * 2 + 1];
	for (int i = 0; i < size; ++i)
	{
		temp[i] = lines[i];
	}

	delete[] lines;
	lines = temp;
	capacity = size * 2 + 1;
}