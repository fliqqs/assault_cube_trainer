#include "Player.h"
#include <iostream>

void Player::Print()
{
	std::cout << "x:" << position_feet.x << " y:" << position_feet.y << " z:" << position_feet.z << "\n";
}