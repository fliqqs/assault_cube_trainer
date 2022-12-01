#pragma once
#include "Player.h"
#include <glm/vec2.hpp>
#include <glm/mat4x4.hpp>
class OwnPlayer :
    public Player
{
    public:
        glm::vec2 screen;
        //glm::mat4 view_matrix = glm::mat4x4(0.0f);
		float view_matrix[16];


        void Print();
        void GetInfo();
};

