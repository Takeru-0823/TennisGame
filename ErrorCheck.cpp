#include "Prototype.h"

void errorCheck(const int IMGBG, const SOUND& SOUND)
{
	if (IMGBG == -1)
	{
		SetFontSize(30);
		DrawString(WIDTH / 2 - 60 / 2 * 21 / 2, HEIGHT / 2, "No IMGBG", RED);
	}

	if (SOUND.bgm == -1)
	{
		SetFontSize(30);
		DrawString(WIDTH / 2 - 30 / 2 * 21 / 2, HEIGHT / 2, "No BGM", RED);
	}

	if (SOUND.jin == -1)
	{
		SetFontSize(30);
		DrawString(WIDTH / 2, HEIGHT / 2, "No JIN", RED);
	}

	if (SOUND.se == -1)
	{
		SetFontSize(30);
		DrawString(WIDTH / 2 + 30 / 2 * 21 / 2, HEIGHT / 2, "No SE", RED);
	}
	
}