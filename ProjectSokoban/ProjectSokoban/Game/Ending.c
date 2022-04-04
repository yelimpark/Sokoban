#include "stdafx.h"
#include "Ending.h"
#include "framework/input.h"

static char s_ending[MAP_SIZE][MAP_SIZE];

void LoadGameEnd()
{
	FILE* fp = NULL;
	fopen_s(&fp, "Game/Ending.txt", "r");
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

			s_ending[i][j] = ch;
		}

		if (feof(fp))
		{
			break;
		}
	}

	fclose(fp);
}

const char** GetGameEnd()
{
	return s_ending;
}

bool UpdateGameEnd()
{
	if (GetButtonDown(SPACE) || GetButtonDown(ENTER)) {
		return true;
	}
	return false;
}
