#include <stdbool.h>

typedef enum KeyCode {
	W = 'w',
	A = 'a',
	S = 's',
	D = 'd'
} EKeyCode;

void UpdateInput();

bool GetButtonDowm(EKeyCode KeyCode);

bool GetButtonUp(EKeyCode KeyCode);

bool GetButton(EKeyCode KeyCode);

