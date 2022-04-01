#include <stdbool.h>

typedef enum KeyCode {
	W = 'W',
	A = 'A',
	S = 'S',
	D = 'D',
	SPACE = ' ',
	ENTER = '\n',
	ESC = 27
} EKeyCode;

void UpdateInput();

bool GetButtonDown(EKeyCode keyCode);

bool GetButtonUp(EKeyCode keyCode);

bool GetButton(EKeyCode keyCode);

