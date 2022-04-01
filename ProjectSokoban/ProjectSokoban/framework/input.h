#include <stdbool.h>

typedef enum KeyCode {
	W = 'W',
	A = 'A',
	S = 'S',
	D = 'D',
	SPACE = ' ',
	ENTER = '\n'
} EKeyCode;

void UpdateInput();

bool GetButtonDown(EKeyCode keyCode);

bool GetButtonUp(EKeyCode keyCode);

bool GetButton(EKeyCode keyCode);

