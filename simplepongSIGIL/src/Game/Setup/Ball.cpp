#include "Setup\Ball.h"

#include "sl.h"

#include "Setup\Game.h"
#include "Setup\Player.h"

namespace Juego
{
	Ball ball;

	namespace Gameplay_Section
	{
		void createBall()
		{
			ball.center.x = (float)screenWidth / 2;
			ball.center.y = (float)screenHeight / 2;
			ball.radio = 10;
			ball.speedX = 500.0f;
			ball.speedY = 0;
			ball.active = false;
			ball.defaultMultiplier = -1.1f;
			ball.defaultMultiplierHorizontalVertical = -1.0f;
			ball.defaultMultiplierDown = 20.0f;
			ball.defaultMultiplierUp = -20.0f;
		}

		void ballUpdate()
		{
			// Ball movement logic
			if (ball.active)
			{
				ball.center.x += ball.speedX * slGetDeltaTime();
				ball.center.y += ball.speedY * slGetDeltaTime();
			}
			else
			{
				if (players[0].scored)
				{
					ball.center.x = (float)screenWidth / 2 + 20;
					ball.center.y = (float)screenHeight / 2;
				}
				else if (players[1].scored)
				{
					ball.center.x = (float)screenWidth / 2 - 20;
					ball.center.y = (float)screenHeight / 2;
				}
			}
		}
		void ballDraw()
		{
			slCircleFill(ball.center.x, ball.center.y, ball.radio, 60);
			//DrawCircleV(ball.position, ball.radio, WHITE);
		}

		void ballResetSpeed()
		{
			if (ball.radio == 10)
			{
				if (players[0].scored)
				{
					ball.speedX = 500.0f;
					ball.speedY = 0.0f;
				}
				else
				{
					ball.speedX = -500.0f;
					ball.speedY = 0.0f;
				}				
			}
			else
			{
				if (players[0].scored)
				{
					ball.speedX = 300.0f;
					ball.speedY = 0.0f;
				}
				else
				{
					ball.speedX = -300.0f;
					ball.speedY = 0.0f;
				}
				
			}
		}
	}
}