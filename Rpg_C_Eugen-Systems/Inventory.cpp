#include "pch.h"
#include <iostream>
#include <string>
#include <sstream>
#include <time.h>

#include "Weapon.h"
#include "Inventory.h"
#include "Character.h"


Inventory::Inventory()
{
	srand(time(NULL)); //-> initialize random seed
}

Inventory::~Inventory(){}

//Setters
void Inventory::setPlayerTarget(Character *hero)
{
	m_hero = hero;
}

//Methods
bool Inventory::Loot(float probability) const
{
	return rand() % 100 < (probability * 100); //Pick a random with a probability
}
Weapon Inventory::RandomWeapon()
{
	int result = rand() % lootableStuff.size();
	std::list<Weapon>::iterator it = lootableStuff.begin();
	std::advance(it, result);
	Weapon *newWeapon = new Weapon(it->getDamageStats(), it->get_WeaponName(), it->getDescription());
	return *newWeapon;
}
void Inventory::Drop_Potion()
{
	std::cout << "\n...WAIT... You find something on his corpse\n";
	int choice = rand() % 2 + 1;
	switch (choice)
	{
	case 1:
		std::cout << "You loot a heal potion\n\n";
		m_hero->setCharacter_Hp(m_hero->getCharacter_Hp() + 15);
		break;
	case 2:
		std::cout << "You loot a mana potion\n\n";
		m_hero->setCharacter_Mana(m_hero->getCharacter_Mana() + 15);
	default:
		break;
	}
}
void Inventory::Choice_ToSwitchWeapon()
{
	std::cout << "\nYou find a chest on him and decide to open it\n\n";
	Weapon newWeapon = RandomWeapon();
	std::cout << "        \"" << newWeapon.get_WeaponName() << "\"\n" << std::endl;
	int result = newWeapon.getDamageStats() - m_hero->getWeapon().getDamageStats();
	std::cout << "Stats difference with your current weapon : ";
	std::cout << (result > 0 ? "+ " : " ") << result << std::endl;
	std::cout << "...Something is written on the blade : \n\n" << "\"" << newWeapon.getDescription() << "\"" << "\n";

	std::cout << "\n\n\n" << "Would you like to switch ?" << std::endl;
	std::cout << "     -1  Yes\n";
	std::cout << "     -2  No\n";

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
		m_hero->ChangeWeapon(&newWeapon);
		break;
	case 2:
		break;
	default:
		break;
	}
}
void Inventory::Loot_GlobalAction()
{
	system("cls");
	std::cout << "\nYour current ennemy has been killed... GG\n";
	if (Loot(m_probabiltyToLoot_Potion))
	{
		Drop_Potion();
	}
	if (Loot(m_probabiltyToLoot_Stuff))
	{
		Choice_ToSwitchWeapon();
	}
}


