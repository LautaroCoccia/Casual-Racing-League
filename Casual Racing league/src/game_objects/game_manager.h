#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "raylib.h"

namespace Casual_Racing_League
{
	namespace Game_Manager
	{
		enum SCENE
		{
			menu, gameplay, instructions
		};

		extern SCENE scene;

		void InitGameplay();
		void MainGameLoop();
	}
}

#endif