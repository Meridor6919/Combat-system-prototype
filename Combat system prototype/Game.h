#pragma once
#include "Player.h"
#include <iostream>
#include <Windows.h>
#include "Skills.h"

class Game
{
	std::unique_ptr<Player> players[2];
	std::unique_ptr<skills::Skills> abilities;
	int round = 0;
	bool winner;
public:
	Game();
	bool New_Round();
	bool Winner();
};

