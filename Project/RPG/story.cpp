#include <iostream>
#include <vector>
#include "chars.h"
#include "story.h"
#include "plot.h"
#include<time.h>
#include <Windows.h>
#include <stdlib.h>
using std::cout;
using std::endl;

int d20::roll()
{
	int dice = rand() % 20 + 1;
	return dice;
}

bool fighting::dodge(Character& attacker, Character& defender)
{
	auto r = d20::roll();
	auto q = d20::roll();

	if (r == 1)
	{
		system("CLS");
		cout << " You rolled a natural 1. There is no recovery from this." << endl << " You are hit by  "<<attacker.name<<" as you try to duck beneath his attack" << endl<<" You lost "<< int(attacker.strength * 0.5)<<" hp"<<endl;
		defender.hp = defender.hp - int(attacker.strength*0.5);
		return false;
	}
	else if (r == 20)
	{
		system("CLS");
		cout << " You rolled a natural 20. You lucky bastard."<<endl<<" You manage to duck perfectly and sneak a quick extra attack." << endl << " You hit " << attacker.name << " for " << int(defender.strength / 2) << endl;
		attacker.hp = attacker.hp - int(defender.strength / 2);
		return true;
	}
	else if ((defender.agility + r)  >= (attacker.agility+q))
	{
		system("CLS");
		cout << " You managed to evade " << attacker.name << "'s attack right as it was going to hit you" << endl;
		return true;
	}
	else
	{
		system("CLS");
		cout << " Unfortunately you didn't manage to succesfully dodge the incoming attack and it hit you. "<< endl;
		return false;
	}
}

bool fighting::attack(Character& attacker, Character& defender)
{
	auto r = d20::roll();
	auto q = d20::roll();
	if (r == 1)
	{
		system("CLS");
		cout << " You rolled a nat 1."<<endl<<" You slipped while attacking and hit yourself" << endl<<" You lost "<< int(attacker.strength / 2)<<" hp"<<endl;
		attacker.hp = attacker.hp - int(attacker.strength / 2);
		return 0;
	}
	else if (r == 20)
	{
		system("CLS");
		cout << " You manage to hit " << defender.name << " with such strength and precision you delt extra " << attacker.strength << " damage" << endl;
		defender.hp = defender.hp - attacker.strength;
		return 1;
	}
	else if ((defender.strength + q) > (attacker.strength + r))
	{
		system("CLS");
		cout << " Unfortunately " << defender.name << " managed to block your attack" << endl;
		return 0;
	}
	else if ((defender.agility + q) > (attacker.agility + r))
	{
		system("CLS");
		cout << " It seems " << defender.name << " is so agile and quick he managed to just dodge your attack" << endl;
		return 0;
	}
	else
	{
		system("CLS");
		cout << " You manage to hit your opponent" << endl;
		return 1;
	}

}

bool fighting::defend(Character& attacker, Character& defender)
{
	auto r = d20::roll();
	auto q = d20::roll();
	if (r == 1)
	{
		system("CLS");
		cout << " You rolled a nat 1" << endl <<" "<< attacker.name << " managed to use the weapon you were defending with against you. You lose " << int(attacker.strength / 2 + defender.strength / 2) <<" hp"<< endl;
		defender.hp = defender.hp - int(attacker.strength / 2 + defender.strength / 2);
		return 0;
	}
	else if (r == 20)
	{
		system("CLS");
		cout << " You rolled a nat 20" << endl << " You managed to perform a counterstrike while defending" << endl<<" You deal extra "<< int(defender.strength / 2)<<" damage"<<endl;
		attacker.hp =attacker.hp- int(defender.strength / 2);
		return 1;
	}
	else if ((defender.strength + r) >= (attacker.strength + q))
	{
		system("CLS");
		cout << " You blocked " << attacker.name << "'s attack" << endl;
		return 1;
	}
	else
	{
		system("CLS");
		cout <<" "<< attacker.name << " bypassed your block and just hit you" << endl;
		return 0;
	}
}

