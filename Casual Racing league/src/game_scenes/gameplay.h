#ifndef GAMEPLAY_H
#define GAMEPLAY_H

namespace Casual_Racing_League
{
	namespace Gameplay
	{
		enum gameModes
		{
			singleplayer, multiplayer
		};

		extern gameModes modes;

		void UpdateGameplay();
	}
	

}
#endif 
