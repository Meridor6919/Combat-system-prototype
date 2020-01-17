#include <iostream>
#include "Player.h"
#include "Skills.h"

namespace skills
{
	void xd1(Player *attacker, Player *target)
	{
		std::cout << "attacked";
	}
	void xd2(Player *attacker, Player *target)
	{
		std::cout << "blocked";
	}
}