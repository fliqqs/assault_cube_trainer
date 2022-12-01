#include "Players.h"
#include <vector>
#include "Offsets.h"
#include "Memory.h"
#include <iostream>


void Players::GetEntityAmmount()
{
	number_of_players = Memory::Read<int>(players_in_map);
}

void Players::GetInfo()
{
	players.resize(number_of_players);
	for (int i = 1; i < number_of_players; i++)
	{
		players[i].base = Memory::Read<uintptr_t>(entity_base);
		players[i].base = Memory::Read<uintptr_t>(players[i].base + (0x4 * i));
		players[i].health = Memory::Read<int>(players[i].base + of_health);
		//players[i].name = Memory::Read<char *>(players[i].base + of_name);
		ReadProcessMemory(Memory::current_handle(), (PBYTE*)(players[i].base + of_name), &players[i].name, sizeof(players[i].name), nullptr);
		players[i].position_head.x = Memory::Read<float>(players[i].base + of_posx);
		players[i].position_head.y = Memory::Read<float>(players[i].base + of_posy);
		players[i].position_head.z = Memory::Read<float>(players[i].base + of_posz);

		players[i].position_feet.x = Memory::Read<float>(players[i].base + of_posx_normal);
		players[i].position_feet.y = Memory::Read<float>(players[i].base + of_posy_normal);
		players[i].position_feet.z = Memory::Read<float>(players[i].base + of_posz_normal);
	}
}

void Players::Print()
{
	for (int i = 1; i < number_of_players; i++)
	{
		std::cout << "Player " << i << " name: " << players[i].name << std::endl;
		std::cout << "Player " << i << " health: " << players[i].health << std::endl;
		std::cout << "Player " << i << " position_head: " << players[i].position_head.x << " " << players[i].position_head.y << " " << players[i].position_head.z << std::endl;
		std::cout << "Player " << i << " position_normal: " << players[i].position_feet.x << " " << players[i].position_feet.y << " " << players[i].position_feet.z << std::endl;
	}
}