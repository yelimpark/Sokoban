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
/// 스테이지를 로딩한다.
///</summary>
void LoadStage(EStageLevel level);

/// <summary>
/// 스테이지를 업데이트한다.
/// </summary>
bool UpdateStage();


///<summary>
/// 맵을 반환한다.
///</summary>
const char** GetMap();

///<summary>
/// 게임이 끝났는지 검사한다.
///</summary>
bool IsClear();