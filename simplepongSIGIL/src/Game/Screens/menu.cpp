#include "menu.h"

#include "sl.h"
//#include "raylib.h"
#include "Setup/Game.h"
#include "Setup\Player.h"

using namespace Juego;

namespace Juego
{
	enum gameActions
	{
		Settings = 7,
		PlayGame,
		QuitGame,
		Credits,
		Howtoplay
	};

	namespace Menu_Section
	{
		static void MenuInput()
		{

			if (slGetKey(49)) //one
			{
				#ifdef AUDIO
								PlaySound(pong_select_menu);
				#endif
				selectOption = PlayGame;
				isPlayer2CPU = true;
				isScreenFinished = true;
			}

			if (slGetKey(50))
			{
				#ifdef AUDIO
								PlaySound(pong_select_menu);
				#endif
				selectOption = PlayGame;
				isPlayer2CPU = false;
				isScreenFinished = true;
			}

			if (slGetKey(51))
			{
				#ifdef AUDIO
								PlaySound(pong_select_menu);
				#endif
				selectOption = Settings;
				isScreenFinished = true;
			}

			if (slGetKey(52))
			{
				#ifdef AUDIO
								PlaySound(pong_select_menu);
				#endif
				selectOption = Howtoplay;
				isScreenFinished = true;
			}

			if (slGetKey(53))
			{
				#ifdef AUDIO
				PlaySound(pong_select_menu);
				#endif
				selectOption = Credits;
				isScreenFinished = true;
			}

			if (slGetKey(54))
			{
				selectOption = QuitGame;
				isScreenFinished = true;
			}
		}

		void UpdateMenuScreen()
		{
			#ifdef AUDIO
			UpdateMusicStream(pong_menu_song);
			#endif
			
			MenuInput();
		}

		void InitMenuScreen()
		{
			isScreenFinished = false;
		}

		bool FinishMenuScreen()
		{
			return isScreenFinished;
		}

		void DrawMenu()
		{
			slSetFontSize(defaultFontSize);
			slText(30, 20, "Simple Pong!");
			slText(10, screenHeight / 6.3, "1. Player vs CPU");
			slText(10, screenHeight / 4.2, "2. 2 Players Local");
			slText(10, screenHeight / 3.2, "3. Options");
			slText(10, screenHeight / 2.6, "4. How to play");
			slText(10, screenHeight / 2.2, "5. Credits");
			slText(10, screenHeight / 1.9, "6. Quit");
			slText(screenWidth / 2.8, screenHeight / 1.1, "Ver. 1.0 by Franco Vega");
			//DrawText(FormatText("Simple Pong!"), MeasureText("Simple Pong!", 60) / 6, 20, defaultFontSize, WHITE);
			//DrawText(FormatText("1. Player vs CPU"), 10, screenHeight / 6.3, defaultFontSize, WHITE);
			//DrawText(FormatText("2. 2 Players Local"), 10, screenHeight / 4.2, defaultFontSize, WHITE);
			//DrawText(FormatText("3. Options"), 10, screenHeight / 3.2, defaultFontSize, WHITE);
			//DrawText(FormatText("4. How to play"), 10, screenHeight / 2.6, defaultFontSize, WHITE);
			//DrawText(FormatText("5. Credits"), 10, screenHeight / 2.2, defaultFontSize, WHITE);
			//DrawText(FormatText("6. Quit"), 10, screenHeight / 1.9, defaultFontSize, WHITE);
			//DrawText(FormatText("Ver. 1.0 by Franco Vega"), screenWidth / 2.8, screenHeight / 1.1, defaultFontSize, WHITE);
		}
	}
}