#include "Constants.h"
#include <string>
class Player;

namespace skills {
	extern std::string default_attack(Player *attacker, Player *target);
	extern std::string default_block(Player *attacker, Player *target);


	class Skills {
		std::pair<int, std::string(*)(Player *attacker, Player *target)> Skill_array[skills::skill_names::Last];
		
		

	public:
		Skills()
		{
			Skill_array[skills::skill_names::DefaultAttack] = std::make_pair( 100, &skills::default_attack);
			Skill_array[skills::skill_names::DefaultBlock] =  std::make_pair(100, &skills::default_block);
		}
		auto TakeAction(int skill)
		{
			if (skill < skills::skill_names::Last)
			{
				return Skill_array[skill].second;
			}
			else

			{
				std::string(*temp)(Player* p1, Player*p2) = nullptr;
				return temp;
			}
		}
		int GetCost(int skill)
		{
			if (skill < skills::skill_names::Last)
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