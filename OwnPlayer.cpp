#include "OwnPlayer.h"
#include "Offsets.h"
#include "Memory.h"

void OwnPlayer::GetInfo()
{
	base = Memory::Read<uintptr_t>(player_base);
	health = Memory::Read<int>(base + of_health);
	ReadProcessMemory(Memory::current_handle(), (PBYTE*)(base + of_name), &name, sizeof(name), nullptr);
	position_head.x = Memory::Read<float>(base + of_posx);
	position_head.y = Memory::Read<float>(base + of_posy);
	position_head.z = Memory::Read<float>(base + of_posz);

	position_feet.x = Memory::Read<float>(base + of_posx_normal);
	position_feet.y = Memory::Read<float>(base + of_posy_normal);
	position_feet.z = Memory::Read<float>(base + of_posz_normal);
	ReadProcessMemory(Memory::current_handle(), (PBYTE*)(of_viewmatrix), &view_matrix, sizeof(view_matrix), nullptr);
}