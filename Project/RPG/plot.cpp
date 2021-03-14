#include <iostream>
#include <vector>
#include "chars.h"
#include "story.h"
#include <time.h>
#include "plot.h"
#include <string>
#include <Windows.h>
#include <fstream>
using std::cout;
using std::endl;
using std::cin;
using std::getline;

Character* Plot::Hero = nullptr;
std::vector<Character*> Plot::allies=std::vector<Character*>();
int Plot::l = 0;

bool Checks::char_check()
{
	auto r = d20::roll();
	if (r == 20)
	{
		return 1;
	}
	else if (r == 1)
	{
		return 0;
	}
	else if ((20 - r) < Plot::Hero->charisma)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool Checks::int_check()
{
	auto r = d20::roll();
	if (r == 20)
	{
		return 1;
	}
	else if (r == 1)
	{
		return 0;
	}
	else if ((20 - r) < Plot::Hero->smart)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void Plot::fighttest()
{
	cout << endl << " How many characters on the opposing side? (min 1)" << endl << endl;
	int e = 0;
	do
	{
		cout<<" "; 
		while (!(cin >> e))
		{
			cout << "\n Please enter a number\n \n";
			cin.clear();
			cin.ignore();
		}
		if (e < 1)
		{
			cout << endl << " Minimum One Character" << endl << endl;
		}
	} while (e < 1);
	std::vector<Character*> enemies;
	for (int i = 0; i < e; i++)
	{
		cout <<endl<< " Choose character class for enemy nr " << i + 1 << endl << " [1] Wizard " << endl << " [2] Knight" << endl << " [3] Barbarian" << endl << " [4] Bard" << endl << " [5] Sorcerer" << endl << endl;
		int c = 0;
		do
		{
			cout<<" "; 
			while (!(cin >> c))
			{
				cout << "\n Please enter a number\n \n";
				cin.clear();
				cin.ignore();
			}
			if (c < 1 || c>5)
			{
				cout << endl << endl << " Choose one of the given character classes" << endl << endl;
			}
		} while (c < 1 || c>5);
		switch (c)
		{
		case 1:
		{
			enemies.push_back(new Wizard);
		}
		break;
		case 2:
		{
			enemies.push_back(new Knight);
		}
		break;
		case 3:
		{
			enemies.push_back(new Barbarian);
		}
		break;
		case 4:
		{
			enemies.push_back(new Bard);
		}
		break;
		case 5:
		{
			enemies.push_back(new Sorcerer);
		}
		break;
		}
		cout << endl << " Enter this character's name" << endl << endl;
		string name;
		cout<<" "; 
		cin.get();
		getline(cin, name);
		enemies[i]->name = name;
	}

	cout << endl << " How many characters on your side? (min 1)" << endl << endl;
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
		if (a < 1)
		{
			cout << endl << " Minimum One Character" << endl << endl;
		}
	} while (a < 1);
	std::vector<Character*> allies;
	for (int i = 0; i < a; i++)
	{
		cout <<endl<< " Choose character class for ally nr " << i + 1 << endl << " [1] Wizard " << endl << " [2] Knight" << endl << " [3] Barbarian" << endl << " [4] Bard" << endl << " [5] Sorcerer" << endl << endl;
		int c = 0;
		do
		{
			cout<<" "; 
			while (!(cin >> c))
			{
				cout << "\n Please enter a number\n \n";
				cin.clear();
				cin.ignore();
			}
			if (c < 1 || c>5)
			{
				cout << endl << endl << " Choose one of the given character classes" << endl << endl;
			}
		} while (c < 1 || c>5);
		switch (c)
		{
		case 1:
		{
			allies.push_back(new Wizard);
		}
		break;
		case 2:
		{
			allies.push_back(new Knight);
		}
		break;
		case 3:
		{
			allies.push_back(new Barbarian);
		}
		break;
		case 4:
		{
			allies.push_back(new Bard);
		}
		break;
		case 5:
		{
			allies.push_back(new Sorcerer);
		}
		break;
		}
		cout << endl << " Enter this character's name" << endl << endl;
		string name;
		cout<<" "; 
		cin.get();
		getline(cin, name);
		allies[i]->name = name;
	}
	system("CLS");
	fighting::fight(allies, enemies);
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
}

void Plot::start()
{
	SetConsoleTitleA("THE QUEST FOR SALAZAR");
	cout << "                      Main Menu" << endl << "---------------THE QUEST FOR SALAZAR---------------" << endl<<endl<<" [1] New Game"<<endl<<endl<<" [2] Fighting Test"<<endl<<endl<<" [3] Characters Statistics"<<endl<<endl<<" [4] Exit"<<endl<<endl;
	int q = 0;
	do
	{
		cout<<" "; 
		while (!(cin >> q))
		{
			cout << "\n Please enter a number\n \n";
			cin.clear();
			cin.ignore();
		}
		if (q<1|| q>4)
		{
			cout <<endl<< " Pick one of the presented options" << endl<<endl;
		}
	} while (q < 1 || q>4);
	switch (q)
	{
	case 1:
	{
		
		begin();
	}
	break;
	case 2:
	
		fighttest();
		Sleep(5000);
		for (int i = 0; i<int(size(allies)); i++)
		{
			delete allies[i];
		}
		allies.clear();
		exit(1);

	
	case 3:
	{
		ifstream in("stats.txt");
		string text;
		std::vector<string> list;
		cout << endl;
		if (in.is_open())
		{
			while (getline(in, text))
			{
				list.push_back(text);
			}
			for (int i = 0; i<int(size(list)); i++)
			{
				cout << list[i]<<endl;
			}
		}
		else
		{
			cout << "file not found";
		}
		in.close();
	}
	break;
	case 4:
	{
		exit(1);
	}
	break;
	}
}

void Plot::begin()
{
	cout << " Quick instructions" << endl << endl << " This is a simple RPG game with number inputs" << endl << " Input just number assigned to options unless you are prompted to do otherwise" << endl << endl << " This game uses a 20-sided dice simulator as a means to include some random part into the game\n It is used to, among other things, influence the outcome of actions, fighting etc\n When it \"rolls\" 20 it means ultimate succes that often yields extra results. 1 on the other hand means ultimate failure which often has extra bad consequences \n There are seven xharacter statistics:\n Health - determines maximum amount of hp pne can have. To calculate it, multiply the number times 5\n Strength - determines how good one is at attacking and blocking and how much damage they can deal\n Agility - determines the chances one has to strike an opponent or avade a hit\n Charisma - used during story to check if one can concince other character to do or say something\n Magic - used to heal one's allies and themself\n Intelligence - used during story to determine if the character can deduce something or knows something\n Hp - number of health points the character currently has\n\n";
	cout << " This game has a turn based combat system.\n The turns however, are not per character but per team. During each turn all characters on each side must be used.\n Also, the order of turns is semi-random. Every two turns it is randomely chosen which team's turn is now. After it's the opposing side's time to shine.\n";
	cout << " Different characters have different statistics.\n Knight - 10, 12, 4, 5, 9, 10\n Barbarian - 15, 20, 5, 1, 3, 6\n Bard - 6, 3, 7, 20, 2, 12\n Sorcerer - 8, 5, 3, 5, 17, 12\n";
	cout << endl << " Choose character class for your Character "  << endl  << " [1] Knight" << endl << " [2] Barbarian" << endl << " [3] Bard" << endl << " [4] Sorcerer" << endl << endl;
	int c = 0;
	do
	{
		cout << " ";
		while (!(cin >> c))
		{
			cout << "\n Please enter a number \n\n";
			cin.clear();
			cin.ignore();
		}
		if (c < 1 || c>4 )
		{
			cout << endl << endl << " Choose one of the given character classes" << endl << endl;
			
		}
	} while (c < 1 || c>4);
	switch (c)
	{
	case 1:
	{
		Plot::Hero = new Knight;
	}
	break;
	case 2:
	{
		Plot::Hero = new Barbarian;
	}
	break;
	case 3:
	{
		Plot::Hero = new Bard;
	}
	break;
	case 4:
	{
		Plot::Hero = new Sorcerer;
	}
	break;
	}
	cout << "\n What is your character's name?\n\n ";
	Plot::allies.push_back(Hero);
	string nam;
	cin.get();
	getline(cin, nam);
	Hero->name = nam;
	first_part();
}

void Plot::level_up(int lev)
{
	for (int i = 0; i < lev; i++)
	{
		cout << " You gained a stat point! \n Choose which statistic to increase \n [1] Health\n [2] Strength\n [3] Agility\n [4] Charisma\n [5] Magic\n [6] Intelligence\n\n";
		int choice = 0;
		bool valid = 1;
		do 
		{
			while (!(cin >> choice))
			{
				cout << "\n Please enter a number\n \n";
				cin.clear();
				cin.ignore();
			}
			switch (choice)
			{
				case 1:
				{
					Hero->health++;
					Hero->hp = Hero->health * 5;
				}
				break;
				case 2:
				{
					Hero->strength++;
				}
				break;
				case 3:
				{
					Hero->agility++;
				}
				break;
				case 4:
				{
					Hero->charisma++;
				}
				break;
				case 5:
				{
					Hero->magic++;
				}
				break;
				case 6:
				{
					Hero->smart++;
				}
				break;
				default:
						{
							cout << "\n Choose one of the 6 stats\n\n";
							cin.clear();
							cin.ignore();
							valid = 0;
						}
			}
		} while (!valid);
	}
}

void Plot::first_part()
{
	system("CLS");
	cout << " You wake up in the gutter by the local inn\n Your liver and head still aching from last night binge\n A stranger approaches you\n \"Hey you. You're finally awake\"\n\n [1] \"Who are you?\"\n [2] \"What happened? Where are my things?\" \n\n ";
	int q;
	cin >> q;
	q = 0;
	cout << "\n \"You really don't remember, do you?\n Last night you gambled everything you had away while at the same time telling me to pour you more and that'll you'll pay it all after you win\"\n";
	cout << " \"Oh crap. I don't have the money on me right now but you know me, I'll come here again. I'll pay everything double then\"\n";
	if (Checks::char_check())
	{
		l++;
		part2a();
	}
	else
	{
		part2b();
	}
}

void Plot::part2a()
{
	cout << "\n               Succesfull charisma check \n\n";
	cout << " \"Sure thing, but make sure you have it on you next time you're here or I'm calling the guards\"\n \"Ok, I'll remember that\" \n You go back to your home. A small room rented above a port inn. But you always make a point to drink somewhere else. After all you wouldn't want your landlord to see you drunk.\n ";
	cout << " You take your shirt off. Go to bed to just lay a bit.\n After all what else is there to do. But just as you are going to do so, you notice something.\n There is a letter laying on the bed.\n";
	if (Checks::int_check())
	{
		l++;
		cout << " You think about picking it up but then decide against it. You don't need to read it to realize ";
		part3a();
	}
	else
	{
		cout << " You pick up the letter and read ";
		part3a();
	}
}

void Plot::part2b()
{
	cout << "\n               Failed charisma check \n\n";
	cout << " \"No way I'm letting you go away now, when I have you. I'm calling the guards right now\"\n You remember the dark, cold floor of the prison cell.\n You don't want to go there but there is nothing you can do\n Guards come and get you.\n They escort you to a carriage and while you think they take you to prison, you may end up somewhere else\n";
	if (Checks::int_check())
	{
		cout << "\n               Succesfull intelligence check \n\n";
		l++;
		part3c();
	}
	else
	{
		part3d();
	}

}

void Plot::part3a()
{
	cout << "your Father. Emperor Varrick Zhu Li.\n You don't need to open it to know he wants you to come to the palace and do something.\n Why else would he send the letter?\n You think about it for a while but decide you have nothing better to do anyways.\n You'll go\n";
	part4a();
}

void Plot::part3c()
{
	cout << " \"You realize they are taking you to your father, the Emperor. That means he has a \"Special mission\" for you...\n Those always end up badly. \n After all, you are the second child. Your brother, the heir gets all the fun, while you are sent to do mundane tasks\n like extorting unloyal subjects\n Wonder what he has in store for you this time";
	part4b();
}

void Plot::part3d()
{
	cout << "\n               Failed intelligence check \n\n";
	cout << " [1] Wait until you get there\n [2] Ask the guards where are you going\n ";
	int q = 0;
	do
	{
		cout << " ";
		while (!(cin >> q))
		{
			cout << "\n Please enter a number\n \n ";
			cin.clear();
			cin.ignore();
		}
		if (q < 1 || q>2)
		{
			cout << endl << " Pick one of the presented options\n" << endl << endl;
		}
	} while (q < 1 || q>2);
	switch (q)
	{
	case 1:
	{
		part4b();
	}
	break;
	case 2:
	{
		if (Checks::char_check())
		{
			cout << "\n \"To the palace, dumbass\"\n";
			l++;
			part3c();
		}
		else
		{
			cout << "\n \"We ain't tellin' you nothin'\"\n";
			part4b();
		}
	}
	break;
	}

}

void Plot::part4a()
{
	cout << "\n You arrive at the gate of the Grand Imperial Palace. One of the most significant landmarcs in the whole Empire.\n It also serves as the residence of none other than your father - Emperor Varrick Zhu Li\n \"I am surprised you came here yourself\" he says\n \"I thought I would find you at one of the inns\"\n \"Hello Father. Can we just cut the chase and you tell me why did you bring me here?\"\n His face loses any expression. You know he loves his royal protocols. And yet, he doesn't just discipline you.\n He must really need you\n";
	cout << " \"Fine. You have a reputation of quite the fighter.\n I need you to 'dispose' of someone who possesses much power and stands in opposition to my authority\"\n\n [1] \"Can't you just send a platoon of your soldiers?\"\n [2] \"Fun, maybe it'll at the very least be some fun\"\n\n";
	int q = 0;
	do
	{
		cout << " ";
		while (!(cin >> q))
		{
			cout << "\n Please enter a number\n \n ";
			cin.clear();
			cin.ignore();
		}
		if (q < 1 || q>2)
		{
			cout << endl << " Pick one of the presented options\n" << endl << endl;
		}
	} while (q < 1 || q>2);
	switch (q)
	{
	case 1:
	{
		cout << "\n \"I wish I could, but he is a highly skilled Wizard and none of my soldiers managed to even get close to him\"\n \"Fine, sounds fun\"";
		part5();
	}
	break;
	case 2:
	{
		part5();
	}
	break;
	}
}

void Plot::part4b()
{
	cout << "\n You arrive at the gate of the Grand Imperial Palace. One of the most significant landmarcs in the whole Empire.\n It also serves as the residence of none other than your father - Emperor Varrick Zhu Li\n \"I see my guards are working well\" he says\n \"I knew I would find you at one of the inns\"\n \"Hello Father. Can we just cut the chase and you tell me why did you bring me here?\"\n His face loses any expression. You know he loves his royal protocols. And yet, he doesn't just discipline you.\n He must really need you\n";
	cout << " \"Fine. You have a reputation of quite the fighter.\n I need you to 'dispose' of someone who possesses much power and stands in opposition to my authority\"\n\n [1] \"Can't you just send a platoon of your soldiers?\"\n [2] \"Fun, maybe it'll at the very least be some fun\"\n\n";
	int q = 0;
	do
	{
		cout << " ";
		while (!(cin >> q))
		{
			cout << "\n Please enter a number\n \n ";
			cin.clear();
			cin.ignore();
		}
		if (q < 1 || q>2)
		{
			cout << endl << " Pick one of the presented options\n" << endl << endl;
		}
	} while (q < 1 || q>2);
	switch (q)
	{
	case 1:
	{
		cout << "\n \"I wish I could, but he is a highly skilled Wizard and none of my soldiers managed to even get close to him\"\n \"Fine, sounds fun\"";
		part5();
	}
	break;
	case 2:
	{
		part5();
	}
	break;
	}
}

void Plot::part5()
{
	cout << "\n \"Happy you agreed. But you won't have to go alone.\n Before going on a journey, one ought to collect a fellowship.\n You can ask around in my court though I won't order anyone\"\n \"Ok then\"\n\n";
	vector<Character*> court;
	level_up(l);
	court.push_back(new Knight);
	court[0]->name = "Don Kichot";
	court.push_back(new Barbarian);
	court[1]->name = "Conan";
	court.push_back(new Bard);
	court[2]->name = "Dandelion";
	court.push_back(new Sorcerer);
	court[3]->name = "Mithrandir";
	bool end = 0;
	while (court.size() > 0 && !end)
	{
		cout << " Choose who to talk to:\n\n";
		for (int i = 0; i < int(court.size()); i++)
		{
			cout << " [" << i + 1 << "] " << court[i]->name<<endl;
		}
		cout << " [" << size(court) + 1 << "] Leave\n";
		int q = 0;
		do
		{
			cout << " ";
			while (!(cin >> q))
			{
				cout << "\n Please enter a number\n \n ";
				cin.clear();
				cin.ignore();
			}
			if (q < 1 || q>int(size(court))+1)
			{
				cout << endl << " Pick one of the presented options\n" << endl << endl;
			}
		} while (q < 1 || q>int(size(court))+1);
		q = q - 1;
		if (q == size(court))
		{
			end = 1;
		}
		else
		{
			std::vector<Character*>::iterator it = court.begin();
			it += q;
			if (Checks::char_check())
			{
				cout << " " << court[q]->name << " joined your team\n\n";
				allies.push_back(court[q]);
			}
			else
			{
				cout << " " << court[q]->name << " didn't join your team\n\n";
				delete court[q];
			}
			court.erase(it);
		}
	}
	for (int i = 0; i<int(court.size()); i++)
	{
		delete court[i];
	}
	court.clear();
	cout << "\n\n You team consists of " << allies.size();
	if (allies.size() == 1)
	{
		cout << " person\n\n";
	}
	else
	{
		cout << " people\n\n";
	}
	finale();
}

void Plot::finale()
{
	auto Salazar = new Wizard;
	Salazar->name = "Salazar";
	vector<Character*> enemies;
	enemies.push_back(Salazar);
	cout << " You enter a dark room in the Wizard's tower, you look around but noone is there \n You light up a torch. Before you stands a giant door with what looks like a puzzle written in some foreign language attached to it. \n";
	if (Checks::int_check())
	{
		cout << " Fortunately, you know this language to be orcish. A long forgotten one since the Great War and their extinction.\n You manage to solve the puzzle and the door opnes before you";
		level_up(2);
	}
	else
	{
		int i = 0;
		bool str = 0;
		for (;i < int(size(allies)); i++)
		{
			auto r = d20::roll();
			if (r == 20)
			{
				str = 1;
				break;
			}
			else if (r == 1)
			{
				str = 0;
			}
			else if ((20 - r) < allies[i]->strength)
			{
				str = 1;
				break;
			}
			else
			{
				str = 0;
			}
		}
		if (str)
		{
			cout << " The language is unknown to you but fortunately ";
			if (i == 0)
			{
				cout << "you are";
			}
			else
			{
				cout << allies[i]->name<<" is";
			}
			cout << " strong enough to knock the door off its hinges\n\n ";
			level_up(2);
		}
		else
		{
			cout << " The language is unknown to you but you find a tunnel leading around the door that is covered in blood\n";
		}

	}
	cout << " You are in what seems to be a throne room when you hear a sinister laugh coming from all around you \n \"I see you've found me... Though I must admit I haven't made it particurarly hard for you\"\n \"But let's just cut the chatter. I assume you are here to fight me. Let's find out how that goes for you\"\n\n";
	Sleep(500);
	fighting::fight(allies, enemies);
	cout << "\n   CONGRATULATIONS\n YOU HAVE WON THE GAME\n";
	ofstream stats("stats.txt", std::ios_base::app);
	//stats = fopen();
	if (stats.is_open())
	{
		stats << *Hero;
	}
	else
	{
		cout << "no file found";
	}
	stats.close();
	Sleep(5000); 
	for (int i = 0; i<int(size(allies)); i++)
	{
		delete allies[i];
	}
	allies.clear();
	for (int i = 0; i<int(size(enemies)); i++)
	{
		delete enemies[i];
	}
	enemies.clear();
	exit(1);
}
