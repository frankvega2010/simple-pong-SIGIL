#include "Game.h"

#include "sl.h"
#include "Screens/gameplay.h"
#include "Screens/menu.h"
#include "Screens/gameover.h"
#include "Screens/settings.h"
#include "Screens/credits.h"
#include "Screens/howtoplay.h"

using namespace Juego;
using namespace Gameplay_Section;
using namespace GameOver_Section;
using namespace Menu_Section;
using namespace Settings_Section;
using namespace Credits_Section;
using namespace Howtoplay_Section;

namespace Juego
{
	enum gameActions
	{
		Gameplay = 3,
		GameOver,
		Restart_Gameplay,
		Menu,
		Settings,
		PlayGame,
		QuitGame,
		Credits,
		Howtoplay
	};

	int screenWidth;
	int screenHeight;

	bool isScreenFinished;

	int selectOption;
	static int gamePhase;

	int defaultFontSize;
	int defaultFontSizeGameplayText;
	int defaultFontSizeGameplayScore;

	int pong_hit_wall;

	int pong_hit_player;
	int pong_player_scored;
	int pong_match_end;
	int pong_select_menu;
	int pong_select_option2;
	int pong_menu_song;


	static void Init()
	{
		screenWidth = 1300;
		screenHeight = 800;

		selectOption = 0;

		defaultFontSize = 60;
		defaultFontSizeGameplayText = 30;
		defaultFontSizeGameplayScore = 120;

		InitGameplayVariables();

		slWindow(screenWidth, screenHeight, "Simple! Pong", false);

#ifdef AUDIO
		pong_hit_wall = slLoadWAV("res/wall.wav");

		pong_hit_player = slLoadWAV("res/player.wav");
		pong_player_scored = slLoadWAV("res/score.wav");
		pong_match_end = slLoadWAV("res/pong_frank_match_end.wav");
		pong_select_menu = slLoadWAV("res/pong_frank_select1.wav");
		pong_select_option2 = slLoadWAV("res/pong_frank_select3.wav");

		pong_menu_song = slLoadWAV("res/pong_menu.wav");

		slSoundLoop(pong_menu_song);
#endif

		slSetFont(slLoadFont("res/fonts/FORCED_SQUARE.ttf"), 24);

		gamePhase = Menu;
		InitMenuScreen();
	}

	static void DeInit()
	{
		slClose();
	}

	static void Draw()
	{
		slSetBackColor(0, 0, 0);

		switch (gamePhase)
		{
		case Menu: Menu_Section::DrawMenu(); break;
		case Gameplay: Gameplay_Section::DrawGameplay(); break;
		case GameOver: GameOver_Section::DrawGameOver(); break;
		case Settings: Settings_Section::DrawSettings(); break;
		case Credits: Credits_Section::DrawCredits(); break;
		case Howtoplay: Howtoplay_Section::DrawHowtoplay(); break;
		}
	}

	static void Update()
	{
		switch (gamePhase)
		{
		case Menu:
		{
			UpdateMenuScreen();

			if (FinishMenuScreen())
			{

				switch (selectOption)
				{
				case PlayGame:
				{
				#ifdef AUDIO
					slSoundStopAll();
				#endif
					RestartPhase();
					gamePhase = Gameplay;
					InitGameplayScreen();
					break;
				}
				case Settings:
				{
					gamePhase = Settings;
					InitSettingsScreen();
					break;
				}
				case Credits:
				{
					gamePhase = Credits;
					InitCreditsScreen();
					break;
				}
				case Howtoplay:
				{
					gamePhase = Howtoplay;
					InitHowtoplayScreen();
					break;
				}
				case QuitGame:
				{
				#ifdef AUDIO
					slSoundStopAll();
				#endif

					gamePhase = 0;
					return;
					break;
				}
				}
			}
		}
		break;
		case Settings:
		{
			UpdateSettingsScreen();

			if (FinishSettingsScreen())
			{
				gamePhase = Menu;
				InitMenuScreen();
			}
		}
		break;

		case GameOver:
		{
			UpdateGameOverScreen();

			if (FinishGameOverScreen())
			{
				switch (selectOption)
				{
				case Menu:
				{
				#ifdef AUDIO
					slSoundPlay(pong_menu_song);
				#endif

					gamePhase = Menu;
					InitMenuScreen();
					break;
				}
				case Restart_Gameplay:
				{
					RestartPhase();
					gamePhase = Gameplay;
					InitGameplayScreen();
					break;
				}
				}
			}
		}
		break;

		case Gameplay:
		{
			UpdateGameplayScreen();

			if (FinishGameplayScreen())
			{
				gamePhase = GameOver;
				InitGameOverScreen();
			}
		}
		break;
		case Credits:
		{
			UpdateCreditsScreen();

			if (FinishCreditsScreen())
			{
				gamePhase = Menu;
				InitMenuScreen();
			}
		}
		break;
		case Howtoplay:
		{
			UpdateHowtoplayScreen();

			if (FinishHowtoplayScreen())
			{
				gamePhase = Menu;
				InitMenuScreen();
			}
		}
		break;
		}
	}

	void Execute()
	{
		Init();
		while (!slShouldClose())
		{
			Update();
			if (gamePhase == 0) return;
			Draw();
			slRender();
		}
		DeInit();
	}
}