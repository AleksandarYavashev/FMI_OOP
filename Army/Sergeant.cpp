#include "Sergeant.h"

static const unsigned short resizeValue = 8;
static const unsigned short initialCapacity = 1;

Sergeant::Sergeant() :description(nullptr), squad(nullptr), size(0), capacity(0) {
}

Sergeant::Sergeant(const char* name, short age, short level, int salary, const char*squadDescription)
	: Soldier(name, age, level, salary), capacity(initialCapacity), size(0), description(nullptr), squad(nullptr)
{
	try
	{
		description = new char[strlen(squadDescription) + 1];
		strcpy(description, squadDescription);

		squad = new Soldier[capacity];
	}
	catch (std::bad_alloc&)
	{
		Soldier::clear();
		Sergeant::clear();

		std::cout << "No memory for the creation of a new squad! \n Try something else! \n";
	}
}

Sergeant::Sergeant(const Soldier& soldier, const char* squadDescription)
	:Soldier(soldier), capacity(initialCapacity),
	size(0), description(nullptr), squad(nullptr)
{
	try
	{
		description = new char[strlen(squadDescription) + 1];
		strcpy(description, squadDescription);

		squad = new Soldier[capacity];
	}
	catch (std::bad_alloc&)
	{
		Soldier::clear();
		Sergeant::clear();

		std::cout << "No memory for the creation of a new squad! \n Try something else! \n";
	}
}

Sergeant::Sergeant(const Sergeant & src): Soldier(src), description(nullptr), squad(nullptr)
{
	try
	{
		copy(src);
	}
	catch (std::bad_alloc&)
	{
		std::cout << "Not enough memory to create new sergeant!\n";
		Soldier::clear();
		Sergeant::clear();
	}
}

Sergeant & Sergeant::operator=(const Sergeant & src)
{
	if (this != &src)
	{
		Soldier::operator=(src);
		clear();
		copy(src);
	}

	return *this;
}

Sergeant::~Sergeant()
{
	clear();
}

void Sergeant::copy(const Sergeant & src)
{
	description = new(std::nothrow) char[strlen(src.description) + 1];

	if (!description)
	{
		std::cerr << "something bad happened\n";
		throw std::bad_alloc();
	}

	strcpy(description, src.description);

	capacity = src.capacity;
	size = src.size;
	squad = new(std::nothrow) Soldier[capacity];

	if (!squad)
	{
		clear();
		std::cout << "something bad happened\n";
		throw std::bad_alloc();
	}
	
	for (size_t i = 0; i < size; ++i)
	{
		squad[i] = src.squad[i];
	}
}

void Sergeant::clear()
{
	delete[]description;
	description = nullptr;
	delete[]squad;
	squad = nullptr;
}

bool Sergeant::addSoldier(Soldier& soldier)
{
	if (this->getLevel() <= soldier.getLevel())
	{
		std::cout << "Level mismatch!\n";
		return false;
	}

	if (capacity == size)
	{
		Soldier* newSquad = new (std::nothrow) Soldier[capacity + resizeValue];
		if (!newSquad)
		{
			std::cout << "No memory for new squad members!\n";
			return false;
		}
		
		capacity += resizeValue;

		for (size_t i = 0; i < size; ++i)
		{
			newSquad[i] = squad[i];
		}

		delete[]squad;
		squad = newSquad;
		}

	squad[size++] = soldier;

	return true;
}

int Sergeant::getSquadSalary() const
{
	int sum = 0;
	for (int i = 0; i < size; ++i)
	{
		sum += squad[i].getSalary();
	}
	return sum;
}