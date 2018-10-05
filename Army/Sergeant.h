#ifndef SERGEANT_HEADER
#define SERGEANT_HEADER

#include "soldier.h"

class Sergeant : public Soldier
{
private:
	char* description;
	Soldier* squad;
	int size;
	int capacity;

public:
	Sergeant();
	Sergeant(const char* name, short age, short level, int salary, const char* squadDescription);
	Sergeant(const Soldier& soldier, const char* squadDescription);

	Sergeant(const Sergeant& src);
	Sergeant& operator=(const Sergeant& src);
	~Sergeant();

private:
	void copy(const Sergeant&);
	void clear();

public:
	bool addSoldier(Soldier&);
	int getSquadSalary() const;
};

#endif // SERGEANT_HEADER_INCLUDED