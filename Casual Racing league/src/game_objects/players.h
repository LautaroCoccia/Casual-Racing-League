#ifndef PLAYERS_H
#define PLAYERS_H

#include "raylib.h"

namespace Casual_Racing_League
{
	namespace Players
	{
		struct PLAYER
		{
			int playerLap;
			Vector2 position;
			Vector2 speed;
			float acceleration;
			float rotation;
			Vector3 collider;
		};

		void InitPlayer1();
		void InitPlayer2();
		void InputPlayer1();
		void InputPlayer2();
		void DrawPlayer1();
		void DrawPlayer2();
	}
}
#endif // !PLAYERS_H

