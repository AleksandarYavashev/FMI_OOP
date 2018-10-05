#include "Soldier.h"
#include "Sergeant.h"
#include <iostream>

int main() {
	

	const int size = 10;

	Soldier cloning("Ivan", 30, 1, 100);
	Soldier battalion[size];
	
	for (int i = 0; i < size; i++)
	{
		battalion[i] = cloning;
	}

	Sergeant serg("Petar", 33, 10, 1000, "TheClonings");

	for (int i = 0; i < size; ++i)
	{
		serg.addSoldier(battalion[i]);
	}

	std::cout << "Salary of squad is: " << serg.getSquadSalary() << "\n";

	return 0;
}