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
			if (slGetKey(49))
			{
				#ifdef AUDIO
				PlaySound(pong_select_menu);
				#endif
				selectOption = Menu;
				isScreenFinished = true;
			}

			if (slGetKey(50))
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
			slText(screenWidth / 4, screenHeight / 16, "Match Finished!");
			//DrawText(FormatText("Match Finished!"), screenWidth / 4, screenHeight / 16, defaultFontSize, WHITE);

			for (int i = 0; i < maxplayers; i++)
			{
				if (players[i].score >= scoreLimit)
				{
					if (players[1].score >= scoreLimit && isPlayer2CPU)
					{
						//DrawText(FormatText("Player CPU won!"), screenWidth / 4, screenHeight / 3, defaultFontSize, WHITE);
						slText(screenWidth / 4, screenHeight / 3, "Player CPU won!");
					}
					else
					{
						//DrawText(FormatText("Player %i won!", i + 1), screenWidth / 4, screenHeight / 3, defaultFontSize, WHITE);
						slText(screenWidth / 4, screenHeight / 3, "Player won!");
					}
				}
			}

			slText(screenWidth / 4 - 20, screenHeight / 2, "1. Go back to Menu");
			slText(screenWidth / 4 - 20, screenHeight / 1.5, "2. Restart Match");
			//DrawText(FormatText("1. Go back to Menu"), screenWidth / 4 - 20, screenHeight / 2, defaultFontSize, WHITE); // default values  screenWidth / 2 - 250, 300
			//DrawText(FormatText("2. Restart Match"), screenWidth / 4 - 20, screenHeight / 1.5, defaultFontSize, WHITE); // default values screenWidth / 2 - 250, 400
		}
	}
}