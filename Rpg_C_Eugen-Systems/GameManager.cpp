#include "pch.h"
#include "GameManager.h"

#include <string>
#include <sstream>
#include <fstream>

#include "Character.h"
#include "Warrior.h"
#include "Mage.h"
#include "Hunter.h"
#include "Monster.h"
#include "Inventory.h"


GameManager::GameManager()
{
	inventory = new Inventory();
}

//Getters
Monster* GameManager::GetBrute()const
{
	return this->brute;
}
Character* GameManager::GetHero() const
{
	return this->hero;
}
int GameManager::GetWave() const
{
	return this->m_wave;
}
bool GameManager::GetState()const
{
	return this->m_alive;
}
std::string GameManager::get_Directory() const
{
	return this->m_fluxFolder;
}

//Methods
void GameManager::Lose()
{
	std::cout << ".....And " << hero->getName() << " died in the fight. He survided "<< m_wave << " waves \n\n";

	WriteFolder(get_Directory(), hero->getName(), m_wave);//-> write in a folder

	std::cout << "Would you want to continue ? \n\n";
	std::cout << "     -1 To Retry a run \n";
	std::cout << "     -2 To Exit \n";
	m_startingLife = 5;
	bool loop = true;
	int choice = 0;
	while (loop)
	{
		std::string s;
		std::getline(std::cin, s);
		std::stringstream stream(s);
		if (stream >> choice && choice <= 2 && choice > 0)
		{
			while (choice != 1 && choice != 2)
			{
				std::cin >> choice;
			}
			loop = false;
			continue;
		}
		else if (s != "")
			std::cout << "Invalid!" << std::endl;
	}

	switch (choice)
	{
		case 1:
			DeletePlayer();
			DeleteEntity();
			Create_Player();
			Initialize();
			break;
		case 2:
			system("cls");
			DeleteEntity();
			DeletePlayer();
			delete inventory;
			std::exit(0);
			break;

		default:
			break;
	}
	m_alive = true;
	system("cls");
}
void GameManager::Initialize()
{
	brute = new Monster(m_startingLife, GetHero());
	hero->setTarget(brute);
	m_startingLife *= 1.25f;
	m_wave++;
}
void GameManager::Create_Player()
{
	m_wave = 0;
	system("cls");
	std::cout << "What's your name ? \n";
	std::string name;
	while(name == "")
		std::getline(std::cin, name);
	system("cls");
	std::cout << "Which class you want to play this run ? \n\n";
	std::cout << "  1-  Mage \n";
	std::cout << "  2-  Warrior \n";
	std::cout << "  3-  Hunter \n";
	
	bool loop = true;
	int choice = 0;
	while (loop)
	{
		std::string s;
		std::getline(std::cin, s);
		std::stringstream stream(s);
		if (stream >> choice && choice <= 3 && choice > 0)
		{
			while (choice != 1 && choice != 2 && choice != 3)
			{
				std::cin >> choice;
			}
			loop = false;
			continue;
		}
		else if (s != "")
			std::cout << "Invalid!" << std::endl;
	}

	switch (choice)
	{
		case 1:
			hero = new Mage(name, "Toothpick");
			break;
		case 2:
			hero = new Warrior(name, "Wooden Axe");
			break;
		case 3:
			hero = new Hunter(name, "Rusty conquistador sword");
			break;

		default:
			break;
	}
	inventory->setPlayerTarget(hero); //Give to the inventory your player -> so we know who can have weapon or potion
	m_alive = true;
	system("cls");
}
void GameManager::DeletePlayer()
{
	delete hero;
	hero = 0;
}
void GameManager::DeleteEntity()
{
	delete brute; //Call the monster destructor -> destroy the target before destroying the monster
	brute = 0;
}

//Core Loop
void GameManager::Action()
{
	hero->DisplayAction();
	bool loop = true;
	int move;
	while (loop)
	{
		std::string s;
		std::getline(std::cin, s);
		std::stringstream stream(s);
		if (stream >> move)
		{
			loop = false;
			continue;
		}
		else if(s != "")
			std::cout << "Invalid!" << std::endl;
	}

	system("cls");
	//Depending on the input, we call the methods bound
	switch (move)
	{
	case 1:
		hero->Attack_Basic();
		brute->Monster_BasicAttack();
		break;
	
	case 2:
		hero->Attack_Medium();
		brute->Monster_MediumAttack();
		break;

	case 3:
		hero->Ultimate_Attack();
		brute->Monster_UltimateAttack();
		break;

	default:
		break;
	}

	if (hero->getCharacter_Hp() <= 0)
	{
		m_alive = false;
		Lose();
	}
	else if (GetBrute()->getMonster_hp() <= 0)
	{
		inventory->Loot_GlobalAction();

		system("cls"); //Clear the screen

		DeleteEntity();//We can destroy the monster

		std::cout << "New brute incoming \n" << std::endl;
		Initialize();
	}
} 

//Save
void GameManager::WriteFolder(std::string directory, std::string Player_Name, int Waves_Record)
{
	std::ofstream flux(directory.c_str(), std::ios::app);
	if (flux)
		flux << Player_Name << "  :  " << Waves_Record << "\n";
	else
		std::cout << "\nERROR_REPOSITORY_NOT_FOUND / NO_DATA_TO_DISPLAY\n\n" << std::endl;
}
