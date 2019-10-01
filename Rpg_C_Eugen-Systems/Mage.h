#pragma once
#ifndef  MAGE
#define MAGE

class Character;

class Mage : public Character
{
public:
	Mage(std::string name, std::string weapon_name);

	void Attack_Basic() override;
	void Attack_Medium() override;
	void Ultimate_Attack() override;

	void ResetPlayer() override;
	void DisplayAction() const override;

private:
	int const m_basicLife = 20;
	int const m_basicMana = 100;
};

#endif // ! MAGE