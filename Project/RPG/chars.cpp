
#include <iostream>
#include "chars.h"
#include<time.h>
#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>


using namespace std;

Character::Character(int h, int s, int a, int c, int m, int i, string cn)
{
	health = h;
	strength = s;
	agility = a;
	charisma = c;
	magic = m;
	smart = i;
	class_name = cn;
	hp = health * 5;
}

Character::~Character()
{

}

void Character::status()
{
	cout << " Current stats: " <<  endl <<" Name: "<<name<<endl<< " Health: " << health << endl << " Strength: " << strength << endl << " Agility: " << agility << endl << " Charisma: " << charisma << endl << " Magic: " << magic << endl << " Intelligence: " << smart << endl<<" Current hp: "<<hp<<"/"<<health*5 << endl<<endl;
}

Wizard::Wizard() :Character(20, 15, 20, 20, 20, 20, "Wizard")
{
}

std::ofstream& operator<< (std::ofstream& os, Character& Hero)
{
	os<< " Name: " << Hero.name << endl << " Class: " << Hero.class_name << endl << " Health: " << Hero.health << endl << " Strength: " << Hero.strength << endl << " Agility: " << Hero.agility << endl << " Charisma: " << Hero.charisma << endl << " Magic: " << Hero.magic << endl << " Intelligence: " << Hero.smart << endl << " Current hp: " << Hero.hp << "/" << Hero.health * 5 << endl <<" Sum: "<< (Hero.agility + Hero.charisma + Hero.health + Hero.magic + Hero.smart + Hero.strength)<<endl<<endl<<endl;
	return os;
}

void Wizard::status() 
{
	if (Wizard::name.empty())
	{
		cout << " The Wizard";
	}
	else
	{
		cout <<" "<< Wizard::name;
	}
	cout << " is so powerfull you cannot determine his statistics" << endl<<endl;
}

Wizard::~Wizard()
{
}

Knight::Knight() : Character(10, 12, 4, 5, 9, 10, "Knight")
{
}

Knight::~Knight()
{
}

Barbarian::Barbarian() : Character(15, 20, 5, 1, 3, 6, "Barbarian")
{
}

Barbarian::~Barbarian()
{
}

Bard::Bard():Character(6, 3, 7, 20, 2, 12, "Bard")
{
}

Bard::~Bard()
{
}

Sorcerer::Sorcerer() : Character(8, 5, 3, 5, 17, 12, "Sorcerer")
{
}

Sorcerer::~Sorcerer()
{
}