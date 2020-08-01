#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "Raylib.h"

namespace Casual_Racing_League
{
	namespace Gameplay
	{
		enum gameModes
		{
			singleplayer, multiplayer
		};
		
		
		extern gameModes modes;

		void InitGameplay();
		void UpdateGameplay();
	}
	
}
#endif 
