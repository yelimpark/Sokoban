#include "stdafx.h"
#include "Game.h"
#include "Renderer.h"
#include "input.h"

bool Initialize() {
	if (false == InitializeRenderer())
		return false;
	return true;
}

void processInput() {
	UpdateInput();
}

void update() {
	if (GetButton(W)) {
		setKeyMessage(W);
	}
	else if (GetButton(D)) {
		setKeyMessage(D);
	}
	else if (GetButton(S)) {
		setKeyMessage(S);
	}
	else if (GetButton(A)) {
		setKeyMessage(A);
	}
}

void render() {
	RenderMap();
}

int32_t Run() {
	while (true)
	{
		// 입력 처리
		processInput();
		// 업데이트
		update();
		// 렌더링
		render();
	}

	return 0;
}