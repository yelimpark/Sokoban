#include "stdafx.h"
#include "Game.h"
#include "Renderer.h"
#include "input.h"
#include "Time.h"

bool Initialize() {
	if (false == InitializeRenderer())
		return false;
	return true;
}

void processInput() {
	UpdateInput();
}

static float sum = 0;

void update() {
	// 0.5초 간격으로 특정 메세지 깜박이기
	float timeSpace = 2;
	sum += GetDeltaTime();
	if (sum > timeSpace) {
		sum = 0;
		setMessage("짜잔");
	}
	//Sleep(1);
}

void render() {
	RenderMap();
}

int32_t Run() {
	while (true)
	{
		UpdateTimer();
		processInput();
		update();
		render();
	}

	return 0;
}