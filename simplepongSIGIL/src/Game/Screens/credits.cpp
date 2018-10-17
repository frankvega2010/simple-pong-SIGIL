#include "credits.h"

#include "sl.h"
//#include "raylib.h"
#include "Setup/Game.h"

namespace Juego
{
	static const int Menu = 6;

	namespace Credits_Section
	{
		static void CreditosInput()
		{
			if (slGetKey(49))
			{
				#ifdef AUDIO
								PlaySound(pong_select_menu);
				#endif
				selectOption = Menu;
				isScreenFinished = true;
			}
		}

		void UpdateCreditsScreen()
		{
			#ifdef AUDIO
			UpdateMusicStream(pong_menu_song);
			#endif
			
			CreditosInput();
		}

		void InitCreditsScreen()
		{
			isScreenFinished = false;
		}

		bool FinishCreditsScreen()
		{
			return isScreenFinished;
		}

		void DrawCredits()
		{
			slSetFontSize(defaultFontSize);
			slText(screenWidth / 3, screenHeight - 80, "Credits"); // screenHeight - 80
			slText(screenWidth / 3, screenHeight / 1.25f, "Version 1.0"); // screenHeight / 1.35f
			slText(screenWidth / 4, screenHeight / 1.5f, "Game made by"); // screenHeight / 1.5f
			slText(screenWidth / 3, screenHeight / 1.7f, "Franco Vega"); // screenHeight / 1.7f
			slText(screenWidth / 4, screenHeight / 2.3f, "Tools Used"); // screenHeight / 2.0f
			slText(screenWidth / 3, screenHeight / 3.0f, "Bfxr"); // screenHeight / 3.0f
			slText(screenWidth / 3, screenHeight / 4.0f, "Bosca Ceoil"); // screenHeight / 4.0f
			slText(screenWidth / 3, screenHeight / 6, "SIGIL"); // screenHeight / 7
			slText(10, 20, "1. Go back to Menu"); //20
		}
	}
}