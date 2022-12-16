#pragma once

#include <vector>
#include "Players.h"
#include "Player.h"


class Players
{
	public:
	int number_of_players;
	std::vector<Player> players;
	void GetEntityAmmount();
	void GetInfo();
	void Print();
};

