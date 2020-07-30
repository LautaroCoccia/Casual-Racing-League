#ifndef GAMEPLAY_H
#define GAMEPLAY_H

namespace Casual_Racing_League
{
	namespace Gameplay
	{
		enum gameModes
		{
			singleplayer, multiPlayer
		};

		extern gameModes modes;

		void InitGameMode();
		void UpdateGameplay();
	}
	

}
#endif 
