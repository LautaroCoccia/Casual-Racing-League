#include "instructions.h"

#include "raylib.h"

#include "../game_objects/game_manager.h"

namespace Casual_Racing_League
{
    namespace Instructions
    {

        void DrawTittle();
        void DrawInstruction();
        void DrawButtons();

        static int fontTittle = 30;
        static int fontSubTittle = 20;
        static int fontText = 20;
        static int fontButtons = 24;
        static float widthRec = 200;
        static float heightRec = 50;
        static int distanceTittle = 60;

        void InitInstructions()
        {
            
        }

        void UpdateInstructions()
        {
            DrawTittle();
            DrawInstruction();
            DrawButtons();
        }

        //-----------------------------
        // functions for this cpp
        void DrawTittle()
        {
            DrawText("Casual racing League", static_cast<int>(GetScreenWidth() / 2 - (MeasureText("Casual racing League", fontTittle) / 2)), GetScreenHeight() / 5, fontTittle, BLUE);
            DrawText("Instructions", static_cast<int>(GetScreenWidth() / 2 - (MeasureText("Instructions", fontSubTittle) / 2)), GetScreenHeight() / 5 + distanceTittle, fontSubTittle, WHITE);
        }

        void DrawInstruction()
        {
            
        }

        void DrawButtons()
        {
            
            //DrawText("Return menu", static_cast<int>(how_to_play.genButton.x + how_to_play.genButton.width / 2) - (MeasureText("Return Menu", 24) / 2), static_cast<int>(how_to_play.genButton.y + heightRec / 3), fontButtons, BLACK);
        }
    }
}