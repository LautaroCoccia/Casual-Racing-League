#include "gameplay.h"

#include "Raylib.h"

#include "../game_objects/players.h"

namespace Casual_Racing_League
{
	namespace Gameplay
	{
		gameModes modes;

		void Timer();

		void UpdateGameplay()
		{
			switch (modes)
			{
			case singleplayer:
				Players::InputPlayer1();
				Players::DrawPlayer1();
				break;
			case multiplayer:
				Players::InputPlayer1();
				Players::InputPlayer2();
				Players::DrawPlayer1();
				Players::DrawPlayer2();
				break;
			}
		}
	}
}