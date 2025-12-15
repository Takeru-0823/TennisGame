#include "Prototype.h"

void play(BALL* ball, RACKET* racket, int* scene, int* timer, int* score, const SOUND& SOUND)
{
	// ボールの処理
	ball->x = ball->x + ball->vx;
	if (ball->x < ball->r && ball->vx < 0) ball->vx = -ball->vx;
	if (ball->x > WIDTH - ball->r && ball->vx > 0) ball->vx = -ball->vx;
	ball->y = ball->y + ball->vy;
	if (ball->y < ball->r && ball->vy < 0) ball->vy = -ball->vy;
	if (ball->y > HEIGHT)
	{
		*scene = OVER;
		*timer = 0;
		StopSoundMem(SOUND.bgm);
		PlaySoundMem(SOUND.jin, DX_PLAYTYPE_BACK);
		return;
	}
	DrawCircle(ball->x, ball->y, ball->r, RED, TRUE);
	DrawCircle(ball->x - ball->r / 4, ball->y - ball->r / 4, ball->r / 2, 0xffa0a0, TRUE);
	DrawCircle(ball->x - ball->r / 4, ball->y - ball->r / 4, ball->r / 4, 0xffffff, TRUE);

	// ラケットの処理
	if (CheckHitKey(KEY_INPUT_LEFT) == 1)
	{
		racket->x = racket->x - 10;
		if (racket->x < racket->w / 2) racket->x = racket->w / 2;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
	{
		racket->x = racket->x + 10;
		if (racket->x > WIDTH - racket->w / 2) racket->x = WIDTH - racket->w / 2;
	}
	DrawBox(racket->x - racket->w / 2 - 2, racket->y - racket->h / 2 - 2, racket->x + racket->w / 2, racket->y + racket->h / 2, 0x40c0ff, TRUE);
	DrawBox(racket->x - racket->w / 2, racket->y - racket->h / 2, racket->x + racket->w / 2 + 2, racket->y + racket->h / 2 + 2, 0x204080, TRUE);
	DrawBox(racket->x - racket->w / 2, racket->y - racket->h / 2, racket->x + racket->w / 2, racket->y + racket->h / 2, SKYBLUE, TRUE);

}