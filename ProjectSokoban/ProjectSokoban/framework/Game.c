#include "stdafx.h"
#include "Game.h"
#include "Renderer.h"
#include "input.h"
#include "Time.h"
#include "Game/Stage.h"
#include "Game/Loby.h"
#include "Game/Menu.h"

static EGameStatus gameStatus = LOBY;
static EStageLevel gameStage = STAGE_01;

bool Initialize() {
	if (false == InitializeRenderer())
		return false;

	InitializeTimer();

	LoadLoby();
	LoadStageMenu();
	LoadStage(gameStage);

	return true;
}

void processInput() {
	UpdateInput();
}

void update() {
	if (gameStatus == LOBY) {
		if (UpdateLoby())
			gameStatus = MENU;
	}
	else if (gameStatus == MENU) {
		if (UpdateStageMenu(&gameStage)) {
			LoadStage(gameStage);
			gameStatus = STAGE;
		}
	}
	else
		UpdateStage();
}

void render() {
	RenderMap(gameStatus);
}

int32_t Run() {
	while (true)
	{
		UpdateTimer();
		processInput();
		update();
		render();
		if (IsClear() == true) {
			clearStage();

			gameStage++;
			if (gameStage == STAGE_MAX) {
				break;
			}
			LoadStage(gameStage);
		}
	}

	return 0;
}