#pragma once
#ifndef CHARACTER
#define CHARACTER

#include <iostream>

#include "Monster.h"
#include "Weapon.h"

class Character
{
public:
	Character(std::string name);
	~Character();

	int getCharacter_Hp() const;
	int getCharacter_Mana() const;
	void ApplyDamage(int damage);
	std::string getName() const;
	Weapon getWeapon() const; //Return the current weapon the player is using 

	void setCharacter_Hp(int hp); //Methods used for heal and...
	void setCharacter_Mana(int mana); //...Mana potion
	void setTarget(Monster *target); //Each player has a target, they know who to apply damage
	void ChangeWeapon(Weapon *newWeapon);

	virtual void Attack_Basic(); 
	virtual void Attack_Medium();
	virtual void Ultimate_Attack();

	virtual void ResetPlayer() = 0; //Abstract class to disable creation of character
	virtual void DisplayAction()const; //Allow use to display every action allowed for each player

protected:
	Weapon *m_weapon;
	Monster *m_target;

	std::string m_name;

	int m_hp;
	int m_mana;
};

#endif // !CHARACTER