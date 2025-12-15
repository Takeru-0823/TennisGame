#pragma once
#include "DxLib.h"
#include <stdlib.h>

const int WIDTH = 960, HEIGHT = 640;
const int SKYBLUE = 0x0080ff;
const int GREEN = 0x00ff00;
const int AQUABLUE = 0x00ffff;
const int RED = 0xff0000;
const int YELLOW = 0xffff00;
const int WHITE = 0xffffff;

struct BALL
{
	int x;
	int y;
	int vx;
	int vy;
	int r;
};

struct RACKET
{
	int x;
	int y;
	int w;
	int h;
};

struct SOUND
{
	int bgm;
	int jin;
	int se;
};


enum
{
	TITLE,
	PLAY,
	OVER
};

void title(BALL* ball, RACKET* racket, int* scene, int* timer, int* score, const SOUND& SOUND);
void play(BALL* ball, RACKET* racket, int* scene, int* timer, int* score, const SOUND& SOUND);
void hitCheck(BALL* ball, const RACKET& RACKET, int* score, int* highScore, const SOUND& SOUND);
void over(int timer, int* scene);
void errorCheck(const int IMGBG, const SOUND& SOUND);