#include "Game.h"

Game::Game()
{
	abilities = std::make_unique<skills::Skills>();
	players[0] = std::make_unique<Player>();
	players[1] = std::make_unique<Player>();
}

bool Game::New_Round()
{
	report.push_back(abilities->TakeAction(0)(players[0].get(), players[1].get()));
	report.push_back(abilities->TakeAction(0)(players[1].get(), players[0].get()));
	return false;
}

void Game::ShowReport()
{
	for (int i = 0; i < report.size(); ++i)
	{
		std::cout << report[i] << "\n";
	}
}

bool Game::Winner()
{
	return winner;
}
