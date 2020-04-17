#pragma once
#include "Constants.h"
#include <string>
class Player;

extern std::string default_attack(Player *attacker, Player *target);
extern std::string default_block(Player *attacker, Player *target);

using namespace Skills;

class SkillRegister {
	std::pair<int, std::string(*)(Player *attacker, Player *target)> Skill_array[SkillName::Last];
	SkillRegister()
	{
		Skill_array[SkillName::DefaultAttack] = std::make_pair( 100, &default_attack);
		Skill_array[SkillName::DefaultBlock] =  std::make_pair(100, &default_block);
	}
public:
	static SkillRegister* GetSkills()
	{ 
		static SkillRegister s = SkillRegister();
		return &s;
	}
	auto TakeAction(SkillName skill_id)
	{
		return Skill_array[skill_id].second;
	}
	int GetCost(SkillName skill_id)
	{
		if (skill_id < SkillName::Last)
		{
			return Skill_array[skill_id].first;
		}
		else
		{
			return -1;
		}
	}
};

