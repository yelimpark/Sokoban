#include "stdafx.h"
#include "Game.h"
#include "Renderer.h"
#include "input.h"
#include "Time.h"
#include "Game/Stage.h"

static EGameStatus gameStatus = LOBY;

bool Initialize() {
	if (false == InitializeRenderer())
		return false;

	InitializeTimer();

	LoadLoby();
	LoadStage(STAGE_01);

	return true;
}

void processInput() {
	UpdateInput();
}

void update() {
	if (gameStatus == LOBY) {
		if (UpdateLoby())
			gameStatus = STAGE;
	}
	else if (gameStatus == MENU)
		gameStatus = STAGE;
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
			LoadStage(STAGE_01);
			gameStatus = LOBY;
		}
	}

	return 0;
}