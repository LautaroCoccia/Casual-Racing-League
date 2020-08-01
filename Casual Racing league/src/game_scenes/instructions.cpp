#include "instructions.h"

#include "../game_objects/game_manager.h"

namespace Casual_Racing_League
{
    namespace Instructions
    {
        BUTTON instructions;

        void CheckCollisionButtonsMouse();
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
            instructions.buttonRec.x = static_cast<float>(GetScreenWidth() - widthRec) / 2;
            instructions.buttonRec.y = static_cast<float>(GetScreenHeight() - heightRec) / 2 + static_cast<float>(GetScreenHeight() - heightRec) / 3;
            instructions.buttonRec.width = widthRec;
            instructions.buttonRec.height = heightRec;
        }
        
        void UpdateInstructions()
        {
            CheckCollisionButtonsMouse();
            DrawTittle();
            DrawInstruction();
            DrawButtons();
        }

        void CheckCollisionButtonsMouse()
        {
            if (CheckCollisionCircleRec(GetMousePosition(), 0, instructions.buttonRec))
            {
                instructions.actualColor = instructions.overState;
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    Game_Manager::scene = Game_Manager::menu;
                }
            }
            else
            {
                instructions.actualColor = instructions.normalState;
            }
        }
        void DrawTittle()
        {
            DrawText("Casual racing League", static_cast<int>(GetScreenWidth() / 2 - (MeasureText("Casual racing League", fontTittle) / 2)), GetScreenHeight() / 5, fontTittle, BLUE);
            DrawText("Instructions", static_cast<int>(GetScreenWidth() / 2 - (MeasureText("Instructions", fontSubTittle) / 2)), GetScreenHeight() / 5 + distanceTittle, fontSubTittle, WHITE);
        }

        void DrawInstruction()
        {
            DrawText("each player must go through each of the checkpoints to add one lap", static_cast<int>(GetScreenWidth() / 2 - (MeasureText("each player must go through each of the checkpoints to add one lap", fontSubTittle) / 2)), GetScreenHeight() -280, fontSubTittle, BLACK);
                 
            DrawText("the first to complete 5 laps wins  ", static_cast<int>(GetScreenWidth() / 2 - (MeasureText(" the first to complete 5 laps wins  ", fontSubTittle) / 2)), GetScreenHeight() -260, fontSubTittle, BLACK);

            DrawText("CONTROLS  ", static_cast<int>(GetScreenWidth() / 2 - (MeasureText(" CONTROLS  ", fontSubTittle) / 2)), GetScreenHeight() - 240, fontSubTittle, BLACK);

            DrawText("WASD for p1           ARROWS for p2  ", static_cast<int>(GetScreenWidth() / 2 - (MeasureText(" WASD for p1           ARROWS for p2   ", fontSubTittle) / 2)), GetScreenHeight() - 220, fontSubTittle, BLACK);
        }

        void DrawButtons()
        {
            DrawRectangleRec(instructions.buttonRec, instructions.actualColor);
            DrawText("Return menu", static_cast<int>(instructions.buttonRec.x + instructions.buttonRec.width / 2) - (MeasureText("Return Menu", 24) / 2), static_cast<int>(instructions.buttonRec.y + heightRec / 3), fontButtons, BLACK);
        }
    }
}