#pragma once
#ifndef INVENTORY
#define INVENTORY

class Weapon;
class Character;

class Inventory
{
public:
	Inventory();
	~Inventory();

	void setPlayerTarget(Character *hero); //TODO : Pas oublier

	void Loot_GlobalAction();

private:
	//Here we create a list of all different lootable weapons with(damage, Name, description)
	std::list<Weapon> lootableStuff = { Weapon(10,"Fangs of the Devourer","Azhir manari kirel. Akim manari galar!"),
								   Weapon(5,"Claws of Ursoc","Azeroth will need you. If you do not stand ready, the world may fall."),
								   Weapon(12,"Fists of the Heavens","There was a great flash of light and a great rush of air, and when it was done, Irmaat could feel his weapons, Al'burq and Alra'ed trembling with elemental power."),
								   Weapon(15,"Aldrachi Warblades","His warblades howled over the clamor of battle, rending anything that came near. Each demon Toranaar vanquished seemed to fill him with renewed vigor and strength. He was an army unto himself."),
								   Weapon(10,"Blades of the Fallen Prince","I will show you the justice of the grave... and the true meaning of fear."),
								   Weapon(6,"Fangs of Ashamane","She ripped through the demons' ranks and then disappeared into the trees. She crept along the high branches and dove down upon the Legion commanders. She was a terror, a fearsome beast, and she held nothing back, offering no mercy."),
								   Weapon(9,"Warswords of the Valarjar","In truth, it is her power that makes these weapons truly magnificent. Her power, laced with her hatred, crashes endlessly against Odyn's spirit. The tension between those energies will forever permeate these blades..."),
								   Weapon(12,"Sheilun, Staff of the Mists","You seek the calm, inevitable force of a deep river, the kind that carves canyons into the toughest stone and carries away warriors on its currents without so much as a ripple.Sheilun is the embodiment of that idea."),
								   Weapon(22,"Fury of the Stonemother","Created through the power of Doomhammer and the powerful shaman who wields it."),
								   Weapon(2,"The Kingslayers","It was not a pleasant death. But it was fast, quiet, and efficient. When the orc took his last breath, the wound that killed him became irregular. Nobody would be able to tell whether he had died to a knife, an axe, or a spear."),
								   Weapon(3,"Spine of Thal'kiel","The Wakeners' screams echoed across Argus, as a grim reminder of the price paid for dealing with demons."),
								   Weapon(5,"Scaleshard","Here is whence true strength comes. From deep places... within the world, and within oneself."),
								   Weapon(5,"Talonclaw","The Eagle Spear. Spear of the Wild Gods. Talonclaw. Bearing many names and many blessings, this is a weapon of legends."),
								   Weapon(8,"The Dreadblades","No blade can shed the blood of so many innocents and not demand a toll on its wielder as well. They are no treasure."),
								   Weapon(28,"Twinblades of the Deceiver","The end has come! Let the unravelling of this world commence!"),
								   Weapon(2,"The Fist of Ra-den","To seal Al'Akir's demise, Master Ra slammed his fist into the mountaintop. The heavens split wide, and all the fire and fury they contained crashed down atop the Windlord's head."),
								   Weapon(2,"Fists of the Heavens","When Irmaat hefted his two weapons and tested the power within them, uncontrollable fury spilled forth."),
								   Weapon(2,"Sharas'dal, Scepter of Tides","They drifted into the abyss, but Azshara and her Highborne remained unbroken. The darkness around them was absolute, and so the queen willed Sharas'dal to bring them light..."),
								   Weapon(12,"Oathseeker","Killing for the sake of killing... conquering for the sake of conquest... there is no honor in such things. There is only shame and regret."),
								   Weapon(10,"T'uure, Beacon of the Naaru","Blessed are the torchbearers, who bring light to the darkness."),
								   Weapon(11,"Aldrachi Warblades","The Aldrachi were a proud race. Too proud to serve. Millions of demons died before the Aldrachi were wiped out, and it took Sargeras himself to kill their king."),
								   Weapon(22,"Light's Wrath","It was with our greatest hopes and prayers that we attended the ceremony that day... and it is with our greatest sorrows that we departed it."),
								   Weapon(35,"Strom'kar, the Warbreaker","The steel of the barbarian king shall strike the final blow. It shall silence the din of battle, and bring the first kingdom into an age of peace."),
								   Weapon(50,"Maw of the Damned","The Maw's thirst is unquenchable. If it is not fed fresh victims, it will not hesitate to drink from its wielder instead.") };
	

	float m_probabiltyToLoot_Potion = 0.85f; //On each monster, your player has 85% chance to loot a potion of heal or mana 
	float m_probabiltyToLoot_Stuff = 0.65f; // -> and 65% to loot a weapon

	bool Loot(float probability) const; //Random for potion
	Weapon RandomWeapon(); //-> Pick a random number between the first element of the list of loot and his size, and display the weapon bound
	Character *m_hero; //TODO :  Destructor and touti quanti

	void Choice_ToSwitchWeapon();
	void Drop_Potion();
};

#endif