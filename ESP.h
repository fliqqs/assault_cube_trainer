#pragma once
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
class ESP
{
	public:
		int screenWidth;
		int screenHeight;
		
		bool WorldToScreen(glm::vec3 position, float& screenx, float& screeny,float matrix[16], int windowHeight, int windowWidth);
};

