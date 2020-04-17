#pragma once
#include "Player.h"
#include <iostream>
#include <Windows.h>
#include <vector>
#include "Skills.h"
using namespace Combat;
using namespace Skills;

class Game
{
	std::vector<std::unique_ptr<Player>> players = {};
	std::vector<std::string> report = {};
public:
	Game() {};
	void InitializePlayers();
	CombatResult StartCombat(Player *attacker, Player *defender);
};

