#ifndef PLOT_H_INCLUDED
#define PLOT_H_INCLUDED
#include <iostream>
#include <vector>
#include "chars.h"
#include "story.h"

///class Plot - class containing functions and variables responsible for the story
class Plot
{
public:

	///start - function containg main menu. it calls either begin or fighttest
	static void start();
private:

	///level_up - function that takes and intiger and for that many times increments chosen statistic of Hero
	static void level_up (int lev);

	///fighttest - a function that instead of story lets player set up custom fight scenarios, it calls fight with appropiate allies and enemies
	static void fighttest();

	///begin - function beggining story, it includes reading instructions and creating character, it calls first_part
	static void begin();

	///first_part - part4b - the story. these functions are mostly printing but they diverge and converge according to player choices and character stats
	///they call each other, level_up, char_check, int_check and part5
	static void first_part();
	static void part2a();
	static void part2b();
	static void part3a();
	static void part3c();
	static void part3d();
	static void part4a();
	static void part4b();

	///part5 - penultimate part of the story, it includes multiple char_checks and adding  characters to allies vector
	static void part5();

	///finale - final part of the story, it creates a Wizard and an enemies vector with that Wizard inside of it. It then calls fight with allies and enemies vector
	static void finale();

	///allies - vector used throughout the story to which allied characters are added
	static std::vector<Character*> allies;

	///l - counter indicating how many level ups is player going to get 
	static int l;
protected:

	///Hero - a variable used throughout the story ot indicate what kind of character and what statistic player character has
	static Character* Hero;
};

///class Checks - it inherits from Plot in order to be able to "see" Hero and use it inside of the functions without taking it as an argument
class Checks : public Plot
{
public:

	///int_check - function using Hero and d20::roll() to determine whether the player character has succeded or failed intelligence check
	static bool int_check();

	///char_check - function using Hero and d20::roll() to determine whether the player character has succeded or failed charisma check
	static bool char_check();
};
#endif