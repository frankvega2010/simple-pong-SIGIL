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
				slSoundPlay(pong_select_menu);
				#endif
				selectOption = PlayGame;
				isPlayer2CPU = true;
				isScreenFinished = true;
			}

			if (slGetKey(50))
			{
				#ifdef AUDIO
				slSoundPlay(pong_select_menu);
				#endif
				selectOption = PlayGame;
				isPlayer2CPU = false;
				isScreenFinished = true;
			}

			if (slGetKey(51))
			{
				#ifdef AUDIO
				slSoundPlay(pong_select_menu);
				#endif
				selectOption = Settings;
				isScreenFinished = true;
			}

			if (slGetKey(52))
			{
				#ifdef AUDIO
				slSoundPlay(pong_select_menu);
				#endif
				selectOption = Howtoplay;
				isScreenFinished = true;
			}

			if (slGetKey(53))
			{
				#ifdef AUDIO
				slSoundPlay(pong_select_menu);
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
			//slSoundResumeAll();
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
		}
	}
}