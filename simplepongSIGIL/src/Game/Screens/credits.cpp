#include "credits.h"

#include "sl.h"
#include "Setup/Game.h"

namespace Juego
{
	static const int Menu = 6;

	namespace Credits_Section
	{
		static void CreditosInput()
		{
			if (slGetKey(57))
			{
				#ifdef AUDIO
				slSoundPlay(pong_select_menu);
				#endif
				selectOption = Menu;
				isScreenFinished = true;
			}
		}

		void UpdateCreditsScreen()
		{		
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
			slText(screenWidth / 3, screenHeight - 80, "Credits");
			slText(screenWidth / 3, screenHeight / 1.25f, "Version 1.0");
			slText(screenWidth / 4, screenHeight / 1.5f, "Game made by");
			slText(screenWidth / 3, screenHeight / 1.7f, "Franco Vega");
			slText(screenWidth / 4, screenHeight / 2.3f, "Tools Used");
			slText(screenWidth / 3, screenHeight / 3.0f, "Bfxr");
			slText(screenWidth / 3, screenHeight / 4.0f, "Bosca Ceoil");
			slText(screenWidth / 3, screenHeight / 6, "SIGIL");

			slText(screenWidth / 1.85, screenHeight / 2.3f, "Font 'Forced Square'");
			slText(screenWidth / 1.5, screenHeight / 2.65f, "made by");
			slSetFontSize(defaultFontSize/1.5);
			slText(screenWidth / 1.65, screenHeight / 3.0f, "www.drawperfect.com");

			slSetFontSize(defaultFontSize);
			slText(10, 20, "9. Go back to Menu"); 
		}
	}
}