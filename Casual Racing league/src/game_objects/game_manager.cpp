#include "game_manager.h"

#include "raylib.h"

#include "../game_scenes/main_menu.h"
#include "../game_scenes/gameplay.h"
#include "../game_scenes/instructions.h"

namespace Casual_Racing_League
{

    namespace Game_Manager
    {
        SCENE scene;

        const int screenWidth = 800;
        const int screenHeight = 450;

        void InitializeWindowMainLoop();
        void InitScenes();

        void InitializeWindowMainLoop()
        {
            InitWindow(screenWidth, screenHeight, "Casual Racing League.exe");
            SetTargetFPS(60);

            scene = menu;

            InitScenes();
        }

        void InitScenes()
        {
            Main_Menu::InitMenu();
            Gameplay::InitGameMode();
            Instructions::InitInstructions();
        }

        // Set our game to run at 60 frames-per-secondd
                //--------------------------------------------------------------------------------------

                // Main game loop
        void MainGameLoop()
        {
            InitializeWindowMainLoop();

            while (!WindowShouldClose())    // Detect window close button or ESC key
            {
                // Update
                //----------------------------------------------------------------------------------
                // TODO: Update your variables here
                //----------------------------------------------------------------------------------

                // Draw
                //----------------------------------------------------------------------------------
                ClearBackground(BLACK);

                BeginDrawing();

                switch (scene)
                {
                case menu:
                    Main_Menu::UpdateMenu();
                    break;
                case gameplay:
                    Gameplay::UpdateGameplay();
                    break;
                case instructions:
                    Instructions::UpdateInstructions();
                    break;
                }

                EndDrawing();
                //----------------------------------------------------------------------------------
            }

            // De-Initialization
            //--------------------------------------------------------------------------------------
            CloseWindow();        // Close window and OpenGL context

        }

    }

}
