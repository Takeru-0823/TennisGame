#include "Prototype.h"

void title(BALL* ball, RACKET* racket,int* scene, int* timer, int* score, const SOUND& SOUND)
{
	SetFontSize(50);
	DrawString(WIDTH / 2 - 50 / 2 * 12 / 2, HEIGHT / 3, "Tennis Game", GREEN);

	if (*timer % 60 < 30)
	{
		SetFontSize(30);
		DrawString(WIDTH / 2 - 30 / 2 * 21 / 2, HEIGHT * 2 / 3, "Press SPACE, to start.", AQUABLUE);
	}
	if (CheckHitKey(KEY_INPUT_SPACE) == 1)
	{
		ball->x = 40;
		ball->y = 80;
		ball->vx = 5;
		ball->vy = 5;
		racket->x = WIDTH / 2;
		racket->y = HEIGHT - 50;
		*score = 0;
		*scene = PLAY;
		PlaySoundMem(SOUND.bgm, DX_PLAYTYPE_LOOP);
	}

}