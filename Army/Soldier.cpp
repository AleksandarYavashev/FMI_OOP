#include "Soldier.h"

Soldier::Soldier() :name(nullptr), age(0), salary(0), level(0) {
}

Soldier::Soldier(const char* _name, short _age, short _level, int _salary) :name(nullptr), age(_age), level(_level), salary(_salary)
{
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
}

Soldier::Soldier(const Soldier & src)
{
	copy(src);
}

Soldier & Soldier::operator=(const Soldier & src)
{
	if (this != &src)
	{
		clear();
		copy(src);
	}

	return *this;
}

Soldier::~Soldier()
{
	clear();
}

void Soldier::copy(const Soldier & src)
{
	name = new(std::nothrow) char[strlen(src.name) + 1];

	strcpy(name, src.name);
	age = src.age;
	salary = src.salary;
	level = src.level;
}

void Soldier::clear()
{
	delete[] name;
	name = nullptr;
}

short Soldier::getAge() const
{
	return age;
}

short Soldier::getLevel() const
{
	return level;
}

int Soldier::getSalary() const
{
	return salary;
}

void Soldier::setName(const char* str)
{
	delete[]name;
	name = new char[strlen(str) + 1];
	strcpy(name, str);
}

void Soldier::setAge(const short num)
{
	age = num;
}

void Soldier::setLevel(const short num)
{
	level = num;
}

void Soldier::setSalary(const int num)
{
	salary = num;
}
