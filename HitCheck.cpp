#include "Prototype.h"

void hitCheck(BALL* ball, const RACKET& RACKET, int* score, int* highScore, const SOUND& SOUND)
{
	static int dx = 0;
	static int dy = 0;

	dx = ball->x - RACKET.x;
	dy = ball->y - RACKET.y;
	if (-RACKET.w / 2 - 10 < dx && dx < RACKET.w / 2 + 10 && -20 < dy && dy < 0)
	{
		ball->vy = -5 - rand() % 5;
		*score = *score + 100;
		if (*score > *highScore) *highScore = *score;
		PlaySoundMem(SOUND.se, DX_PLAYTYPE_BACK);
	}

}