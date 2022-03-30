#include "stdafx.h"
#include "Renderer.h";

#define MAP_SIZE 24

static char s_map[MAP_SIZE][MAP_SIZE] = {
	"****************",
	"* Sokoban      *",
	"****************"
};

static HANDLE s_consolHandle;

bool InitializeRenderer() {
	s_consolHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	if (INVALID_HANDLE_VALUE == s_consolHandle) {
		return false;
	}

	return true;
}

void RenderMap() {
	const static COORD initalPos = { 0, 0 };
	const static CONSOLE_CURSOR_INFO info = { 100, false };

	SetConsoleCursorPosition(s_consolHandle, initalPos);
	SetConsoleCursorInfo(s_consolHandle, &info);

	for (int i = 0; i < MAP_SIZE; i++) {
		puts(s_map[i]);
	}
}