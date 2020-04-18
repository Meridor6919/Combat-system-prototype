#include "Game.h"

Game::Game()
{
	InitializePlayers();
}
void Game::InitializePlayers()
{
	{
		const std::vector<SkillName> move_set = { SkillName::DefaultAttack, SkillName::DefaultAttack, SkillName::DefaultBlock };
		players.emplace_back(std::make_unique<Player>(100, 10, move_set));
	}
	{
		const std::vector<SkillName> move_set = { SkillName::DefaultBlock};
		players.emplace_back(std::make_unique<Player>(100, 20, move_set));
	}
}
CombatResult Game::StartCombat(unsigned int attacker_id, unsigned int defender_id)
{
	SkillRegister *skill_register = SkillRegister::GetSkills();

	if ((attacker_id | defender_id) >= static_cast<int>(players.size())) 
	{
		MessageBox(0, ErrorMsg::invalid_id.c_str(), ErrorTitle::invalid_id.c_str(), 0);
		exit(-1);
	}
	for (int turn = 1; turn <= maximum_length_of_battle; ++turn)
	{
		players[attacker_id]->GainInitiative();
		while (players[attacker_id]->CanUseAbility())
		{
			report.emplace_back(players[attacker_id]->UseAbility(players[defender_id].get()));
			if (!players[defender_id]->IsAlive())
			{
				return CombatResult::AttackerWon;
			}
		}
		players[defender_id]->GainInitiative();
		while (players[defender_id]->CanUseAbility())
		{
			report.emplace_back(players[defender_id]->UseAbility(players[attacker_id].get()));
			if (!players[attacker_id]->IsAlive())
			{
				return CombatResult::DefenderWon;
			}
		}
	}
	return CombatResult::Draw;
}
