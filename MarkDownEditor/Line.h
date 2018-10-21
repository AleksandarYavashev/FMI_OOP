#ifndef _LINE_HEADER
#define _LINE_HEADER

#include "Word.h"

class Line
{
public:
	Line();
	Line(char* str);
	Line(const Line& src);
	Line& operator=(const Line& src);
	~Line();

	void add(const char* str, int startPos, int endPos);
	// for heading
	void add(const char* str, int startPos);

	void serialize(std::ofstream& ofs);

private:
	void resize();
	//void moveWith(int size, int pos);
	void addWord(char* str);
/*	int getPosBeforeWord(int pos);
	int getPosAfterWord(int pos);
*/
	void addBefore(const char* str, int pos);
	void addAfter(const char* str, int pos);

private:
	Word* line;
	int size;
	int capacity;
};

#endif //  _LINE_HEADER_INCLUDED

