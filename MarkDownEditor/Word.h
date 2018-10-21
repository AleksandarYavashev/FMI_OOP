#ifndef _WORD_HEADER
#define _WORD_HEADER

#include <iostream>
#include <fstream>

class Word
{
public:
	Word();
	Word(char* str);
	Word(const Word& src);
	Word& operator= (const Word& src);
	~Word();

public:
	void serialize(std::ofstream& ofs);

	void addBefore(const char* str);
	void addAfter(const char* str);

private:
	char* word;
	int length;
};

#endif // _WORD_HEADER_INCLUDED