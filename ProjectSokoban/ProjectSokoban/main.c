#include "stdafx.h"
#include "Framework/Game.h"

int main() {
	if (false == Initialize()) {
		puts("�ʱ�ȭ�� ����");
	}
	while (1) {
		Run();
	}
}