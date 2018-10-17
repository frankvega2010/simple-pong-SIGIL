#include "gameover.h"

#include "sl.h"
#include "Setup/Game.h"
#include "Screens/gameplay.h"
#include "Setup\Player.h"

namespace Juego
{
	static const int Menu = 6;
	static const int Restart_Gameplay = 5;

	namespace GameOver_Section
	{
		static void GameOverInput()
		{
			if (slGetKey(55))
			{
				#ifdef AUDIO
				PlaySound(pong_select_menu);
				#endif
				selectOption = Menu;
				isScreenFinished = true;
			}

			if (slGetKey(56))
			{
				#ifdef AUDIO
				PlaySound(pong_select_menu);
				#endif
				selectOption = Restart_Gameplay;
				isScreenFinished = true;
			}
		}

		void UpdateGameOverScreen()
		{
			GameOverInput(); 
		}

		void InitGameOverScreen()
		{
			isScreenFinished = false;
		}

		bool FinishGameOverScreen()
		{
			return isScreenFinished;
		}

		void DrawGameOver()
		{
			slSetFontSize(defaultFontSize);
			slText(screenWidth / 3.5, screenHeight / 1.2, "Match Finished!");

			for (int i = 0; i < maxplayers; i++)
			{
				if (players[i].score >= scoreLimit)
				{
					if (players[1].score >= scoreLimit && isPlayer2CPU)
					{
						slText(screenWidth / 4, screenHeight / 1.5, "Player CPU won!");
					}
					else
					{
						switch (i)
						{
						case 0: slText(screenWidth / 4, screenHeight / 1.5, "Player 1 won!"); break;
						case 1: slText(screenWidth / 4, screenHeight / 1.5, "Player 2 won!"); break;
						}
					}
				}
			}

			slText(screenWidth / 4, screenHeight / 3, "7. Go back to Menu");
			slText(screenWidth / 4, screenHeight / 4, "8. Restart Match");
		}
	}
}