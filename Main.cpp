#include "Prototype.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	SetWindowText("テニスゲーム");
	SetGraphMode(WIDTH, HEIGHT, 32);
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1) return -1;
	SetBackgroundColor(0, 0, 0);
	SetDrawScreen(DX_SCREEN_BACK);

	const int IMGBG = LoadGraph("image/bg.png");
	const SOUND SOUND
	{
		LoadSoundMem("sound/bgm.mp3"),
		LoadSoundMem("sound/gameover.mp3"),
		LoadSoundMem("sound/hit.mp3")
	};

	int scene = TITLE;
	int timer = 0;
	int score = 0;
	int highScore = 0;

	BALL ball = { 40, 80, 5, 5, 10 };
	RACKET racket = { WIDTH / 2, HEIGHT - 50, 120, 12 };

	ChangeVolumeSoundMem(128, SOUND.bgm);
	ChangeVolumeSoundMem(128, SOUND.jin);


	while (1)
	{
		ClearDrawScreen();
		DrawGraph(0, 0, IMGBG, FALSE);
		errorCheck(IMGBG, SOUND);
		timer++;

		switch (scene)
		{
		case TITLE:
			title(&ball, &racket, &scene, &timer, &score, SOUND);
			break;

		case PLAY:
			play(&ball, &racket, &scene, &timer, &score, SOUND);
			hitCheck(&ball, racket, &score, &highScore, SOUND);
			break;

		case OVER:
			over(timer, &scene);
			break;
		}

		SetFontSize(30);
		DrawFormatString(10, 10, WHITE, "SCORE %d", score);
		DrawFormatString(WIDTH - 200, 10, YELLOW, "HI-SC %d", highScore);

		ScreenFlip();
		WaitTimer(16);
		if (ProcessMessage() == -1) break;
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) break;
	}

	DxLib_End();
	return 0;
}