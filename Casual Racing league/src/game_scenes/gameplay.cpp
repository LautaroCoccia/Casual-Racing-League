#include "gameplay.h"

#include "../game_objects/players.h"

namespace Casual_Racing_League
{
	namespace Gameplay
	{
		gameModes modes;

		Texture2D track;

		

		const int screenWidth = 800;
		const int screenHeight = 450;

		
		void InitGameplay()
		{
			Players::InitChecker();
			
			track = LoadTexture("assets/track.png");
		}

		void UpdateGameplay()
		{
			DrawTexture(track, screenWidth / 2 - track.width / 2, screenHeight / 2 - track.height / 2, WHITE);
			

			switch (modes)
			{
			case singleplayer:
				if (!Players::Player1Win())
				{
					Players::InputPlayer1();
					Players::DrawPlayer1();
					Players::DrawChecker();
					Players::CollisionChecker();
					Players::Player1Win();
				}
				else if(Players::Player1Win())
				{
					DrawText(FormatText("Player 1 wins"), static_cast<int>(GetScreenWidth() / 2 - (MeasureText(FormatText("Player 1 wins"), 50) / 2)), GetScreenHeight() / 5, 50, BLACK);
				}
				break;
			case multiplayer:
				if (!Players::Player1Win() && !Players::Player2Win())
				{
					Players::InputPlayer1();
					Players::InputPlayer2();
					Players::DrawPlayer1();
					Players::DrawPlayer2();
					Players::DrawChecker();
					Players::CollisionChecker();
					Players::Player1Win();
					Players::Player2Win();
				}
				if (Players::Player1Win())
				{
					DrawText(FormatText("Player 1 wins"), static_cast<int>(GetScreenWidth() / 2 - (MeasureText(FormatText("Player 1 wins"), 50) / 2)), GetScreenHeight() / 5, 50, BLACK);
				}
				else if (Players::Player2Win())
				{
					DrawText(FormatText("Player 2 wins"), static_cast<int>(GetScreenWidth() / 2 - (MeasureText(FormatText("Player 1 wins"), 50) / 2)), GetScreenHeight() / 5, 50, BLACK);
				}
				break;
			}
		}
	}
}