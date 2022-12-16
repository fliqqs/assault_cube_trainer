#include "ESP.h"
#include <iostream>
#include <glm/vec4.hpp>
#include "glm/gtx/string_cast.hpp"

bool ESP::WorldToScreen(glm::vec3 position, float& screenx, float& screeny, float matrix[16], int windowWidth, int windowHeight)
{
	glm::vec4 clipCoords = { 0, 0, 0, 0 };
	clipCoords.x = position.x * matrix[0] + position.y * matrix[4] + position.z * matrix[8] + matrix[12];
	clipCoords.y = position.x * matrix[1] + position.y * matrix[5] + position.z * matrix[9] + matrix[13];
	clipCoords.z = position.x * matrix[2] + position.y * matrix[6] + position.z * matrix[10] + matrix[14];
	clipCoords.w = position.x * matrix[3] + position.y * matrix[7] + position.z * matrix[11] + matrix[15];
	
	if (clipCoords.w < 0.1f)
		return false;

	glm::vec3 NDC;
	NDC.x = clipCoords.x / clipCoords.w;
	NDC.y = clipCoords.y / clipCoords.w;
	NDC.z = clipCoords.z / clipCoords.w;
	
	screenx = (windowWidth / 2 * NDC.x ) + (NDC.x + windowWidth / 2);
	screeny = -(windowHeight / 2 * NDC.y) + (NDC.y + windowHeight / 2);
	
	return true;
}
