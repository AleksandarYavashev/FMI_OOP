#include "CmdHandler.h"

const int LINE_MAX_SIZE = 1024;

CmdHandler::CmdHandler(char * str) : exitIf(false)
{
	filePath = new char[strlen(str) + 1];
	strcpy(filePath, str);
}

void CmdHandler::run()
{
	char arg[128];

	init();

	while (std::cin >> arg)
	{
		callCommand(arg);

		if (exitIf)
			return;
	}
}

void CmdHandler::makeHeading()
{
	int lineNumber = 0;
	std::cin >> lineNumber;

	text.makeHeading(lineNumber);
}

void CmdHandler::makeItalic()
{
	int lineNumber, from, to;
	std::cin >> lineNumber >> from >> to;

	text.makeItalic(lineNumber, from, to);
}

void CmdHandler::makeBold()
{
	int lineNumber, from, to;
	std::cin >> lineNumber >> from >> to;

	text.makeBold(lineNumber, from, to);
}

void CmdHandler::makeCombine()
{
	int lineNumber, from, to;
	std::cin >> lineNumber >> from >> to;

	text.makeCombine(lineNumber, from, to);
}

void CmdHandler::addLine()
{
	char line[LINE_MAX_SIZE];
	std::cin.getline(line, LINE_MAX_SIZE);

	Line myLine(line);
	text.addLine(myLine);
}

void CmdHandler::remove()
{
	int lineNumber = 0;
	std::cin >> lineNumber;

	text.removeLine(lineNumber);
}

void CmdHandler::exit()
{
	int length = strlen(filePath);

	filePath[length - 3] = 'm';
	filePath[length - 2] = 'd';
	filePath[length - 1] = '\0';

	std::ofstream ofs(filePath, std::ios::out);
	if (!ofs.is_open())
	{
		std::cout << "Cannot write to file.\n";
		return;
	}
	else
	{
		text.serialize(ofs);
	}
	exitIf = true;

	ofs.close();
}

void CmdHandler::init()
{
	std::ifstream ifs(filePath, std::ios::in || std::ios::beg);
	if (!ifs.is_open())
	{
		std::cout << "Could not open file for reading.\n";
		return;
	}

	Text temp(ifs);
	text = temp;

	ifs.close();
}