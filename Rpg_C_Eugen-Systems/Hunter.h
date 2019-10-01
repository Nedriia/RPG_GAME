#pragma once
#ifndef  HUNTER
#define HUNTER

class Character;

class Hunter : public Character
{
public:
	Hunter(std::string name, std::string weapon_name);

	void Attack_Basic() override;
	void Attack_Medium() override;
	void Ultimate_Attack() override;

	void ResetPlayer() override;
	void DisplayAction() const override;
	 
private:
	int const m_basicLife = 35;
	int const m_basicMana = 35;
};

#endif // ! HUNTER