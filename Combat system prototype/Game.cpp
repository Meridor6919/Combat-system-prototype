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
		const std::vector<SkillName> move_set = { SkillName::DefaultAttack, SkillName::DefaultAttack, SkillName::BleedingStrike };
		players.emplace_back(std::make_unique<Player>("attacker", 100, 50, move_set));
	}
	{
		const std::vector<SkillName> move_set = { SkillName::BleedingStrike, SkillName::WeakeningStrike,  SkillName::BleedingStrike,  SkillName::BleedingStrike};
		players.emplace_back(std::make_unique<Player>("defender", 100, 50, move_set));
	}
}
void Game::ResetPlayers(unsigned int attacker_id, unsigned int defender_id)
{
	players[attacker_id]->Reset();
	players[defender_id]->Reset();
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
		report.emplace_back("Turn " + std::to_string(turn) + '\n');
		players[attacker_id]->GainInitiative();
		while (players[attacker_id]->CanUseAbility())
		{
			report.emplace_back('\t' + players[attacker_id]->UseAbility(players[defender_id].get()) + '\n');
			if (!players[defender_id]->IsAlive())
			{
				report.emplace_back(players[attacker_id]->GetName() + " won");
				Save_Report(players[attacker_id]->GetName(), players[defender_id]->GetName());
				ResetPlayers(attacker_id, defender_id);
				return CombatResult::AttackerWon;
			}
		}
		report.emplace_back(players[attacker_id]->EndOfTurn());
		players[defender_id]->GainInitiative();
		while (players[defender_id]->CanUseAbility())
		{
			report.emplace_back('\t' + players[defender_id]->UseAbility(players[attacker_id].get()) + '\n');
			if (!players[attacker_id]->IsAlive())
			{
				report.emplace_back(players[defender_id]->GetName() + " won");
				Save_Report(players[attacker_id]->GetName(), players[defender_id]->GetName());
				ResetPlayers(attacker_id, defender_id);
				return CombatResult::DefenderWon;
			}
		}
		report.emplace_back(players[defender_id]->EndOfTurn());
	}
	report.emplace_back("Draw");
	Save_Report(players[attacker_id]->GetName(), players[defender_id]->GetName());
	ResetPlayers(attacker_id, defender_id);
	return CombatResult::Draw;
}

void Game::Save_Report(std::string attacker_name, std::string defender_name)
{
	std::ofstream stream_report(("Reports\\" + GetReportTime() + ' ' + attacker_name + "_vs_" + defender_name + ".txt").c_str());
	for (int i = 0; i < static_cast<int>(report.size()); ++i)
	{
		stream_report << report[i];
	}
	stream_report.close();
	report.clear();
}
