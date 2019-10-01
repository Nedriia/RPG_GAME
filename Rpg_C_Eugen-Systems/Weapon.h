#pragma once
#ifndef WEAPON
#define WEAPON

#include <list>

class Weapon
{
public:
	Weapon(int damage, std::string name);
	Weapon(int damage, std::string name, std::string description);
	Weapon(Weapon const& WeaponToCopie);

	std::string getDescription()const;
	std::string get_WeaponName() const;
	int getDamageStats() const;

	int ApplyDamage(float multiplier) const;
	void display_NewWeapon_Stats(std::ostream &flux)const;
	
private:
	int m_damage;
	std::string m_name;
	std::string m_description;
};

std::ostream& operator<<(std::ostream &flux, Weapon const& weapon);

#endif // !WEAPON
