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
		// �Է� ó��
		processInput();
		// ������Ʈ
		update();
		// ������
		render();
	}

	return 0;
}