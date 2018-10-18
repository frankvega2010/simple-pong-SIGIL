#include "howtoplay.h"

#include "sl.h"
#include "Setup/Game.h"
#include "Screens\gameplay.h"

namespace Juego
{
	static const int Menu = 6;
	static const int KEY_9 = 57;

	namespace Howtoplay_Section
	{
		static void HowtoplayInput()
		{

			if (slGetKey(KEY_9))
			{
				#ifdef AUDIO
				slSoundPlay(pong_select_menu);
				#endif
				selectOption = Menu;
				isScreenFinished = true;
			}
		}

		void UpdateHowtoplayScreen()
		{
			HowtoplayInput();
		}

		void InitHowtoplayScreen()
		{
			isScreenFinished = false;
		}

		bool FinishHowtoplayScreen()
		{
			return isScreenFinished;
		}

		void DrawHowtoplay()
		{
			slSetFontSize(defaultFontSize);
			slText(screenWidth / 3, screenHeight - 80, "How to Play");
			slText(screenWidth / 8, screenHeight / 1.5f, "Player 1:");
			slText(screenWidth / 8, screenHeight / 1.7f, "W - Go Up");
			slText(screenWidth / 8, screenHeight / 2.0f, "S - Go Down");
			slText(screenWidth / 8, screenHeight / 3.0f, "Player 2:");
			slText(screenWidth / 8, screenHeight / 4.0f, "KEY_UP - Go Up");
			slText(screenWidth / 8, screenHeight / 6, "KEY_DOWN - Go Down");
			slText(screenWidth / 1.7, screenHeight / 2.5, "Score Limit = 5"); 
			slText(10, 20, "9. Go back to Menu");
		}
	}
}
