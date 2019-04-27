#ifndef COMBATANT_H
#define COMBATANT_H

#include <string>

//****************************************************************************************************

struct Combatant
{
	int roll;
	string name;

	Combatant();

	friend ostream & operator << (ostream & out, const Combatant & data);
	bool operator > (const Combatant & rhs) const;
};

//****************************************************************************************************

Combatant::Combatant()
{
	roll = 0;
	name = "no name";
}

//****************************************************************************************************

ostream & operator << (ostream & out, const Combatant & rhs)
{
	out << rhs.name << ": " << rhs.roll << endl;
	return out;
}

//****************************************************************************************************

bool Combatant::operator > (const Combatant & rhs) const
{
	return (this->roll > rhs.roll);
}

//****************************************************************************************************

#endif COMBATANT_H