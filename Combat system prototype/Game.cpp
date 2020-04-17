#include "Game.h"

void Game::InitializePlayers()
{
	//player initialization
}
CombatResult Game::StartCombat(Player *attacker, Player *defender)
{
	SkillRegister *skill_register = SkillRegister::GetSkills();
	const int maximum_lenth_of_battle = 100;

	for (int turn = 1; turn <= maximum_lenth_of_battle; ++turn)
	{
		report.emplace_back(attacker->UseAbility(turn, defender));
		if (defender->current_hp <= 0)
		{
			return CombatResult::AttackerWon;
		}
		report.emplace_back(defender->UseAbility(turn, attacker));
		if (attacker->current_hp <= 0)
		{
			return CombatResult::DefenderWon;
		}
	}
	return CombatResult::Draw;
}
