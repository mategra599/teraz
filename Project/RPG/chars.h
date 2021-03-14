#ifndef CHARS_H_INCLUDED
#define CHARS_H_INCLUDED

#include <iostream>
#include <vector>
#include<time.h>
#include <fstream>
using namespace std;

///class Character - it stores information about different character statistics as well as its constructor, function status and a << operator overload
class Character
{
public:
	Character()=default;
	
	///Character constructor - it takes several numerical values as well as string cn which contains "character class" name and asignes them to stats and string class_name 
	///see chars.cpp
	Character(int h, int s, int a, int c, int m, int i, string cn);

	///name - a character's name, assigned after construction
	string name;

	///class_name - a variable which stores the name of "character class" assigned during construction
	string class_name;

	///health - a statistic responsible for character's max hp
	int health;

	///strength - a statistic used during fighting
	int strength;

	///agility - a statistic used during fighting
	int agility;

	///charisma - a statistic used in story to determine whether player can convince other characters to do or say something
	///see Checks::char_check() in plot.h and plot.cpp
	int charisma;

	///magic - a statistic used in fighting to determine the amount of hp a character can heal
	int magic;

	///smart - also elsewhere called intelligence - a statistic used in story to determine whether player knows or can deduce something
	///see Checks::int_check() in plot.h and plot.cpp
	int smart;

	///hp - statistic indicating current health points of a character
	int hp;

	///status - function that prints current statistics and name of a character
	virtual void status();

	///<< operator overload. when used with an ofstream it prints all data about character to the file
	friend std::ofstream & operator<< (std::ofstream & os, Character & hero);
	virtual ~Character();

};

///class Wizard - one of "character classes". he is the most overpowered character as he is the main boss of the game
class Wizard : public Character
{
public:
	Wizard();
	~Wizard();

	///status override - when status is called on Wizard it doesn't print its data but instead prints a custom message
	virtual void status() override;
};

///class Knight - one of "character classes"
class Knight :public Character
{
public:
	Knight();
	~Knight();
};

///class Barbarian - one of "character classes"
class Barbarian :public Character
{
public:
	Barbarian();
	~Barbarian();
};

///class Bard - one of "character classes"
class Bard :public Character
{
public:
	Bard();
	~Bard();
};

///class Sorcerer - one of "character classes"
class Sorcerer : public Character
{
public:
	Sorcerer();
	~Sorcerer();
};
#endif