#include "players.h"

#include <cmath>

namespace Casual_Racing_League
{
    namespace Players
    {
        PLAYER player1;
        PLAYER player2;
        
        Rectangle checkpoint1;
        Rectangle checkpoint2;
        Rectangle checkpoint3;
        Rectangle checkpoint4;
        
        static float shipHeight = 0.0f;

        const int FIRST_LAP_NUM = 1;
        const int LAST_LAP_NUM = 5;

        const float INIT_SPEED = 0.0f;
        const float MAX_SPEED = 1.0f;
        const float PLAYER_BASE_SIZE = 20.0f;
        const float PLAYER_SPEED = 6.0f;


        void InitPlayer1()
        {
            
            shipHeight = (PLAYER_BASE_SIZE / 2) / tanf(20 * DEG2RAD);
            player1.playerLap = FIRST_LAP_NUM;
            player1.collider.x = static_cast<float>(player1.position.x + sin(static_cast<double>(player1.rotation) * DEG2RAD) * (shipHeight / 2.5f));
            player1.collider.y = static_cast<float>(player1.position.y - cos(static_cast<double>(player1.rotation) * DEG2RAD) * (shipHeight / 2.5f));
            player1.collider.z = 12;
            player1.position.x = 100;
            player1.position.y = 200;
            player1.acceleration = INIT_SPEED;
            player1.win = false;
            
        }
        void InitPlayer2()
        {

            player2.playerLap = FIRST_LAP_NUM;
            player2.collider.x = player2.position.x + sin(static_cast<double>(player2.rotation) * DEG2RAD) * (shipHeight / 2.5f);
            player2.collider.y = player2.position.y - cos(static_cast<double>(player2.rotation) * DEG2RAD) * (shipHeight / 2.5f);
            player2.collider.z = 12;
            player2.position.x = 120;
            player2.position.y = 200;
            player2.acceleration = INIT_SPEED;
            player2.win = false;
        }

        void InputPlayer1()
        {
            if (IsKeyDown(KEY_A)) player1.rotation -= 5;
            if (IsKeyDown(KEY_D)) player1.rotation += 5;


            player1.speed.x = sin(static_cast<double>(player1.rotation) * DEG2RAD) * static_cast<double>(PLAYER_SPEED);
            player1.speed.y = cos(static_cast<double>(player1.rotation) * DEG2RAD) * static_cast<double>(PLAYER_SPEED);


            if (IsKeyDown(KEY_W))
            {
                if (player1.acceleration < 1) player1.acceleration += 0.04f;
            }
            else
            {
                if (player1.acceleration > 0) player1.acceleration -= 0.02f;
                else if (player1.acceleration < 0) player1.acceleration = 0;
            }

            if (IsKeyDown(KEY_DOWN))
            {
                if (player1.acceleration > 0) player1.acceleration -= 0.04f;
                else if (player1.acceleration < 0) player1.acceleration = 0;
            }


            player1.position.x += (player1.speed.x * player1.acceleration);
            player1.position.y -= (player1.speed.y * player1.acceleration);


        }

        void InputPlayer2()
        {
            if (IsKeyDown(KEY_LEFT)) player2.rotation -= 5;
            if (IsKeyDown(KEY_RIGHT)) player2.rotation += 5;


            player2.speed.x = sin(static_cast<double>(player2.rotation) * DEG2RAD) * static_cast<double>(PLAYER_SPEED);
            player2.speed.y = cos(static_cast<double>(player2.rotation) * DEG2RAD) * static_cast<double>(PLAYER_SPEED);


            if (IsKeyDown(KEY_UP))
            {
                if (player2.acceleration < 1) player2.acceleration += 0.04f;
            }
            else
            {
                if (player2.acceleration > 0) player2.acceleration -= 0.02f;
                else if (player2.acceleration < 0) player2.acceleration = 0;
            }
            if (IsKeyDown(KEY_DOWN))
            {
                if (player2.acceleration > 0) player2.acceleration -= 0.04f;
                else if (player2.acceleration < 0) player2.acceleration = 0;
            }

            player2.position.x += (player2.speed.x * player2.acceleration);
            player2.position.y -= (player2.speed.y * player2.acceleration);

        }

