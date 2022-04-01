#include "stdafx.h"
#include "Renderer.h";
#include "Game/Stage.h"
#include "Game/Loby.h"

static char s_map[MAP_SIZE][MAP_SIZE];
static HANDLE s_consolHandle;

void clear() {
	memset(s_map, ' ', sizeof(s_map));

	for (size_t i = 0; i < MAP_SIZE; i++) {
		s_map[i][MAP_SIZE - 1] = '\0';
	}
}

bool InitializeRenderer() {
	s_consolHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	if (INVALID_HANDLE_VALUE == s_consolHandle) {
		return false;
	}

	return true;
}

void RenderMap(EGameStatus gameStatus) {
	const static COORD initialPos = { 0, 0 };
	const static CONSOLE_CURSOR_INFO info = { 100, false };

	SetConsoleCursorPosition(s_consolHandle, initialPos);
	SetConsoleCursorInfo(s_consolHandle, &info);

	const char** screen = {""};

	if (gameStatus == LOBY) {
		screen = GetLoby();
	}
	else if (gameStatus == MENU) {

	}
	else {
		screen = GetMap();
	}
	memcpy(s_map, screen, sizeof(s_map));


	for (size_t i = 0; i < MAP_SIZE; i++) {
		puts(s_map[i]);
	}

	clear();
}