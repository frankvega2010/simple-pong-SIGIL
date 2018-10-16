#include "Player.h"

#include "Setup\Game.h"
#include "Setup\Ball.h"
#include "sl.h"

namespace Juego
{
	Player players[maxplayers];
	static Player middleLine;
	bool isPlayer2CPU = false;
	float cpuDifficulty = cpu_normal;

	const float cpu_easy = 1.3f;
	const float cpu_normal = 1.25f;
	const float cpu_hard = 1.24f;

	namespace Gameplay_Section
	{
		void createPlayer()
		{
			for (int i = 0; i < maxplayers; i++)
			{
				players[i].rectangle.x = 0; // default value
				players[i].rectangle.y = screenHeight / 2; // default value = screenHeight / 2 - 40
				players[i].rectangle.width = 20; // mitad = 60
				players[i].rectangle.height = 120; // mitad = 60
				players[i].score = 0;
				players[i].scorePositionX = screenWidth / 2 - 250;
				players[i].scored = false;
				players[i].defaultSpeed = 750.0f;
			}

			// Setting player 1 X Position
			players[0].rectangle.x = screenWidth / 34; // default value = screenWidth / 2 - 550 - 20
			players[0].scorePositionX = screenWidth / 2 - 250;

			 // Setting player 2 X Position
			players[1].rectangle.x = screenWidth / 2 * 1.9; // default value = screenWidth / 2 + 550
			players[1].scorePositionX = screenWidth / 2 + 250;
		}

		void createMiddleLine()
		{
			middleLine.rectangle.x = screenWidth / 2;
			middleLine.rectangle.y = screenHeight / 2;
			middleLine.rectangle.width = 5;
			middleLine.rectangle.height = (float)screenHeight;
		}
		
		void playerInput()
		{
			if (slGetKey(87)) players[0].rectangle.y += players[0].defaultSpeed * slGetDeltaTime(); // w
			if (slGetKey(83)) players[0].rectangle.y -= players[0].defaultSpeed * slGetDeltaTime(); // s

			if (!(isPlayer2CPU))
			{
				if (slGetKey(SL_KEY_UP)) players[1].rectangle.y += players[1].defaultSpeed * slGetDeltaTime();
				if (slGetKey(SL_KEY_DOWN)) players[1].rectangle.y -= players[1].defaultSpeed * slGetDeltaTime();
			}			
		}

		void playerUpdate()
		{
			if (isPlayer2CPU)
			{
				players[1].rectangle.y = (ball.center.y / cpuDifficulty);
			}

			for (int i = 0; i < maxplayers; i++)
			{
				if (players[i].rectangle.y + (players[i].rectangle.y / 2) > screenHeight) players[i].rectangle.y = screenHeight - (players[i].rectangle.y / 2);
				if (players[i].rectangle.y - (players[i].rectangle.y / 2) < 0) players[i].rectangle.y = 0 + (players[i].rectangle.y/2);
			}
		}

		void playerDraw()
		{
			// Draw middle line
			slRectangleFill(middleLine.rectangle.x, middleLine.rectangle.y, middleLine.rectangle.width, middleLine.rectangle.height);

			slRectangleFill(players[0].rectangle.x, players[0].rectangle.y, players[0].rectangle.width, players[0].rectangle.height); // red

			slRectangleFill(players[1].rectangle.x, players[1].rectangle.y, players[1].rectangle.width, players[1].rectangle.height); // skyblue

			if (isPlayer2CPU)
			{
				slRectangleFill(players[1].rectangle.x, players[1].rectangle.y, players[1].rectangle.width, players[1].rectangle.height); //yellow
			}
		}

		void player1AddScore()
		{
			players[0].scored = true;
			players[1].scored = false;

			players[0].score++;
		}

		void player2AddScore()
		{
			players[1].scored = true;
			players[0].scored = false;

			players[1].score++;
		}
	}
}