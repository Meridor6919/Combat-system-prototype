#include "Game.h"

Game::Game()
{
	players[0] = std::make_unique<Player>();
	players[1] = std::make_unique<Player>();
	skill_register = SkillRegister::GetSkills();
}

bool Game::New_Round()
{
	report.push_back(skill_register->TakeAction(skill_names::DefaultAttack)(players[0].get(), players[1].get()));
	report.push_back(skill_register->TakeAction(skill_names::DefaultAttack)(players[1].get(), players[0].get()));
	return false;
}

void Game::ShowReport()
{
	for (int i = 0; i < static_cast<int>(report.size()); ++i)
	{
		std::cout << report[i] << "\n";
	}
}

bool Game::Winner()
{
	return winner;
}
