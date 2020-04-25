#include <iostream>
#include "Game.h"
#include <time.h>

int main()
{
	srand(time(0));
	Game g;
	for (int i = 0; i < 30; ++i)
	{
		g.StartCombat(0, 1);
		Sleep(1000);
	}
	std::cin.get();
}