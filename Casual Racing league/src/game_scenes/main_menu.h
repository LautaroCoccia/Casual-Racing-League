#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "raylib.h"

namespace Casual_Racing_League
{
	namespace Main_Menu
	{
		struct BUTTON
		{

			bool cursorOver = false;
			Rectangle buttonRec;
			Color normalState = WHITE;
			Color overState = BLUE;
			Color exitState = RED;
			Color actualColor = normalState;

		};
		extern bool exitGame;

		void InitMenu();
		void UpdateMenu();
	}
}
#endif