void fighting::heal(Character& healer, std::vector<Character*>& allies)
{
	auto r = d20::roll();
	cout << " Whom do you want to heal?" << endl;
	for (int i = 0; i < int(size(allies)); i++)
	{
		cout <<" ["<< i + 1 << "] " << allies[i]->name <<" hp: "<<allies[i]->hp<<"/"<<allies[i]->health*5<< endl;
	}
	int q = 0;
	cout<<" "; 
	while (!(cin >> q))
	{
		cout << "\n Please enter a number\n \n";
		cin.clear();
		cin.ignore();
	}
	q = q - 1;
	if (r == 1)
	{
		system("CLS");
		cout << " You got a nat 1. You ain't doing any healing with that" << endl;
	}
	else if (r == 20)
	{
		system("CLS");
		cout << " You got nat 20, you restore " << allies[q]->name << " to full health\n";
		allies[q]->hp = allies[q]->health * 5;
	}
	else
	{
		system("CLS");
		cout << " You gave " << allies[q]->name <<" "<< healer.magic + r / 2 << " hp" << endl;
		allies[q]->hp = allies[q]->hp + healer.magic + r / 2;
		if (allies[q]->hp > (allies[q]->health * 5))
		{
			allies[q]->hp = allies[q]->health * 5;
		}
	}
}

void fighting::allies(std::vector<Character*>& allies, std::vector<Character*>& enemies)
{
	std::vector<bool> vec;
	for (int i = 0; i < int(size(allies)); i++)
	{
		vec.push_back(1);
	}
	bool check=1;
	while (check)
	{
		auto r = d20::roll();
		cout << " Allies: " << endl;
		for (int i = 0; i < int(size(allies)); i++)
		{
			cout <<" ["<< i + 1 << "] ";
			allies[i]->status();
			if (allies[i]->hp == 0)
			{
				vec[i] = 0;
			}
		}
		cout<<endl << " Enemies: " << endl;
		for (int i = 0; i < int(size(enemies)); i++)
		{
			cout <<" ["<< i + 1 << "] ";
			enemies[i]->status();
		}
		cout << " What do you want to do?" << endl << " [1] Attack (strength and agility)" << endl << " [2] Heal (magic)" << endl;
		int s = 0;
		do
		{
			cout<<" "; 
			while (!(cin >> s))
			{
				cout << "\n Please enter a number \n \n";
				cin.clear();
				cin.ignore();
			}
			if (s != 1 && s != 2)
			{
				cout << endl << " Choose one of the two options" << endl;
			}
		} while (s != 1 && s != 2);
		switch (s)
		{
		case 1:
		{
			cout << " Choose which enemy to attack" << endl;
			int l = 0;
			do
			{
				cout<<" "; 
				while (!(cin >> l))
				{
					cout << "\n Please enter a number\n \n";
					cin.clear();
					cin.ignore();
				}
				if (l > int(size(enemies)) || l < 1)
				{
					cout << endl << " Choose one of the numbers written next to the enemy you want to attack"<<endl;
				}
			} while (l > int(size(enemies)) || l < 1);
			l = l - 1;
			cout << endl << " Which ally do you want to attack with?" << endl;
			int a = 0;
			
			do
			{
				do
				{
					cout<<" "; 
					while (!(cin >> a))
					{
						cout << "\n Please enter a number\n \n";
						cin.clear();
						cin.ignore();
					}
					if (a > int(size(allies)) || a < 1)
					{
						cout << endl << " Choose one of the numbers written next to the ally you want to use" << endl;
					}
				} while (a > int(size(allies)) || a < 1);
				a = a - 1;
				if (vec[a] == 0)
				{
					cout << endl << " You've already used this ally during this fight or he's knocked out" << endl;
				}
			} while (vec[a] == 0);
			vec[a] = 0;
			auto at = attack(*allies[a], *enemies[l]);
			if (at)
			{
				enemies[l]->hp = enemies[l]->hp - (allies[a]->strength + r / 2);
				if (enemies[l]->hp <= 0)
				{
					std::vector<Character*>::iterator it = enemies.begin();
					it += l;
					cout <<" "<< enemies[l]->name << " dies" << endl;
					delete enemies[l];
					enemies.erase(it);
				}
			}
		}
		break;
			case 2:
			{
				cout << endl << " Which ally do you want to heal with?" << endl;
				int a = 0;
				do
				{
					do
					{
						cout<<" "; 
						while (!(cin >> a))
						{
							cout << "\n Please enter a number\n \n";
							cin.clear();
							cin.ignore();
						}
						if (a > int(size(allies)) || a < 1)
						{
							cout << endl << " Choose one of the numbers written next to the ally you want to use" << endl;
						}
					} while (a > int(size(allies)) || a < 1);
					a = a - 1;
					if (vec[a] == 0)
					{
						cout << endl << " You've already used this ally during this fight or he's knocked out" << endl;
					}
				} while (vec[a] == 0);
				vec[a] = 0;
				heal(*allies[a], allies);
			}
			break;
		}
		check = 0;
		for (int i = 0; i < int(size(vec)); i++)
			{
				check = check + vec[i];
			}
		for (int i = 1; i < int(size(allies)); i++)
		{
			if (allies[i]->hp <= 0)
			{
				allies[i]->hp = 0;
				cout <<" "<< allies[i]->name << " has been knocked out. He will recover after the fight." << endl;
			}
		}
		if (allies[0]->hp <= 0)
		{
			cout << "---------------YOU DIED. GAME OVER---------------" << endl;
			for (int i = 0; i < int(size(enemies)); i++)
			{
				delete enemies[i];
			}
			enemies.clear();
			for (int i = 0; i < int(size(allies)); i++)
			{
				delete allies[i];
			}
			allies.clear();
			Sleep(5000); 
			exit(1);
		}
		if (empty(enemies))
		{
			//cout << endl << " You defeated all enemies" << endl;
			return;
		}
		cout << "------------------------------------------------------------------------------------------------------" << endl;

	}
	
}

