#include "Line.h"

const int INITIAL_LINE_SIZE = 15;

Line::Line() : line(nullptr), size(0), capacity(0)
{
	//...
}

Line::Line(char * str) : line(nullptr), size(0), capacity(0)
{
	line = new Word[INITIAL_LINE_SIZE];
	capacity = INITIAL_LINE_SIZE;

	const char delimiter[3] = "\t ";

	char* token = strtok(str, delimiter);

	while (token)
	{
		addWord(token);
		token = strtok(NULL, delimiter);
	}
}

Line::Line(const Line & src) : line(nullptr)
{
	size = src.size;
	line = new (std::nothrow) Word[size];

	if (!line)
	{
		std::cout << "Failed to create a line.\n";
		size = 0;
		return;
	}

	capacity = size;

	for (int i = 0; i < size; ++i)
		line[i] = src.line[i];
}

Line & Line::operator=(const Line & src)
{
	if (this != &src)
	{
		delete[] line;

		size = src.size;
		line = new Word[size];
		
		if (!line)
		{
			std::cout << "Failed to create line.\n";
			size = 0;
			return *this;
		}

		capacity = size;

		for (int i = 0; i < size; ++i)
			line[i] = src.line[i];

	}
	
	return *this;
}

Line::~Line()
{
	delete[] line;
}

void Line::add(const char * str, int startPos, int endPos)
{
	addBefore(str, startPos);
	addAfter(str, endPos);
}

void Line::add(const char * str, int startPos)
{
	addBefore(str, startPos);
}

void Line::serialize(std::ofstream & ofs)
{
	for (int i = 0; i < size; ++i)
	{
		line[i].serialize(ofs);
		ofs << ' ';
	}
	ofs << '\n';
}

void Line::resize()
{
	Word* temp = new Word[size * 2];
	
	for (int i = 0; i < size; ++i)
		temp[i] = line[i];

	delete[] line;
	line = temp;
	capacity = size * 2;
}


void Line::addWord(char * str)
{
	if (size == capacity)
		resize();

	Word myWord(str);

	line[size] = myWord;
	++size;
}


/*
void Line::moveWith(int size, int pos)
{
	for (int i = length; i >= pos + size; --i)
	{
		line[i] = line[i - size];
	}
}


int Line::getPosBeforeWord(int pos)
{
	int i = 0;
	int count = 1;


	// skip whitespaces
	while ((line[i] == ' ') || (line[i] = '\t'))
		++i;
	std::cout << "Whitespaces skipped: " << i << '\n';

	while (i <= length && count != pos)
	{
		if ((line[i] == ' ') || (line[i] = '\t'))
		{
			++count;
		}
		++i;
	}

	return i;
}

int Line::getPosAfterWord(int pos)
{
	int i = getPosBeforeWord(pos);

	while (line[i] != ' ' && line[i] != '\t' && i < length)
		++i;

	return i;
}

*/
void Line::addBefore(const char * str, int pos)
{
	line[pos - 1].addBefore(str);
}

void Line::addAfter(const char * str, int pos)
{
	line[pos - 1].addAfter(str);
}