#include <iostream>
#include "Game.h"

int main()
{
	Game g;
	while (g.New_Round());
	std::cout << "Wygral gracz " << static_cast<int>(g.Winner()+1);
	std::cin.get();
}