#include "Game.h"
#include <iostream>
#include <Windows.h>

#define WIDTH 50
#define HEIGHT 33

int main()
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT windowSize = { 0,0, WIDTH - 1, HEIGHT - 1 };
	COORD bufferSize = { WIDTH, HEIGHT };
	SetConsoleTitle("Our shiny new title!");
	HANDLE wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE rHnd = GetStdHandle(STD_INPUT_HANDLE);
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
	SetConsoleScreenBufferSize(wHnd, bufferSize);

	system("pause");
}