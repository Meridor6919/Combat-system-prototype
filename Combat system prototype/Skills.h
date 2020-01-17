#include "Constants.h"
class Player;

namespace skills {
	extern void xd1(Player *attacker, Player *target);
	extern void xd2(Player *attacker, Player *target);


	class Skills {
		std::pair<int, void(*)(Player *attacker, Player *target)> Skill_array[skills::skill_names::last];
		
		

	public:
		Skills()
		{
			Skill_array[skills::skill_names::default_attack] = std::make_pair( 100, &skills::xd1);
			Skill_array[skills::skill_names::default_block] =  std::make_pair(100, &skills::xd2);
		}
		auto TakeAction(int skill)
		{
			if (skill < skills::skill_names::last)
			{
				return Skill_array[skill].second;
			}
			else

			{
				void(*temp)(Player* p1, Player*p2) = nullptr;
				return temp;
			}
		}
		int GetCost(int skill)
		{
			if (skill < skills::skill_names::last)
			{
				return Skill_array[skill].first;
			}
			else
			{
				return -1;
			}
		}
	};
}