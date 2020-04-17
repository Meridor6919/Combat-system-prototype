#pragma once
#include <string>

class Player
{
public:
	int total_hp;
	int initiative;


	int current_hp;
	int current_initiative;
	

	Player();
	std::string UseAbility(int turn, Player *opponent) { return ""; };
};

