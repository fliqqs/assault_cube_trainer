#pragma once
#include <glm/vec3.hpp>
class Player
{

public:
	char name[20];
	int base;
	int health;
	glm::vec3 position_head = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 position_feet = glm::vec3(0.0f, 0.0f, 0.0f);
	
	void Print();
	
};

