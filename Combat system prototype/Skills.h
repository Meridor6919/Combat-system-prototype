#include "Constants.h"
class Player;

namespace skills {
	extern void xd1(Player *attacker, Player *target);
	extern void xd2(Player *attacker, Player *target);


	class Skills {
		void(*Skill_array[skills::skill_names::last])(Player *attacker, Player *target) = { &xd1, &xd2 };

	public:
		auto GetSkill(int skill)
		{
			if (skill < skills::skill_names::last)
			{
				return Skill_array[skill];
			}
			else

			{
				void(*temp)(Player* p1, Player*p2) = nullptr;
				return temp;
			}
		}
	};
}