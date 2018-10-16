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
			slText(screenWidth / 3, 20, "Credits");
			slText(screenWidth / 3, screenHeight / 7, "Version 1.0");
			slText(screenWidth / 4, screenHeight / 4.0f, "Game made by");
			slText(screenWidth / 3, screenHeight / 3.0f, "Franco Vega");
			slText(screenWidth / 4, screenHeight / 2.0f, "Tools Used");
			slText(screenWidth / 3, screenHeight / 1.7f, "Bfxr");
			slText(screenWidth / 3, screenHeight / 1.5f, "Bosca Ceoil");
			slText(screenWidth / 3, screenHeight / 1.35f, "SIGIL");
			slText(10, screenHeight - 80, "1. Go back to Menu");

			//DrawText(FormatText("Credits"), screenWidth / 3, 20, defaultFontSize, WHITE);
			//DrawText(FormatText("Version 1.0"), screenWidth / 3, screenHeight / 7, defaultFontSize, WHITE);
			//DrawText(FormatText("Game made by"), screenWidth / 4, screenHeight / 4.0f, defaultFontSize, WHITE);
			//DrawText(FormatText("Franco Vega"), screenWidth / 3, screenHeight / 3.0f, defaultFontSize, WHITE);
			//DrawText(FormatText("Tools Used"), screenWidth / 4, screenHeight / 2.0f, defaultFontSize, WHITE);
			//DrawText(FormatText("Bfxr"), screenWidth / 3, screenHeight / 1.7f, defaultFontSize, WHITE);
			//DrawText(FormatText("Bosca Ceoil"), screenWidth / 3, screenHeight / 1.5f, defaultFontSize, WHITE);
			//DrawText(FormatText("Raylib"), screenWidth / 3, screenHeight / 1.35f, defaultFontSize, WHITE);
			//DrawText(FormatText("1. Go back to Menu"), 10, screenHeight - 80, defaultFontSize, WHITE);
		}
	}
}