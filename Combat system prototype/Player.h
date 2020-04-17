#pragma once
#include <string>
#include <vector>
#include "Constants.h"
#include "Skills.h"

using namespace Skills;
class Player
{
	std::vector<Skills::SkillName> move_set;
	int total_hp;
	int initiative;
	int current_hp;
	int accumulated_initiative = 0;
	int move_id = 0;
	
public:
	Player() = delete;
	Player(int hp, int initiative, std::vector<Skills::SkillName> move_set);
	bool IsAlive();
	bool CanUseAbility();
	void GainInitiative();
	std::string UseAbility(Player *opponent);
};

