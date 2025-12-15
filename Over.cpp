#include "Prototype.h"

void over(int timer, int* scene)
{
	SetFontSize(40);
	DrawString(WIDTH / 2 - 40 / 2 * 9 / 2, HEIGHT / 3, "GAME OVER", RED);
	if (timer > 60 * 5) *scene = TITLE;
}