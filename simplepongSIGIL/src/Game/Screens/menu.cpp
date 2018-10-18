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

	static const int KEY_1 = 49;
	static const int KEY_2 = 50;
	static const int KEY_3 = 51;
	static const int KEY_4 = 52;
	static const int KEY_5 = 53;
	static const int KEY_6 = 54;

	namespace Menu_Section
	{
		static void MenuInput()
		{

			if (slGetKey(KEY_1)) //one
			{
				#ifdef AUDIO
				slSoundPlay(pong_select_menu);
				#endif
				selectOption = PlayGame;
				isPlayer2CPU = true;
				isScreenFinished = true;
			}

			if (slGetKey(KEY_2))
			{
				#ifdef AUDIO
				slSoundPlay(pong_select_menu);
				#endif
				selectOption = PlayGame;
				isPlayer2CPU = false;
				isScreenFinished = true;
			}

			if (slGetKey(KEY_3))
			{
				#ifdef AUDIO
				slSoundPlay(pong_select_menu);
				#endif
				selectOption = Settings;
				isScreenFinished = true;
			}

			if (slGetKey(KEY_4))
			{
				#ifdef AUDIO
				slSoundPlay(pong_select_menu);
				#endif
				selectOption = Howtoplay;
				isScreenFinished = true;
			}

			if (slGetKey(KEY_5))
			{
				#ifdef AUDIO
				slSoundPlay(pong_select_menu);
				#endif
				selectOption = Credits;
				isScreenFinished = true;
			}

			if (slGetKey(KEY_6))
			{
				selectOption = QuitGame;
				isScreenFinished = true;
			}
		}

		void UpdateMenuScreen()
		{			
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
			slText(10, screenHeight / 1.6, "1. Player vs CPU");
			slText(10, screenHeight / 1.9, "2. 2 Players Local");
			slText(10, screenHeight / 2.2, "3. Options");
			slText(10, screenHeight / 2.6, "4. How to play");
			slText(10, screenHeight / 3.2, "5. Credits");
			slText(10, screenHeight / 4.2, "6. Quit");
			slText(screenWidth / 2.8, screenHeight / 6.3, "Ver. 1.0 by Franco Vega");
		}
	}
}