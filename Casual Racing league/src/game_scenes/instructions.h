#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "raylib.h"

namespace Casual_Racing_League
{
	namespace Instructions
	{
		struct BUTTON
		{

			bool cursorOver = false;
			Rectangle buttonRec;
			Color normalState = WHITE;
			Color overState = BLUE;
			Color actualColor = normalState;

		};
		void InitInstructions();
		void UpdateInstructions();
	}
	
}
#endif // !INSTRUCTIONS_
