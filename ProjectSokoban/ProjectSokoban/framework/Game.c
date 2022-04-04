#include "stdafx.h"
#include "Game.h"
#include "Renderer.h"
#include "input.h"
#include "Time.h"
#include "Game/Stage.h"
#include "Game/Loby.h"
#include "Game/Menu.h"
#include "Game/Ending.h"

static EGameStatus gameStatus = LOBY;
static EStageLevel gameStage = STAGE_01;
static bool isExit = false;

bool Initialize() {
	if (false == InitializeRenderer())
		return false;

	InitializeTimer();

	LoadLoby();
	LoadStageMenu();
	LoadGameEnd();
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
	else if (gameStatus == END) {
		if (UpdateGameEnd())
			isExit = true;
	}
	else {
		if (UpdateStage()) {
			clearStage();
			gameStatus = MENU;
		}
	}
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
		if (isExit) break;
		
		if (IsClear() == true) {
			clearStage();

			gameStage++;
			if (gameStage == STAGE_MAX) {
				gameStatus = END;
			}
			else {
				LoadStage(gameStage);
			}
		}
	}

	return 0;
}