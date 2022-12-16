#pragma once
#include <Windows.h>
class GDI
{
	public:
	HWND windowHandle;
	HDC windowDC;
	void DrawTextGDI(float screenx, float screeny, const char* text);
	void init();

};

