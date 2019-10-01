#include "pch.h"

#include "Character.h"
#include "Warrior.h"

Warrior::Warrior(std::string name, std::string weapon_name) : Character(name)
{
	m_weapon = new Weapon(2, weapon_name); //All Classes start with a basic weapon predefined
	m_hp = m_basicLife;
	m_mana = m_basicMana;
}

void Warrior::Attack_Basic()
{
	std::cout << "*POUM POUM*" << std::endl;
	m_target->ApplyDamage(m_weapon->ApplyDamage(1.25f)); //Apply weapon -> call the methods of weapon (It take the damage of the current weapon * (the multiplier) -> here 1.25
}
void Warrior::Attack_Medium()
{
	std::cout << "AAARRRRGHHH" << std::endl;
	m_hp += 2; 
	std::cout << "You have regen 2 hp during the fight\n";
	m_target->ApplyDamage(m_weapon->ApplyDamage(1.75f));
}
void Warrior::Ultimate_Attack()
{
	std::cout << "BULLLLLLIIIIIIAAAAAAEEWWW" << std::endl;
	m_hp += 5;
	std::cout << "You have regen 5 hp during the fight\n";
	m_target->ApplyDamage(m_weapon->ApplyDamage(2.25f));
}

void Warrior::ResetPlayer()
{
	m_hp = m_basicLife;
	m_mana = m_basicMana;
}
void Warrior::DisplayAction() const
{
	std::cout << "Status:\n" << std::endl;
	std::cout << "Hp_Ennemy : " << m_target->getMonster_hp() << std::endl << "Health : " << m_hp << std::endl << "Mana : " << m_mana << std::endl << "\n(1) Execute " << std::endl << "(2) Bloodthirst " << std::endl << "(3) Siegebreaker " << std::endl;
}