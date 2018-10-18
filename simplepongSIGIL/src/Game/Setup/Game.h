#ifndef GAME_H
#define GAME_H

namespace Juego
{
	extern int screenWidth;
	extern int screenHeight;

	extern bool isScreenFinished;

	extern int selectOption;

	extern int defaultFontSize;
	extern int defaultFontSizeGameplayText;
	extern int defaultFontSizeGameplayScore;

	extern int pong_hit_wall;
	extern int pong_hit_player;
	extern int pong_player_scored;
	extern int pong_match_end;
	extern int pong_select_menu;
	extern int pong_select_option2;
	extern int pong_menu_song;

	void Execute();
}
#endif // GAME_H