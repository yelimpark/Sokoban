#include "stdafx.h"
#include "Stage.h"
#include "framework/input.h"

static char s_map[MAP_SIZE][MAP_SIZE];
static int32_t s_goalCount = 0;
static int32_t s_boxOnGoalCount = 0;
static int32_t s_playerX = 0;
static int32_t s_playerY = 0;

bool parseMapType(int i, int j, char mapType)
{
	switch (mapType)
	{
	case '\n':
		return false;

	case 'P':
		s_playerY = i;
		s_playerX = j;
		s_map[i][j] = mapType;
		break;

	case 'O':
		s_goalCount++;
		s_map[i][j] = mapType;
		break;

	default :
		s_map[i][j] = mapType;
	}
	return true;
}

void clearStage()
{
	memset(s_map, ' ', sizeof(s_map));
	for (size_t i = 0; i < MAP_SIZE; ++i)
	{
		s_map[i][MAP_SIZE - 1] = '\0';
	}
	s_goalCount = 0;
	s_boxOnGoalCount = 0;
	s_playerX = 0;
	s_playerY = 0;
}

void LoadStage(EStageLevel level)
{
	assert(STAGE_01 <= level && level < STAGE_MAX);

	static char path[MAX_PATH] = { 0 };
	sprintf_s(path, sizeof(path), "Stage/Stage%02d.txt", (int32_t)level);

	FILE* fp = NULL;
	fopen_s(&fp, path, "r");
	assert(fp != NULL);

	clearStage();

	for (size_t i = 0; i < MAP_SIZE; ++i)
	{
		for (size_t j = 0; j < MAP_SIZE; ++j)
		{
			char ch = fgetc(fp);

			if (false == parseMapType(i, j, ch))
			{
				break;
			}
		}

		if (feof(fp))
		{
			break;
		}
	}

	fclose(fp);
}

void UpdatePos(int x, int y) {
	s_map[s_playerY][s_playerX] = MAPTYPE_PATH;
	s_playerX += x;
	s_playerY += y;
	s_map[s_playerY][s_playerX] = MAPTYPE_PLAYER;
}

void Move(int x, int y) {
	if (s_map[s_playerY + y][s_playerX + x] == MAPTYPE_WALL || 
		s_map[s_playerY + y][s_playerX + x] == MAPTYPE_GOAL) {
		return;
	}

	if (s_map[s_playerY + y][s_playerX + x] == MAPTYPE_BOX) {
		if (s_map[s_playerY + y*2][s_playerX + x*2] != MAPTYPE_WALL) {
			s_map[s_playerY + y][s_playerX + x] = MAPTYPE_PATH;
			if (s_map[s_playerY + y*2][s_playerX + x*2] == MAPTYPE_GOAL) {
				s_map[s_playerY + y*2][s_playerX + x*2] = MAPTYPE_BOX_ON_GOAL;
				s_boxOnGoalCount++;
			}
			else {
				s_map[s_playerY + y*2][s_playerX + x*2] = MAPTYPE_BOX;
			}
			UpdatePos(x, y);
		}
	}
	else {
		UpdatePos(x, y);
	}
}

bool UpdateStage()
{
	if (GetButtonDown(W)) {
		Move(0, -1);
	}
	else if (GetButtonDown(D)) {
		Move(1, 0);
	}
	else if (GetButtonDown(S)) {
		Move(0, 1);
	}
	else if (GetButtonDown(A)) {
		Move(-1, 0);
	}
	else if (GetButtonDown(ESC)) {
		return true;
	}
	return false;
}

bool IsClear() {
	if (s_boxOnGoalCount == s_goalCount) {
		return true;
	}
	return false;
}

const char** GetMap()
{
	return s_map;
}