#pragma once

#include <stdint.h>

typedef enum MapType
{
	MAPTYPE_WALL = '#',
	MAPTYPE_PLAYER = 'P',
	MAPTYPE_BOX = 'B',
	MAPTYPE_GOAL = 'O',
	MAPTYPE_BOX_ON_GOAL = '@',
	MAPTYPE_PATH = ' '
} EMapType;

typedef enum StageLevel
{
	STAGE_01 = 1,
	STAGE_02,
	STAGE_03,
	STAGE_04,
	STAGE_05,
	STAGE_MAX
} EStageLevel;

///<summary>
/// ���������� �ε��Ѵ�.
///</summary>
void LoadStage(EStageLevel level);

/// <summary>
/// ���������� ������Ʈ�Ѵ�.
/// </summary>
bool UpdateStage();


///<summary>
/// ���� ��ȯ�Ѵ�.
///</summary>
const char** GetMap();

///<summary>
/// ������ �������� �˻��Ѵ�.
///</summary>
bool IsClear();