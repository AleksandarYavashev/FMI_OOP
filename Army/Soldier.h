#ifndef SOLDIER_HEADER
#define SOLDIER_HEADER

#include <cstring>
#include <iostream>
class Soldier
{
private:
	char* name;
	short age;
	short level;
	int salary;

public:
	Soldier();
	Soldier(const char* _name, short _age, short _level, int _salary);
	Soldier(const Soldier& src);
	Soldier& operator=(const Soldier& src);
	~Soldier();

public:
	void clear();
	void copy(const Soldier& src);

	short getAge() const;
	short getLevel() const;
	int getSalary() const;

	void setName(const char* str);
	void setAge(const short num);
	void setLevel(const short num);
	void setSalary(const int num);
};

#endif // SOLDIER_HEADER_INCLUDED