#ifndef STORY_H_INCLUDED
#define STORY_H_INCLUDED

#include <iostream>
#include <vector>
#include "chars.h"
#include<time.h>

///class d20 - class containing a single function that simulates a 20-sided dice rolls
class d20
{
public:
	d20() = default;
	static int roll();
};

///class fighting - class containing various function responsible for my fighting system
class fighting
{
protected:
	///dodge - dodging attacks. this function compares the attacker's and defender's agility summed with d20's rolls and returns whether the defender managed to evade the attack or not
	static bool dodge(Character& attacker, Character& defender);
	
	///attack - attacking. this function compares defender's and attacker's agility and strength summed with d20 rolls and returns whether the attacker managed to hit the defender
	static bool attack(Character& attacker, Character& defender);
	
	///block - blocking attacks. this function compares the attacker's and defender's strength summed with d20's rolls and returns whether the defender managed to block the attack or not
	static bool defend(Character& attacker, Character& defender);
	
	///heal - healing function that checks a character's magic stat and a d20 roll and adds appropiate amount of hp to a chosen character
	static void heal(Character& healer, std::vector<Character*>& allies);
	
	///enemies - a function responsible for enemies' turn in combat. it gives the player a choice and calls defend and/or dodge 
	static void enemies(std::vector<Character*>& allies, std::vector<Character*>& enemies);
	
	///allies - a function responsible for allies' turn in combat. it gives the player a choice and calls attack and/or heal 
	static void allies(std::vector<Character*>& allies, std::vector<Character*>& enemies);

public:	
	///fight - main function responsible for the fighting system. it calls 'allies' and 'enemies' until one sides either the Hero (first ally in the allies vector)'s hp is 0 or there are no more enemies in their vector
	static void fight(std::vector<Character*>& allies, std::vector<Character*>& enemies);
};
#endif