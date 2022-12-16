#include "GDI.h"
#include <iostream>
#include <Windows.h>
#include <WinUser.h>

void GDI::init()
{
	GDI::windowHandle = FindWindowA(NULL, "AssaultCube");
	GDI::windowDC = GetDC(windowHandle);
}

void GDI::DrawTextGDI(float screenx, float screeny, const char* text)
{
	SetBkMode(windowDC, TRANSPARENT);
	SetTextColor(windowDC, RGB(255, 0, 0));
	TextOutA(windowDC, screenx, screeny, text, strlen(text));
}