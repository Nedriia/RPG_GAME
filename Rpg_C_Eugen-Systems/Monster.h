#pragma once
#ifndef MONSTER
#define MONSTER

class Character;

class Monster
{
public:
	Monster(int health, Character* target); //Each Monster has a target (our player), so he know on who to deal damage
	~Monster();

	int getMonster_hp() const;

	void setMonster_hp(int hp);

	void Monster_BasicAttack();
	void Monster_MediumAttack();
	void Monster_UltimateAttack();

	void ApplyDamage(int damage);
	
private:
	int m_hp;
	Character* m_target;
};

#endif // !MONSTER