#include "Word.h"

Word::Word(): word(nullptr), length(0)
{
	//...
}

Word::Word(char * str)
{
	length = strlen(str);

	word = new (std::nothrow) char[length + 1];
	if (!word)
	{
		std::cout << "Failed to allocate memory for word. (char* ctr)\n";
		length = 0;
		word = nullptr;
		return;
	}

	strcpy(word, str);
}

Word::Word(const Word & src)
{
	word = new (std::nothrow) char[src.length + 1];
	if (!word)
	{
		std::cout << "Failed to allocate memory for word.\n";
		return;
	}
	
	strcpy(word, src.word);
	length = src.length;
}

Word & Word::operator=(const Word & src)
{
	if (this != &src)
	{
		delete[] word;

		word = new (std::nothrow) char[src.length + 1];
		if (!word)
		{
			std::cout << "Failed to allocate memory for word. (OP =)\n";
			return *this;
		}

		strcpy(word, src.word);
		length = src.length;
	}

	return *this;
}

Word::~Word()
{
	delete[] word;
}

void Word::serialize(std::ofstream & ofs)
{
	ofs << word;
}

void Word::addBefore(const char * str)
{
	int strLength = strlen(str);
	char* tempStr = new (std::nothrow) char[strLength + length + 1];
	if (!tempStr)
	{
		std::cout << "Failed to allocate memory. (addB / word)\n";
		return;
	}


	for (int i = 0; i < strLength; ++i)
	{
		tempStr[i] = str[i];
	}

	int j = strLength;
	for (int i = 0; i < length; ++i)
	{
		tempStr[j] = word[i];
		++j;
	}

	length = length + strLength;
	tempStr[length] = '\0';

	delete[] word;
	word = tempStr;
}

void Word::addAfter(const char * str)
{
	int strLength = strlen(str);
	char* tempStr = new (std::nothrow) char[strLength + length + 1];
	if (!tempStr)
	{
		std::cout << "Failed to allocate memory. (addB / word)\n";
		return;
	}

	for (int i = 0; i < length; ++i)
	{
		tempStr[i] = word[i];
	}

	int j = length;
	for (int i = 0; i < strLength; ++i)
	{
		tempStr[j] = str[i];
		++j;
	}

	length = strLength + length;
	tempStr[length] = '\0';

	delete[] word;
	word = tempStr;
}
