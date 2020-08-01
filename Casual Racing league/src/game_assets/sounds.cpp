#include "sounds.h"

namespace Casual_Racing_League
{
	namespace Sounds
	{
		Sound buttons;

		void LoadMusic()
		{
			InitAudioDevice();

			buttons = LoadSound("sounds/buttons.ogg");
		}

		void UnloadMusic()
		{
			UnloadSound(buttons);
		}
	}
}