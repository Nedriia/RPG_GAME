#pragma once
#ifndef  WARRIOR
#define WARRIOR

class Character;

class Warrior : public Character
{
public:
	Warrior(std::string name, std::string weapon_name);

	void Attack_Basic() override;
	void Attack_Medium() override;
	void Ultimate_Attack() override;

	void ResetPlayer();
	void DisplayAction() const;

private:
	int const m_basicLife = 50;
	int const m_basicMana = 10;
};

#endif // ! WARRIOR