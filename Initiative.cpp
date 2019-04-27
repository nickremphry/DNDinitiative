#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#include "Combatant.h"

//****************************************************************************************************

int getNumCombatants();
void fillVector(vector<Combatant> & init, int numOfPlayers);
void sortVector(vector<Combatant> & init);
void display(vector<Combatant> & init);

//****************************************************************************************************

int main()
{
	int numOfCombatants;
	vector<Combatant> init;

	numOfCombatants = getNumCombatants();
	fillVector(init, numOfCombatants);
	sortVector(init);
	display(init);

}

//****************************************************************************************************

int getNumCombatants()
{
	int combatants;

	do
	{
		cout << "Please enter the number of combatants: ";
		cin >> combatants;

		if (combatants < 0)
		{
			cout << "Cannot have a negative number of combatants! Try again!" << endl;
		}
		else if (combatants == 0)
		{
			cout << "There cannot be 0 people in combat! Try again!" << endl;
		}
		else if (combatants == 1)
		{
			cout << "There must be more than one person for there to be combat! Try again!" << endl;
		}
	} 
	while (combatants <= 1);

	return combatants;
}

//****************************************************************************************************

void fillVector(vector<Combatant> & init, int numOfPlayers)
{
	Combatant combatant;

	for (int i = 0; i < numOfPlayers; i++)
	{
		cin.ignore();
		cout << "What is combatant " << i + 1 << "'s name: ";
		getline(cin, combatant.name);
		cout << "What is combatant " << i + 1 << "'s roll: ";
		cin >> combatant.roll;

		init.push_back(combatant);
	}
}

//****************************************************************************************************

void sortVector(vector<Combatant> & init)
{
	cout << "\nSorting List... ";

	int size = static_cast<int>(init.size());
	
	for (int i = 1; i < size; i++)
	{
		for (int r = size - 1; r > 0; r--)
		{
			if (init.at(r) > init.at(r - 1))
			{
				swap(init.at(r), init.at(r - 1));
			}
		}
	}

	cout << "List Sorted!" << endl;
	
}

//****************************************************************************************************

void display(vector<Combatant> & init)
{
	cout << "\nHere is the order of initiation: \n" << endl;

	for (int i = 0; i < init.size(); i++)
	{
		cout << init.at(i);
	}
}