#include "settings.h"

#include "sl.h"

#include "Setup/Game.h"
#include "Screens/gameplay.h"
#include "Setup\Player.h"
#include "Setup\Ball.h"

using namespace Juego;
using namespace Gameplay_Section;

namespace Juego
{
	static const int Menu = 6;

	static const int KEY_6 = 54;
	static const int KEY_7 = 55;
	static const int KEY_8 = 56;
	static const int KEY_9 = 57;

	namespace Settings_Section
	{
		static void SettingsInput()
		{

			if (slGetKey(KEY_6))
			{
				#ifdef AUDIO
				slSoundPlay(pong_select_option2);
				#endif
				cpuDifficulty = cpu_easy;
			}

			if (slGetKey(KEY_7))
			{
				#ifdef AUDIO
				slSoundPlay(pong_select_option2);
				#endif
				cpuDifficulty = cpu_normal;
			}

			if (slGetKey(KEY_8))
			{
				#ifdef AUDIO
				slSoundPlay(pong_select_option2);
				#endif
				cpuDifficulty = cpu_hard;
			}

			if (slGetKey(KEY_9))
			{
				#ifdef AUDIO
				slSoundPlay(pong_select_menu);
				#endif
				selectOption = Menu;
				isScreenFinished = true;
			}
		}

		void UpdateSettingsScreen()
		{
			SettingsInput();
		}
		void InitSettingsScreen()
		{
			isScreenFinished = false;
		}
		bool FinishSettingsScreen()
		{
			return isScreenFinished;
		}

		void DrawSettings()
		{
			slSetFontSize(defaultFontSize);

			slText(30, screenHeight / 1.1, "CPU Difficulty");
			slText(30, screenHeight / 1.3, "6. Easy");
			slText(30, screenHeight / 1.45, "7. Normal");
			slText(30, screenHeight / 1.65, "8. Hard");
			slText(10, 20, "9. Go back to Menu");
		}
	}
}