
#include "CmdHandler.h"

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Need to provide a file path.\n";
		//return 1;
	}

	char str[128] = "C:\\Users\\Acer\\Desktop\\text.txt";

	CmdHandler cmdHandler(str);

	cmdHandler.run();

	system("pause");
	return 0;
}