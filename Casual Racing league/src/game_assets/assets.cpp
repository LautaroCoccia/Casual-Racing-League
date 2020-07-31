#include "assets.h"


namespace Casual_Racing_league
{
	namespace Assets
	{
		Texture2D player1Car;

		void LoadMyTextures()
		{
			player1Car = LoadTexture("res\assets\Car_1_01.png");
		}


		void UnloadMyTextures()
		{
			UnloadTexture(player1Car);
		}
	}
}