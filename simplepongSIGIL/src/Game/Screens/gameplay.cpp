#include "gameplay.h"

#include <cmath>
#include "sl.h"
#include "Setup\Game.h"
#include "Setup\Player.h"
#include "Setup\Ball.h"

namespace Juego
{
	int scoreLimit;
	static bool gameON;
	static int maxAngle = -800;
	static float ballMaxSpeed = 1800.0f;

	static const int minBallSpeedY = 200;
	static const int medBallSpeedY = 400;
	static const int maxBallSpeedY = 600;

	namespace Gameplay_Section
	{
		static bool CheckCollisionCircleRec(Center center, float radius, Rectangle rec)
		{
			if (center.x - radius < players[0].rectangle.x + players[0].rectangle.width / 2)
			{
				if (center.y + radius > players[0].rectangle.y - players[0].rectangle.height / 2 && center.y + radius < players[0].rectangle.y + players[0].rectangle.height / 2)
				{
					return true;
				}
			}

			if (center.x + radius > players[1].rectangle.x - players[1].rectangle.width / 2)
			{
				if (center.y + radius > players[1].rectangle.y - players[1].rectangle.height / 2 && center.y + radius < players[1].rectangle.y + players[1].rectangle.height / 2)
				{
					return true;
				}
			}

			return false;
		}

		static void GameplayInput()
		{
			// Ball launching logic
			if (!ball.active)
			{
				if (slGetKey(32))
				{
						ball.active = true;
				}
			}

			// Player Movement
			playerInput();
		}

		void InitGameplayVariables()
		{
			// Round Variables
			scoreLimit = 5;
			gameON = true;

			createBall();

			createPlayer();

			createMiddleLine();
		}

		void UpdateGameplayScreen()
		{
			//---------- Input
			GameplayInput();

			// Score Limit
			for (int i = 0; i < maxplayers; i++)
			{
				if (players[i].score >= scoreLimit)
				{
					#ifdef AUDIO
					PlaySound(pong_match_end);
					#endif
					isScreenFinished = true;
					return;
				}
			}

			playerUpdate();

			ballUpdate();


			// Collision logic: ball vs vertical walls FOR BOTH PLAYERS
			if ((ball.center.x + ball.radio) >= screenWidth && ball.active)
			{
			#ifdef AUDIO
				PlaySound(pong_player_scored);
			#endif

				ball.active = false;

				player1AddScore();

				ballResetSpeed();
			}
			else if ((ball.center.x + ball.radio) <= 0 && ball.active)
			{
			#ifdef AUDIO
				PlaySound(pong_player_scored);
			#endif

				ball.active = false;

				player2AddScore();

				ballResetSpeed();
			}

			// Collision logic: ball vs horizontal walls
			if ((ball.center.y - ball.radio) <= 0)
			{
				#ifdef AUDIO
								PlaySound(pong_hit_wall);
				#endif

				ball.center.y = 0 + ball.radio;
				ball.speedY *= ball.defaultMultiplierHorizontalVertical;
			}
			if ((ball.center.y + ball.radio) >= screenHeight)
			{
				#ifdef AUDIO
								PlaySound(pong_hit_wall);
				#endif
				ball.center.y = screenHeight - ball.radio;
				ball.speedY *= ball.defaultMultiplierHorizontalVertical;
			}

			// PLAYER VS BALL COLLISION ----------------------------------------------------------------------------------------------
			//////////////////////////////////////////////////////--------------------------------------------------------------------
			for (int i = 0; i < maxplayers; i++)
			{

				//if(ball.center.x + ball.radio >=)
				if (CheckCollisionCircleRec(ball.center, ball.radio, players[i].rectangle))
				{
					if (ball.speedX < 0)
					{
						if (ball.center.y >(players[0].rectangle.y + players[0].rectangle.height / 3)) ball.speedY = maxBallSpeedY;
						else if (ball.center.y >(players[0].rectangle.y + players[0].rectangle.height / 6)) ball.speedY = medBallSpeedY;
						else if (ball.center.y > players[0].rectangle.y) ball.speedY = minBallSpeedY;

						else if (ball.center.y < (players[0].rectangle.y - players[0].rectangle.height / 3)) ball.speedY = -(maxBallSpeedY);
						else if (ball.center.y < (players[0].rectangle.y - players[0].rectangle.height / 6)) ball.speedY = -(medBallSpeedY);
						else if (ball.center.y < players[0].rectangle.y) ball.speedY = -(minBallSpeedY);
					}
					else if (ball.speedX > 0)
					{
						if (ball.center.y >(players[1].rectangle.y + players[1].rectangle.height / 3)) ball.speedY = maxBallSpeedY;
						else if (ball.center.y >(players[1].rectangle.y + players[1].rectangle.height / 6)) ball.speedY = medBallSpeedY;
						else if (ball.center.y > players[1].rectangle.y) ball.speedY = minBallSpeedY;

						else if (ball.center.y < (players[1].rectangle.y - players[1].rectangle.height / 3)) ball.speedY = -(maxBallSpeedY);
						else if (ball.center.y < (players[1].rectangle.y - players[1].rectangle.height / 6)) ball.speedY = -(medBallSpeedY);
						else if (ball.center.y < players[1].rectangle.y) ball.speedY = -(minBallSpeedY);
					}

					if (ball.speedX < 0 || ball.speedX > 0)
					{
						#ifdef AUDIO
												PlaySound(pong_hit_player);
						#endif
						if (ball.center.x - ball.radio < players[0].rectangle.x + players[0].rectangle.width / 2)
						{
							ball.center.x = players[0].rectangle.x + players[0].rectangle.width / 2 + ball.radio;
						}
						if (ball.center.x + ball.radio > players[1].rectangle.x - players[1].rectangle.width / 2)
						{
							ball.center.x = players[1].rectangle.x - players[1].rectangle.width / 2 - ball.radio;
						}

						if (ball.speedX >= ballMaxSpeed)
						{
							ball.speedX = ballMaxSpeed * (-1);
						}
						else if (ball.speedX <= -(ballMaxSpeed))
						{
							ball.speedX = -(ballMaxSpeed) * (-1);
						}
						else
						{
							ball.speedX *= -1.1;
						}	
					}
				}

			}
		}

		void InitGameplayScreen()
		{
			isScreenFinished = false;
		}

		bool FinishGameplayScreen()
		{
			return isScreenFinished;
		}

		void RestartPhase()
		{
			ball.active = false;
			gameON = true;

			for (int i = 0; i < maxplayers; i++)
			{
				players[i].score = 0;
			}

			ball.center.x = (float)screenWidth / 2;
			ball.center.y = (float)screenHeight / 2;
			players[0].rectangle.y = screenHeight / 2;
			players[1].rectangle.y = screenHeight / 2;
		}

		void DrawGameplay()
		{
			playerDraw();
			ballDraw();

			if (!ball.active)
			{
				if (gameON)
				{
					slSetFontSize(defaultFontSizeGameplayText);
					slText(screenWidth / 2 - 280, screenHeight / 4, "Press");
					slText(screenWidth / 2 + 20, screenHeight / 4, "'SPACEBAR' to begin!");
				}
			}

			//Draw Score
			for (int i = 0; i < maxplayers; i++)
			{
				slSetFontSize(defaultFontSizeGameplayScore);
				slText(players[i].scorePositionX, screenHeight / 80, "0");
				//DrawText(FormatText("%i", players[i].score), players[i].scorePositionX, screenHeight / 80, defaultFontSizeGameplayScore, WHITE);			
			}
		}
	}
}