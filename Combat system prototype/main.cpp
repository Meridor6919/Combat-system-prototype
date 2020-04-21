#include <iostream>
#include "Game.h"
#include <time.h>

int main()
{
	srand(time(0));
	Game g;
	g.StartCombat(0, 1);
	std::cin.get();
}