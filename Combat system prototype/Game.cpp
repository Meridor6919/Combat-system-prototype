#include "Game.h"

Game::Game()
{
	abilities = std::make_unique<skills::Skills>();
	players[0] = std::make_unique<Player>();
	players[1] = std::make_unique<Player>();
}

bool Game::New_Round()
{
	abilities->GetSkill(0)(players[0].get(), players[1].get());
	abilities->GetSkill(1)(players[0].get(), players[1].get());
	return false;
}

bool Game::Winner()
{
	return winner;
}
