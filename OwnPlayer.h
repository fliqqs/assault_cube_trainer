#pragma once
#include "Player.h"
#include <glm/vec2.hpp>
#include <glm/mat4x4.hpp>
class OwnPlayer :
    public Player
{
    public:
        glm::vec2 screen;
		float view_matrix[16];
        void Print();
        void GetInfo();
};