void fighting::enemies(std::vector<Character*>& allies, std::vector<Character*>& enemies)
{
	for (int i = 0; i < int(size(enemies)); i++)
	{
		auto r = d20::roll();
		int q = rand() % size(allies);
		while (allies[q]->hp == 0)
		{
			int q = rand() % size(allies);

		}
		cout << " Attacking enemy: " << endl;
		enemies[i]->status();
		cout << " Defending ally: " << endl;
		allies[q]->status();
		cout << " What do you want to do?" << endl << " [1] Block (uses strength)" << endl << " [2] Dodge (uses agility)" << endl << endl;
		int a = 0;
		do
		{
			cout<<" "; 
			while (!(cin >> a))
			{
				cout << "\n Please enter a number\n \n";
				cin.clear();
				cin.ignore();
			}
			if (a != 1 && a != 2)
			{
				cout << endl << " Choose one of the two options" << endl;
			}
		} while (a != 1 && a != 2);
		switch (a)
		{
		case 1: 
		{
			auto f = defend(*enemies[i], *allies[q]);
			if (!f)
			{
				allies[q]->hp = allies[q]->hp - (enemies[i]->strength + r / 4);
			}
		}
			break; 
		case 2:
		{
			auto g = dodge(*enemies[i], *allies[q]);
			if (!g)
			{
				allies[q]->hp = allies[q]->hp - (enemies[i]->strength + r / 4);
			}
		}
			break;

		}
		if (enemies[i]->hp <= 0)
		{
			std::vector<Character*>::iterator it = enemies.begin();
			it += i;
			cout <<" "<< enemies[i]->name << " dies" << endl;
			delete enemies[i];
			enemies.erase(it);
		}
		if (allies[q]->hp <= 0 && q!=0)
		{
			allies[q]->hp = 0;
			cout <<" "<< allies[q]->name << " has been knocked out. He will recover after the fight." << endl;
		}
		if (allies[0]->hp <= 0)
		{
			cout << "---------------YOU DIED. GAME OVER---------------" << endl;
			for (int i = 0; i < int(size(enemies)); i++)
			{
				delete enemies[i];
			}
			enemies.clear();
			for (int i = 0; i < int(size(allies)); i++)
			{
				delete allies[i];
			}
			allies.clear();
			Sleep(5000); 
			exit(1);
		}
		if (empty(enemies))
		{
			//cout << endl << " You defeated all enemies" << endl;
			return;
		}
		cout << "------------------------------------------------------------------------------------------------------" << endl;
	}
}

