#include "stdafx.h"
#include "Loby.h"
#include "framework/input.h"

static char s_loby[MAP_SIZE][MAP_SIZE];

void LoadLoby()
{
	FILE* fp = NULL;
	fopen_s(&fp, "Game/Loby.txt", "r");
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

			s_loby[i][j] = ch;
		}

		if (feof(fp))
		{
			break;
		}
	}

	fclose(fp);
}

const char** GetLoby()
{
	return s_loby;
}

bool UpdateLoby() {
	if (GetButtonDown(SPACE) || GetButtonDown(ENTER)) {
		return true;
	}
	return false;
}