#pragma once
#include "Player.h"
#include <iostream>
#include <Windows.h>
#include <vector>
#include "Skills.h"

class Game
{
	SkillRegister *skill_register;
	std::unique_ptr<Player> players[2];
	std::vector<std::string> report;
	int round = 0;
	bool winner;
public:
	Game();
	bool New_Round();
	void ShowReport();
	bool Winner();
};

