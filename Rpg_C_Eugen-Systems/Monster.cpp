#include "pch.h"
#include <cstdlib>
#include <iostream>

#include "Monster.h"
#include "Character.h"


Monster::Monster(int health, Character* target) : m_hp(health) , m_target(target){}

Monster::~Monster()
{
	m_target = 0;
}

//Getters
int Monster::getMonster_hp() const
{
	return this->m_hp;
}

//Setters
void Monster::setMonster_hp(int hp)
{
	m_hp = hp;
}

//Methods
void Monster::Monster_BasicAttack()
{
	if (m_hp > 0)
	{
		std::cout << "\nThe enemy cast a Magic Missle : - 2 hp\n\n";
		m_target->ApplyDamage(2); //Apply damage directly into his target(our player)
	}
}
void Monster::Monster_MediumAttack()
{
	if (m_hp > 0)
	{
		std::cout << "\nThe enemy used his sword : - 5 hp \n\n";
		m_target->ApplyDamage(5);
	}
}
void Monster::Monster_UltimateAttack()
{
	if (m_hp > 0)
	{
		std::cout << "\nThe enemy charge with his giant axe : -8 hp \n\n";
		m_target->ApplyDamage(8);
	}
}

void Monster::ApplyDamage(int damage)
{
	m_hp -= damage;
}


