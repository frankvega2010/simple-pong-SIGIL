#ifndef BALL_H
#define BALL_H

//#include "raylib.h"

namespace Juego
{
	struct Ball {
		int posX;
		int posY;
		int speedX;
		int speedY;
		int radio;
		bool active;
		float defaultMultiplier;
		float defaultMultiplierHorizontalVertical;
		float defaultMultiplierDown;
		float defaultMultiplierUp;
	};

	extern Ball ball;

	namespace Gameplay_Section
	{
		void createBall();
		void ballUpdate();
		void ballDraw();
		void ballResetSpeed();
	}
}
#endif // BALL_H
