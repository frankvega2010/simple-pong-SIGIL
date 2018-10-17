#include "howtoplay.h"

#include "sl.h"
#include "Setup/Game.h"
#include "Screens\gameplay.h"

namespace Juego
{
	static const int Menu = 6;

	namespace Howtoplay_Section
	{
		static void HowtoplayInput()
		{

			if (slGetKey(57))
			{
				#ifdef AUDIO
				PlaySound(pong_select_menu);
				#endif
				selectOption = Menu;
				isScreenFinished = true;
			}
		}

		void UpdateHowtoplayScreen()
		{
			#ifdef AUDIO
			UpdateMusicStream(pong_menu_song);
			#endif

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
			slText(screenWidth / 8, screenHeight / 1.5f, "Player 1:"); //  screenHeight / 1.5f
			slText(screenWidth / 8, screenHeight / 1.7f, "W - Go Up");//  screenHeight / 1.7f
			slText(screenWidth / 8, screenHeight / 2.0f, "S - Go Down");// screenHeight / 2.0f
			slText(screenWidth / 8, screenHeight / 3.0f, "Player 2:");// screenHeight / 3.0f
			slText(screenWidth / 8, screenHeight / 4.0f, "KEY_UP - Go Up");// screenHeight / 4.0f
			slText(screenWidth / 8, screenHeight / 6, "KEY_DOWN - Go Down");// screenHeight / 6
			slText(screenWidth / 1.7, screenHeight / 2.5, "Score Limit = 5");// 
			slText(10, 20, "9. Go back to Menu");
		}
	}
}
