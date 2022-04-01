#pragma once
#include <stdbool.h>
#include "Game/Stage.h"

void LoadStageMenu();

const char** GetStageMenu();

bool UpdateStageMenu(EStageLevel * stage);