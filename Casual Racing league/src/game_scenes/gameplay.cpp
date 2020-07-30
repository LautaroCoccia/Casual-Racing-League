#include "gameplay.h"

#include "Raylib.h"
#include <iostream>
namespace Casual_Racing_League
{
	namespace Gameplay
	{
		gameModes modes;

		void Timer();

		void InitGameMode()
		{
			
			modes = singleplayer;
		}

		void UpdateGameplay()
		{
			switch (modes)
			{
			case singleplayer:
				DrawText("GAMEPLAY", 50, GetScreenHeight() / 3 + 150, 50, BLUE);
				break;
			case multiPlayer:
				DrawText("GAMEPLAY", 50, GetScreenHeight() / 3 + 150, 100, BLUE);
				break;
			}
		}
	}
}