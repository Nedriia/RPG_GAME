#include "pch.h"
#include <iostream>

#include "GameManager.h"

/*""Short"" Resume before starting working on it*/

/*So in this game we're facing a monster, we have each turn 3 different actions -> all of them attack him and he deals us a certain amount of damage in return  ----//We want to keep the same mechanic//----
Once the monster is dead the game is finish

First Observation :
	Health and mana have no limit->so we can consume all of our attacks and we will have a negative mana with no affect on the game
		Same for the life->our health point can be negative and the game will still we continuing
	There is no check of the input ask to the player -> if we type a char in place of an integer, the program blow up, if we type an int not in the range of the int asked it's will don't say anything as return
	The monster can attack in the tour where he died even if the player play first
	Variables are set back to default on the end of the game->no need because we are leaving the game
	All of the process of the game are accesible in the same file, so we can set the values as we want and for maintenance it's a mess

On the replayability point(even if it's a small game):
	We are only allowed to fight one monster without real challenge -> when the monster is dead we have no other choice but to leave

On a maintenance point of view :
	We need to hide the core loop process to the player, hide variables so they can't be switched and take off all possibility to mess with the game
	-> I create a character abstract class with basic method, so we can know the hp, mana, his target, his weapon, attacks...
		And i have classes (Mage, Hunter, Warrior) who derived of it and each of them are overiding they attacks methods
		//So with that we have different player(with different characteristics and attaks) -> easier to change

	Like the player, the monster has his own class so we can make change and manage it easily -> in the futur we could imagine different type of monster

	The game now is handle by the gameManager -> He takes care of managing the instantiation/destruction of the player and the monster

	Finally we have an Inventory Class-> with a list defined in advance of possible loot and proba of luck to give object to the player
	//we can change our current weapon with the one dropped or leave it, we could imagine a to stock potion too. For now if we drop a potion, she's applied automatically

On a personal point of view =
	My first idea was to create an endless dungeon, we keep killing monster(when we kill a monster the next one is stronger) over and over until we died.
	For more variety I added classes of player, basically it don't change much on the gameplay. You will have different outputs depending the class you chose. And not every class are equal : for example, 
	mage can burst more damage but has less life, warrior can heal themselves on each attack and the hunter is a medium class between the other two
	Other idea : If u think of RPG, you think of loot, so when you kill a monster you will have a certain amount of probability(85 % actually) to drop a potion(heal or mana) and if you are lucky
	(with 65 % of chance->every proba can be adjust) you will drop a new weapon with its own characteristics.You will then have the choice between switching of weapon with hope to go further or 
	then continue with your own
	I added a save record too, (limited for now), if u define a folder directory, it write in it the name of your player with his record of waves achieved*/

/*I know it will take some time to read it all but it would be a real pleasure to have feedback on it, it would really allow me to improve myself
			arthur.favre@hotmail.com
*/

int main()
{
	GameManager manager;
	manager.Create_Player(); 
	manager.Initialize();

label:
	if (manager.GetState())
		manager.Action();
	else
		return 0;

	goto label;
}