void fighting::fight(std::vector<Character*>& allies, std::vector<Character*>& enemies)
{
	while (allies[0]->hp > 0 && !empty(allies) && !empty(enemies))
	{
		auto r = d20::roll();
		auto q = d20::roll();
		if (r >= q)
		{
			fighting::allies(allies, enemies);
			if (allies[0]->hp <= 0)
			{
				cout << "---------------YOU DIED. GAME OVER---------------" << endl;
				for (int i = 0; i < int(size(enemies)); i++)
				{
					delete enemies[i];
				}
				enemies.clear();
				for (int i = 0; i < int(size(allies)); i++)
				{
					delete allies[i];
				}
				allies.clear();
				Sleep(5000); 
				exit(1);
			}
			if (empty(enemies))
			{
				cout << endl << " You defeated all enemies" << endl;
				for (int i = 0; i<int(size(enemies)); i++)
				{
					delete enemies[i];
				}
				enemies.clear();
				return;
			}

			fighting::enemies (allies, enemies);
			if (allies[0]->hp <= 0)
			{
				cout << "---------------YOU DIED. GAME OVER---------------" << endl;
				for (int i = 0; i < int(size(enemies)); i++)
				{
					delete enemies[i];
				}
				enemies.clear();
				for (int i = 0; i < int(size(allies)); i++)
				{
					delete allies[i];
				}
				allies.clear();
				Sleep(5000); 
				exit(1);
			}
			if (empty(enemies))
			{
				cout << endl << " You defeated all enemies" << endl;
				for (int i = 0; i<int(size(enemies)); i++)
				{
					delete enemies[i];
				}
				enemies.clear();
				return;
			}

			//system("CLS");
		}
		else
		{
			fighting::enemies(allies, enemies);
			if (allies[0]->hp <= 0)
			{
				cout << "---------------YOU DIED. GAME OVER---------------" << endl;
				for (int i = 0; i < int(size(enemies)); i++)
				{
					delete enemies[i];
				}
				enemies.clear();
				for (int i = 0; i < int(size(allies)); i++)
				{
					delete allies[i];
				}
				allies.clear();
				Sleep(5000); 
				exit(1);
			}
			if (empty(enemies))
			{
				cout << endl << " You defeated all enemies" << endl;
				for (int i = 0; i<int(size(enemies)); i++)
				{
					delete enemies[i];
				}
				enemies.clear();
				return;
			}

			fighting::allies(allies, enemies);
			if (allies[0]->hp <= 0)
			{
				cout << "---------------YOU DIED. GAME OVER---------------" << endl;
				for (int i = 0; i < int(size(enemies)); i++)
				{
					delete enemies[i];
				}
				enemies.clear();
				for (int i = 0; i < int(size(allies)); i++)
				{
					delete allies[i];
				}
				allies.clear();
				Sleep(5000); 
				exit(1);
			}
			if (empty(enemies))
			{
				cout << endl << " You defeated all enemies" << endl;
				for (int i = 0; i<int(size(enemies)); i++)
				{
					delete enemies[i];
				}
				enemies.clear();
				return;
			}

			//system("CLS");
		}
		if (allies[0]->hp <= 0)
		{
			cout << "---------------YOU DIED. GAME OVER---------------" << endl;
			for (int i = 0; i < int(size(enemies)); i++)
			{
				delete enemies[i];
			}
			enemies.clear();
			for (int i = 0; i < int(size(allies)); i++)
			{
				delete allies[i];
			}
			allies.clear();
			Sleep(5000); 
			exit(1);
		}
		if (empty(enemies))
		{
			cout << endl << " You defeated all enemies" << endl;
			for (int i = 0; i<int(size(enemies)); i++)
			{
				delete enemies[i];
			}
			enemies.clear();
			return;
		}
		
	}
}
