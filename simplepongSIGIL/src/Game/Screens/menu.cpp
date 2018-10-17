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
			slText(30, screenHeight - 60, "Simple Pong!");
			slText(10, screenHeight / 1.6, "1. Player vs CPU");//1.1
			slText(10, screenHeight / 1.9, "2. 2 Players Local");//1.9
			slText(10, screenHeight / 2.2, "3. Options");//2.2
			slText(10, screenHeight / 2.6, "4. How to play");//2.6
			slText(10, screenHeight / 3.2, "5. Credits");//3.2
			slText(10, screenHeight / 4.2, "6. Quit");//4.2
			slText(screenWidth / 2.8, screenHeight / 6.3, "Ver. 1.0 by Franco Vega");//6.3
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