#include "stdafx.h"
#include "Menu.h"
#include "framework/input.h"

static char s_menu[MAP_SIZE][MAP_SIZE];
static int32_t cursorX = 0;
static int32_t cursorY = 0;

void LoadStageMenu()
{
	FILE* fp = NULL;
	fopen_s(&fp, "Game/Menu.txt", "r");
	assert(fp != NULL);

	for (size_t i = 0; i < MAP_SIZE; ++i)
	{
		for (size_t j = 0; j < MAP_SIZE; ++j)
		{
			char ch = fgetc(fp);

			if (ch == '\n')
			{
				break;
			}
			else if (ch == '*') {
				cursorX = j;
				cursorY = i;
			}

			s_menu[i][j] = ch;
		}

		if (feof(fp))
		{
			break;
		}
	}

	fclose(fp);
}

const char** GetStageMenu()
{
	return s_menu;
}

void MoveCursor(int x, int y) {
	if (s_menu[cursorY + y][cursorX] == '#')
		return;

	s_menu[cursorY][cursorX] = ' ';
	cursorY += y;
	s_menu[cursorY][cursorX] = '*';
}

bool UpdateStageMenu(EStageLevel* stage)
{
	if (GetButtonDown(W)) {
		MoveCursor(0, -1);
	}
	else if (GetButtonDown(D)) {
		
	}
	else if (GetButtonDown(S)) {
		MoveCursor(0, 1);
	}
	else if (GetButtonDown(A)) {
		
	}
	else if (GetButtonDown(SPACE) || GetButtonDown(ENTER)) {
		*stage = cursorY;
		return true;
	}
	return false;
}
