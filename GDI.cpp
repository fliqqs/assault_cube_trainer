#include "GDI.h"
#include <iostream>
#include <Windows.h>
#include <WinUser.h>

void GDI::DrawTextGDI(float screenx, float screeny, const char* text)
{

	auto windowHandle = FindWindowA(NULL, "AssaultCube");
	auto windowDC = GetDC(windowHandle);

	SetBkMode(windowDC, TRANSPARENT);
	SetTextColor(windowDC, RGB(255, 255, 255));
	TextOutA(windowDC, screenx, screeny, text, strlen(text));
}