        void DrawPlayer1()
        {
            DrawText(FormatText("%i", player1.playerLap), static_cast<int>(50 - (MeasureText(FormatText("%i", player1.playerLap), 50) / 2)), GetScreenHeight() / 5, 50, RED);
            Vector2 v1 = { player1.position.x + sinf(player1.rotation * DEG2RAD) * (shipHeight), player1.position.y - cosf(player1.rotation * DEG2RAD) * (shipHeight) };
            Vector2 v2 = { player1.position.x - cosf(player1.rotation * DEG2RAD) * (PLAYER_BASE_SIZE / 2), player1.position.y - sinf(player1.rotation * DEG2RAD) * (PLAYER_BASE_SIZE / 2) };
            Vector2 v3 = { player1.position.x + cosf(player1.rotation * DEG2RAD) * (PLAYER_BASE_SIZE / 2), player1.position.y + sinf(player1.rotation * DEG2RAD) * (PLAYER_BASE_SIZE / 2) };
            DrawTriangle(v1, v2, v3, MAROON);
        }
        void DrawPlayer2()
        {
            DrawText(FormatText("%i", player2.playerLap), static_cast<int>(750 - (MeasureText(FormatText("%i", player2.playerLap), 50) / 2)), GetScreenHeight() / 5, 50, BLUE);
            Vector2 v1 = { player2.position.x + sinf(player2.rotation * DEG2RAD) * (shipHeight), player2.position.y - cosf(player2.rotation * DEG2RAD) * (shipHeight) };
            Vector2 v2 = { player2.position.x - cosf(player2.rotation * DEG2RAD) * (PLAYER_BASE_SIZE / 2), player2.position.y - sinf(player2.rotation * DEG2RAD) * (PLAYER_BASE_SIZE / 2) };
            Vector2 v3 = { player2.position.x + cosf(player2.rotation * DEG2RAD) * (PLAYER_BASE_SIZE / 2), player2.position.y + sinf(player2.rotation * DEG2RAD) * (PLAYER_BASE_SIZE / 2) };
            DrawTriangle(v1, v2, v3, BLUE);
        }

        void InitChecker()
        {
            checkpoint1 = { 55,200,100,10 };
            checkpoint2 = { 390, 50, 10, 50 };
            checkpoint3 = { 650, 200, 100, 10 };
            checkpoint4 = { 390, 340, 10, 50 };
        }

        void DrawChecker()
        {
            DrawRectangle(static_cast<int>(checkpoint1.x), static_cast<int>(checkpoint1.y), checkpoint1.width, checkpoint1.height, YELLOW);
            DrawRectangle(static_cast<int>(checkpoint2.x), static_cast<int>(checkpoint2.y), checkpoint2.width, checkpoint2.height, YELLOW);
            DrawRectangle(static_cast<int>(checkpoint3.x), static_cast<int>(checkpoint3.y), checkpoint3.width, checkpoint3.height, YELLOW);
            DrawRectangle(static_cast<int>(checkpoint4.x), static_cast<int>(checkpoint4.y), checkpoint4.width, checkpoint4.height, YELLOW);
        }
        
        void CollisionChecker()
        {
            if (CheckCollisionPointRec(player1.position, checkpoint2) && player1.checker == 0)
            {
                player1.checker++;
            }
            else if (CheckCollisionPointRec(player1.position, checkpoint3) && player1.checker == 1)
            {
                player1.checker++;

            }
            else if (CheckCollisionPointRec(player1.position, checkpoint4) && player1.checker == 2)
            {
                player1.checker++;

            }
            else if (CheckCollisionPointRec(player1.position, checkpoint1) && player1.checker == 3)
            {
                player1.checker = 0;
                player1.playerLap++;

            }

            if (CheckCollisionPointRec(player2.position, checkpoint2) && player2.checker == 0)
            {
                player2.checker++;
            }
            else if (CheckCollisionPointRec(player2.position, checkpoint3) && player2.checker == 1)
            {
                player2.checker++;

            }
            else if (CheckCollisionPointRec(player2.position, checkpoint4) && player2.checker == 2)
            {
                player2.checker++;

            }
            else if (CheckCollisionPointRec(player2.position, checkpoint1) && player2.checker == 3)
            {
                player2.checker = 0;
                player2.playerLap++;

            }
            
        }
        bool Player1Win()
        {
            if (player1.playerLap == 5)
            {
                player1.win = true;
            }
            return player1.win;
        }

        bool Player2Win()
        {
            if (player2.playerLap == 5)
            {
                player2.win = true;
            }
            return player2.win;
        }
    }
}