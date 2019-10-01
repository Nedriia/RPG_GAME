#include "pch.h"
#include "string"

#include "Character.h"
#include "Monster.h"


Character::Character(std::string name) : m_name(name){}

Character::~Character()
{
	m_weapon = 0; //Pointers back to 0
	m_target = 0;
}

//Getters 
int Character::getCharacter_Hp() const
{
	return this->m_hp;
}
int Character::getCharacter_Mana() const
{
	return this->m_mana;
}
std::string Character::getName() const
{
	return this->m_name;
}
Weapon Character::getWeapon() const
{
	return *m_weapon;
}


//Setters 
void Character::setCharacter_Hp(int hp)
{
	m_hp = hp;
}
void Character::setCharacter_Mana(int mana)
{
	m_mana = mana;
}
void Character::setTarget(Monster* target)
{
	m_target = target;
}


//Methods
void Character::Attack_Basic(){}
void Character::Attack_Medium(){}
void Character::Ultimate_Attack(){}

void Character::ApplyDamage(int damage)
{
	m_hp = m_hp - damage;
}
void Character::ChangeWeapon(Weapon *newWeapon)
{
	*m_weapon = *newWeapon;
}
void Character::DisplayAction()const {}

void Character::ResetPlayer(){}

