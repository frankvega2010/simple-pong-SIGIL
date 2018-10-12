#include "sl.h"

void main()
{
	// set up our window and a few resources we need
	slWindow(1300, 800, "Simple! Pong", false);
	slSetFont(slLoadFont("res/fonts/calibri.ttf"), 24);
	slSetTextAlign(SL_ALIGN_CENTER);
	//int tex = slLoadTexture("png/glow.png");

	int movingplatform = 0;

	while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE))
	{

		if (slGetKey(SL_KEY_ENTER))
		{
			movingplatform = movingplatform + 5;
		}
		// background glow
		slSetForeColor(0.1, 0.9, 0.2, 0.4);
		//slSprite(tex, 200, 240, 300, 200);

		// large text and fat line
		slSetForeColor(0.0, 0.8, 0.2, 1.0);
		slSetFontSize(24);
		slText(200, 250, "SIGIL:");
		slRectangleFill(movingplatform, 240, 100, 7);

		// smaller subtext
		slSetFontSize(14);
		slText(200, 220, "Sprites, text, sound, input, and more!");
		slLine(48, 210, 352, 210);

		slRender();
	}
	slClose();
}