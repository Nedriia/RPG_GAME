#include "pch.h"

#include "Character.h"
#include "Hunter.h"

Hunter::Hunter(std::string name, std::string weapon_name) : Character(name)
{
	m_weapon = new Weapon(2, weapon_name); //All Classes start with a basic weapon predefined
	m_hp = m_basicLife;
	m_mana = m_basicMana;
}

//Methods
void Hunter::Attack_Basic()
{
	std::cout << "Fiouu...Yes it's an arrow" << std::endl;
	m_target->ApplyDamage(m_weapon->ApplyDamage(1.55f)); //Apply weapon -> call the methods of weapon (It take the damage of the current weapon * (the multiplier) -> here 1.55
}
void Hunter::Attack_Medium()
{
	if (m_mana >= 2)
	{
		std::cout << "Arrow Raffallleee" << std::endl;
		m_mana -= 2;
		m_target->ApplyDamage(m_weapon->ApplyDamage(2.15f));
	}
	else
		std::cout << "You're exhausted, you can't cast this attack right now :>\n\n";
}
void Hunter::Ultimate_Attack()
{
	if (m_mana >= 5)
	{
		std::cout << "You trigger the power of the elements and your familiar" << std::endl;
		m_mana -= 5;
		m_target->ApplyDamage(m_weapon->ApplyDamage(2.55f));
	}
	else
		std::cout << "You're exhausted, you can't cast this attack right now :>\n\n";
}
void Hunter::ResetPlayer()
{
	m_hp = m_basicLife;
	m_mana = m_basicMana;
}
void Hunter::DisplayAction() const
{
	std::cout << "Status:\n" << std::endl;
	std::cout << "Hp_Ennemy : " << m_target->getMonster_hp() << std::endl << "Health : " << m_hp << std::endl << "Mana : " << m_mana << std::endl << "\n(1) Cobra Shot " << std::endl << "(2) Rapid Fire " << std::endl << "(3) Raptor Strike " << std::endl;
}