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
				players[i].posX = 0; // default value
				players[i].posY = screenHeight / 2; // default value = screenHeight / 2 - 40
				players[i].sizeX = 20; // mitad = 60
				players[i].sizeY = 120; // mitad = 60
				players[i].score = 0;
				players[i].scorePositionX = screenWidth / 2 - 250;
				players[i].scored = false;
				players[i].defaultSpeed = 750.0f;
			}

			// Setting player 1 X Position
			players[0].posX = screenWidth / 34; // default value = screenWidth / 2 - 550 - 20
			players[0].scorePositionX = screenWidth / 2 - 250;

			 // Setting player 2 X Position
			players[1].posX = screenWidth / 2 * 1.9; // default value = screenWidth / 2 + 550
			players[1].scorePositionX = screenWidth / 2 + 250;
		}

		void createMiddleLine()
		{
			middleLine.posX = screenWidth / 2;
			middleLine.posY = 0;
			middleLine.sizeX = 5;
			middleLine.sizeY = (float)screenHeight;
		}
		
		void playerInput()
		{
			if (slGetKey(119)) players[0].posY -= players[0].defaultSpeed * slGetDeltaTime(); // w
			if (slGetKey(115)) players[0].posY += players[0].defaultSpeed * slGetDeltaTime(); // s

			if (!(isPlayer2CPU))
			{
				if (slGetKey(SL_KEY_UP)) players[1].posY -= players[1].defaultSpeed * slGetDeltaTime();
				if (slGetKey(SL_KEY_DOWN)) players[1].posY += players[1].defaultSpeed * slGetDeltaTime();
			}			
		}

		void playerUpdate()
		{
			if (isPlayer2CPU)
			{
				players[1].posY = (ball.posY / cpuDifficulty);
			}

			for (int i = 0; i < maxplayers; i++)
			{
				if (players[i].posY < 0) players[i].posY = 0;
				if (players[i].posY + players[i].sizeY > screenHeight) players[i].posY = screenHeight - players[i].sizeY;
			}
		}

		void playerDraw()
		{
			// Draw middle line
			slRectangleFill(middleLine.posX, middleLine.posY, middleLine.sizeX, middleLine.sizeY);

			slRectangleFill(players[0].posX, players[0].posY, players[0].sizeX, players[0].sizeY); // red

			slRectangleFill(players[1].posX, players[1].posY, players[1].sizeX, players[1].sizeY); // skyblue

			if (isPlayer2CPU)
			{
				slRectangleFill(players[1].posX, players[1].posY, players[1].sizeX, players[1].sizeY); //yellow
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