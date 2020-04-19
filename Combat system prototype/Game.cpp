#include "Game.h"

Game::Game()
{
	InitializePlayers();
}
std::string Game::GetReportTime()
{
	time_t t;
	char buffer[26];
	time(&t);
	
	ctime_s(buffer, 26, &t);
	for (int i = 0; i < 26; ++i)
	{
		if (buffer[i] == ' ')
		{
			buffer[i] = '_';
		}
		else if (buffer[i] == ':')
		{
			buffer[i] = '-';
		}
		else if (buffer[i] == '\n')
		{
			buffer[i] = '\0';
		}
	}
	return std::string(buffer);
}
void Game::InitializePlayers()
{
	{
		const std::vector<SkillName> move_set = { SkillName::DefaultAttack, SkillName::DefaultAttack, SkillName::DefaultBlock };
		players.emplace_back(std::make_unique<Player>("attacker", 100, 10, move_set));
	}
	{
		const std::vector<SkillName> move_set = { SkillName::DefaultBlock};
		players.emplace_back(std::make_unique<Player>("defender", 100, 20, move_set));
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
	std::ofstream report(("Reports\\" + GetReportTime() + ' ' + players[attacker_id]->GetName() + "_vs_" + players[defender_id]->GetName() + ".txt").c_str());
	for (int turn = 1; turn <= maximum_length_of_battle; ++turn)
	{
		players[attacker_id]->GainInitiative();
		while (players[attacker_id]->CanUseAbility())
		{
			report << players[attacker_id]->UseAbility(players[defender_id].get()) + '\n';
			if (!players[defender_id]->IsAlive())
			{
				report.close();
				return CombatResult::AttackerWon;
			}
		}
		players[defender_id]->GainInitiative();
		while (players[defender_id]->CanUseAbility())
		{
			report << players[defender_id]->UseAbility(players[attacker_id].get()) + '\n';
			if (!players[attacker_id]->IsAlive())
			{
				report.close();
				return CombatResult::DefenderWon;
			}
		}
	}
	report.close();
	return CombatResult::Draw;
}
