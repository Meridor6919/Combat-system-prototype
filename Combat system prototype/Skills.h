#include "Constants.h"
#include <string>
class Player;

extern std::string default_attack(Player *attacker, Player *target);
extern std::string default_block(Player *attacker, Player *target);

class SkillRegister {
	std::pair<int, std::string(*)(Player *attacker, Player *target)> Skill_array[skill_names::Last];
	SkillRegister()
	{
		Skill_array[skill_names::DefaultAttack] = std::make_pair( 100, &default_attack);
		Skill_array[skill_names::DefaultBlock] =  std::make_pair(100, &default_block);
	}
public:
	static SkillRegister* GetSkills()
	{ 
		static SkillRegister s = SkillRegister();
		return &s;
	}
	auto TakeAction(skill_names skill_id)
	{
		if (skill_id < skill_names::Last)
		{
			return Skill_array[skill_id].second;
		}
		else

		{
			std::string(*temp)(Player* p1, Player*p2) = nullptr;
			return temp;
		}
	}
	int GetCost(skill_names skill_id)
	{
		if (skill_id < skill_names::Last)
		{
			return Skill_array[skill_id].first;
		}
		else
		{
			return -1;
		}
	}
};

