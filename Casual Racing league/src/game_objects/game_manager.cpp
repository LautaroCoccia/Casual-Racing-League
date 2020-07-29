#include "game_manager.h"

#include "raylib.h"



namespace Casual_Racing_League
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    namespace Game_Manager
    {
        void InitializeWindowMainLoop();


        void InitializeWindowMainLoop()
        {
            InitWindow(screenWidth, screenHeight, "Casual Racing League.exe");
            SetTargetFPS(60);
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
                BeginDrawing();

                ClearBackground(BLACK);

                DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

                EndDrawing();
                //----------------------------------------------------------------------------------
            }

            // De-Initialization
            //--------------------------------------------------------------------------------------
            CloseWindow();        // Close window and OpenGL context
            //--------------------------------------------------------------------------------------

        }

    }

}
