#include "stdafx.h"
#include "Framework/Game.h"

int main() {
	if (false == Initialize()) {
		puts("초기화에 실패");
	}
	while (1) {
		Run();
	}
}