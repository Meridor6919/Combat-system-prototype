#pragma once
#include <string>
namespace Skills {
	enum SkillName {
		DefaultAttack,
		BleedingStrike,
		WeakeningStrike,
		Last
	};
}
namespace Combat {
	enum CombatResult {
		AttackerWon,
		DefenderWon,
		Draw,
		Last
	};
	const int maximum_length_of_battle = 100;
}
namespace Effects
{
	enum Effect {
		Weakness,
		Bleeding,
		Last
	};
}
namespace ErrorMsg
{
	const std::string invalid_id = "id param exceeds vector of players";
}
namespace ErrorTitle
{
	const std::string invalid_id = "ID error";
}
