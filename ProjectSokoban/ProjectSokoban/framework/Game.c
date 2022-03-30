#include "stdafx.h"
#include "Game.h"
#include "Renderer.h"

bool Initialize() {
	if (false == InitializeRenderer())
		return false;
	return true;
}

void processInput() {

}

void update() {

}

void render() {
	RenderMap();
}

int32_t Run() {
	render();
}