#include "main_menu.h"

#include "../game_objects/game_manager.h"

#include "gameplay.h"

namespace Casual_Racing_League
{
    namespace Main_Menu
    {
        BUTTON play;
        BUTTON instructions;
        BUTTON exit;

        bool exitGame;

        static const int HALF_SCREEN = 2;
        static const int MOUSE_RADIUS = 0;

        static int titleFont = 60;
        static int buttonsFont = 24;
        static float rectWidth = 200;
        static float rectHeight = 50;
        static int rectDistance = 20;

        void CheckCollisionButtonMouse();
        void DrawTitle();
        void DrawButtons();
        void DrawCredits();

        void InitMenu()
        {
            play.buttonRec.x = static_cast<float>(GetScreenWidth() - rectWidth) / HALF_SCREEN;
            play.buttonRec.y = static_cast<float>(GetScreenHeight() - rectHeight) / 2.5f;
            play.buttonRec.width = rectWidth;
            play.buttonRec.height = rectHeight;

            instructions.buttonRec.x = static_cast<float>(GetScreenWidth() - rectWidth) / HALF_SCREEN;
            instructions.buttonRec.y = play.buttonRec.y + rectHeight + rectDistance;
            instructions.buttonRec.width = rectWidth;
            instructions.buttonRec.height = rectHeight;

            exit.buttonRec.x = static_cast<float>(GetScreenWidth() - rectWidth) / HALF_SCREEN;
            exit.buttonRec.y = instructions.buttonRec.y + rectHeight + rectDistance;
            exit.buttonRec.width = rectWidth;
            exit.buttonRec.height = rectHeight;

            exitGame = false;
        }
        void UpdateMenu()
        {
            CheckCollisionButtonMouse();
            DrawTitle();
            DrawButtons();
            DrawCredits();
        }

        void CheckCollisionButtonMouse()
        {
            if (CheckCollisionCircleRec(GetMousePosition(), MOUSE_RADIUS, play.buttonRec))
            {
                play.actualColor = play.overState;
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    Game_Manager::scene = Game_Manager::gameplay;
                    Gameplay::modes = Gameplay::singleplayer;
                }
            }
            else
            {
                play.actualColor = play.normalState;
            }

            if (CheckCollisionCircleRec(GetMousePosition(), MOUSE_RADIUS, instructions.buttonRec))
            {
                instructions.actualColor = instructions.overState;
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    Game_Manager::state = Game_Manager::gameplay;
                    Gameplay::modes = Gameplay::fight;
                }
            }
            else
            {
                instructions.actualColor = instructions.normalState;
            }

            if (CheckCollisionCircleRec(GetMousePosition(), MOUSE_RADIUS, exit.buttonRec))
            {
                exit.actualColor = exit.exitState;
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    exitGame = true;
                }
            }
            else
            {
                exit.actualColor = exit.normalState;
            }

        }
        void DrawTitle()
        {
            DrawText("Casual Racing League", static_cast<int>(GetScreenWidth() / HALF_SCREEN - (MeasureText("Casual Racing League", titleFont) / 2)), GetScreenHeight() / 5, titleFont, BLUE);
        }

        void DrawButtons()
        {
            DrawRectangleRec(play.buttonRec, play.actualColor);
            DrawText("PLAY", static_cast<int>(play.buttonRec.x + play.buttonRec.width / HALF_SCREEN) - (MeasureText("PLAY", 24) / 2), static_cast<int>(play.buttonRec.y + rectHeight / 3), buttonsFont, BLACK);

            DrawRectangleRec(instructions.buttonRec, instructions.actualColor);
            DrawText("Instructions", static_cast<int>(instructions.buttonRec.x + instructions.buttonRec.width / HALF_SCREEN) - (MeasureText("Instructions", 24) / 2), static_cast<int>(instructions.buttonRec.y + rectHeight / 3), buttonsFont, BLACK);

            DrawRectangleRec(exit.buttonRec, exit.actualColor);
            DrawText("Exit", static_cast<int>(exit.buttonRec.x + exit.buttonRec.width / 2) - (MeasureText("Exit", 24) / 2), static_cast<int>(exit.buttonRec.y + rectHeight / 3), buttonsFont, BLACK);

        }

        void DrawCredits()
        {
            int font = 15;
            int distanceX = 10;
            int distanceY1 = 10;
            int distanceY2 = 25;

            DrawText("Made with RAYLIB", distanceX, distanceY1, font, WHITE);

            DrawText("Lautaro G. Coccia", distanceX, GetScreenHeight() - distanceY2, font, WHITE);
        }
        
    }
}