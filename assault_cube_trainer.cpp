// assault_cube_trainer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Memory.h"
#include "Players.h"
#include "OwnPlayer.h"
#include "glm/gtx/string_cast.hpp"
#include "ESP.h"
#include "GDI.h"

using namespace std;

void drawESP(Players& player_entites, OwnPlayer& self)
{
	GDI g;
	ESP esp;
	

	for (int i = 1; i < player_entites.number_of_players; i++)
	{
		float x, y;
		if (esp.WorldToScreen(player_entites.players[i].position_feet, x, y, self.view_matrix, 1024, 768))
		{

			g.DrawTextGDI(x, y, "player");
		}
	}
}

int main()
{

	Memory::openProccess("AssaultCube");

	Players player_entities;
	player_entities.GetEntityAmmount();
	player_entities.GetInfo();
	player_entities.Print();
	
	OwnPlayer self;
	self.GetInfo();
	std::cout << sizeof(self.view_matrix);

	while (true)
	{
		self.GetInfo();
		//std::cout << glm::to_string(self.view_matrix) << std::endl;
		//std::cout << self.view_matrix[0] << std::endl;
		
		player_entities.GetInfo();
		//player_entities.players[1].Print();

		drawESP(player_entities, self);


		
	}
	
	//https://www.youtube.com/watch?v=ih20l3pJoeU
	//https://en.wikipedia.org/wiki/3D_projection
}
