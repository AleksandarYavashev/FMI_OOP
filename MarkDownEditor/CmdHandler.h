#ifndef _CMDHANDLER_HEADER
#define _CMDHANDLER_HEADER

#include <iostream>
#include <fstream>
#include "TextTransformator.h"

class CmdHandler
{
public:
	CmdHandler(char* str);
	void run();

private:
	Text text;
	char* filePath;
	bool exitIf;

private:
	void makeHeading();
	void makeItalic();
	void makeBold();
	void makeCombine();
	void addLine();
	void remove();
	void exit();
	void init();

private:
	void callCommand(const char* command)
	{
		if (strcmp(command, "makeHeading") == 0)
		{
			makeHeading();
		}
		else if (strcmp(command, "makeItalic") == 0)
		{
			makeItalic();
		}
		else if (strcmp(command, "makeBold") == 0)
		{
			makeBold();
		}
		else if (strcmp(command, "makeCombine") == 0)
		{
			makeCombine();
		}
		else if (strcmp(command, "addLine") == 0)
		{
			addLine();
		}
		else if (strcmp(command, "remove") == 0)
		{
			remove();
		}
		else if (strcmp(command, "exit") == 0)
		{
			exit();
		}
		else
		{
			std::cout << "Wrong command input.\n";
		}
	}

};

#endif //_CMDHANDLER_HEADER_INCLUDED
