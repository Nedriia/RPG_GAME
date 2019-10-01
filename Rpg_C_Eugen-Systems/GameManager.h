#pragma once
#ifndef GAME_MANAGER
#define GAME_MANAGER
#include <iostream>

class Monster;
class Character;
class Inventory;

class GameManager
{
public:
	GameManager();

	void Lose();
	void Initialize(); //Initialize the monster and fill the target's variable of the player with it
	void Create_Player(); //Create the player, let the choice to pick the name and the class

	void DeleteEntity(); //Delete the monster
	void DeletePlayer(); //Delete the player	

	Monster* GetBrute() const;
	Character* GetHero() const;
	int GetWave() const;
	bool GetState() const; //Return the state of the player -> He's he still alive ? Or dead
	std::string get_Directory() const; //Return the directory where we want to write and save our run

	void Action(); //GameLoop -> Will ask the player which action he want to do 
	void WriteFolder(std::string directory, std::string Player_Name, int Waves_Record); //Fill the .txt at the directory with the player's name and the waves he accesed before he died
	
private:
	Monster *brute; //The Game manager has pointer towards the current monster---
	Character *hero; //---...the current player---									//So we able to know at any moment who is fighting versus who
	Inventory *inventory;//---...and an inventory to display random weapon

	std::string m_fluxFolder;//-> add a directory to create a .txt with every run describe in it -> If empty ->> will display a message error at the end of each run (with no consequence on the gameplay)

	int m_wave;
	int m_startingLife = 5;
	bool m_alive;
};

#endif // !GAME_MANAGER