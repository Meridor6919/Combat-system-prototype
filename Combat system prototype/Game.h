#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <time.h>
#include "Skills.h"
#include "Player.h"
using namespace Combat;
using namespace Skills;

class Game
{
	std::vector<std::unique_ptr<Player>> players = {};
	std::string GetReportTime();
	void InitializePlayers();

public:
	Game();
	CombatResult StartCombat(unsigned int attacker_id, unsigned int defender_id);
};

