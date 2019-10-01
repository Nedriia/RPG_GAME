#include "pch.h"
#include <iostream>
#include <string>
#include <iterator>

#include "Weapon.h"


Weapon::Weapon(int damage, std::string name) : m_damage(damage), m_name(name){}

Weapon::Weapon(int damage, std::string name, std::string description) : m_damage(damage), m_name(name), m_description(description){}

Weapon::Weapon(Weapon const& WeaponToCopie) : m_damage(WeaponToCopie.m_damage) , m_name(WeaponToCopie.m_name) , m_description(WeaponToCopie.m_description){}


//Getters
std::string Weapon::get_WeaponName()const
{
	return this->m_name;
}
std::string Weapon::getDescription()const
{
	return this->m_description;
}
int Weapon::getDamageStats() const
{
	return this->m_damage;
}

//Methods
int Weapon::ApplyDamage(float multiplier)const
{
	std::cout << m_name << " cast " << (int)(m_damage * multiplier) << " damage " << std::endl;
	return m_damage * multiplier;
}
void Weapon::display_NewWeapon_Stats(std::ostream &flux)const
{
	std::cout << m_name << " " << m_damage << "\n";
}

std::ostream &operator<<(std::ostream &flux, Weapon const &weapon)
{
	weapon.display_NewWeapon_Stats(flux);
	return flux;
}
