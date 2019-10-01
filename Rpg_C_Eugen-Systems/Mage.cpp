#include "pch.h"

#include "Character.h"
#include "Mage.h"

Mage::Mage(std::string name, std::string weapon_name) : Character(name)
{
	m_weapon = new Weapon(2, weapon_name); //All Classes start with a basic weapon predefined
	m_hp = m_basicLife;
	m_mana = m_basicMana;
}

//Methods
void Mage::Attack_Basic()
{
	std::cout << "You cast a missle" << std::endl;
	m_target->ApplyDamage(m_weapon->ApplyDamage(2.10f));//Apply weapon -> call the methods of weapon (It take the damage of the current weapon * (the multiplier) -> here 2.10
}
void Mage::Attack_Medium()
{
	if(m_mana >= 6)
	{
		std::cout << "You cast a giant thunderstorm" << std::endl;
		setCharacter_Mana(m_mana - 6);
		m_target->ApplyDamage(m_weapon->ApplyDamage(2.55f));
	}
	else
		std::cout << "You're exhausted, you can't cast this attack right now :>\n\n";
}
void Mage::Ultimate_Attack()
{
	if(m_mana >= 8)
	{
		std::cout << "APOCAALLIPTIIICAA" << std::endl;
		m_mana -= 8;
		m_target->ApplyDamage(m_weapon->ApplyDamage(3.55f));
	}
	else
		std::cout << "You're exhausted, you can't cast this attack right now :>\n\n";
}
void Mage::ResetPlayer()
{
	m_hp = m_basicLife;
	m_mana = m_basicMana;
}
void Mage::DisplayAction() const
{
	std::cout << "Status:\n" << std::endl;
	std::cout << "Hp_Ennemy : " << m_target->getMonster_hp() << std::endl << "Health : " << m_hp << std::endl << "Mana : " << m_mana << std::endl << "\n(1) Firebolt " << std::endl << "(2) Lightning Storm " << std::endl << "(3) Apocalypse Cast " << std::endl;
}