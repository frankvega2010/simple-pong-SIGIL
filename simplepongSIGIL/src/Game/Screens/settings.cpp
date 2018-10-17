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

	namespace Settings_Section
	{
		static void SettingsInput()
		{

			if (slGetKey(54))
			{
				#ifdef AUDIO
				PlaySound(pong_select_option2);
				#endif
				cpuDifficulty = cpu_easy;
			}

			if (slGetKey(55))
			{
				#ifdef AUDIO
				PlaySound(pong_select_option2);
				#endif
				cpuDifficulty = cpu_normal;
			}

			if (slGetKey(56))
			{
				#ifdef AUDIO
				PlaySound(pong_select_option2);
				#endif
				cpuDifficulty = cpu_hard;
			}

			if (slGetKey(57))
			{
				#ifdef AUDIO
				PlaySound(pong_select_menu);
				#endif
				selectOption = Menu;
				isScreenFinished = true;
			}
		}

		void UpdateSettingsScreen()
		{
			#ifdef AUDIO
			UpdateMusicStream(pong_menu_song);
			#endif
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