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
		attacker->GainInitiative();
		while (attacker->CanUseAbility())
		{
			report.emplace_back(attacker->UseAbility(defender));
			if (defender->IsAlive())
			{
				return CombatResult::AttackerWon;
			}
		}
		defender->GainInitiative();
		while (defender->CanUseAbility())
		{
			report.emplace_back(defender->UseAbility(attacker));
			if (attacker->IsAlive())
			{
				return CombatResult::DefenderWon;
			}
		}
	}
	return CombatResult::Draw;
}
