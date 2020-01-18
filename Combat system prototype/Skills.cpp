#include <iostream>
#include "Player.h"
#include "Skills.h"

namespace skills
{
	std::string default_attack(Player *attacker, Player *target)
	{
		return "attack";
	}
	std::string default_block(Player *attacker, Player *target)
	{
		return "block";
	}
}