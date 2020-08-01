#include "game_manager.h"

#include "raylib.h"

#include "../game_scenes/main_menu.h"
#include "../game_scenes/gameplay.h"
#include "../game_scenes/instructions.h"
#include "players.h"
#include "../game_assets/sounds.h"

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
            InitScenes();
            Sounds::LoadMusic();
        }

        void InitScenes()
        {
            Main_Menu::InitMenu();
            Gameplay::InitGameplay();
            Players::InitPlayer1();
            Players::InitPlayer2();
            Instructions::InitInstructions();
        }

        void MainGameLoop()
        {
            InitializeWindowMainLoop();

            Texture2D background = LoadTexture("assets/background.png");

            while (!WindowShouldClose())    
            {   

                BeginDrawing();

                ClearBackground(BLACK);

                
                DrawTexture(background, screenWidth / 2 - background.width / 2, screenHeight / 2 - background.height / 2, WHITE);

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
                
            }

            Sounds::UnloadMusic();
            CloseWindow();       

        }

    }

}
