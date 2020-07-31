#include "players.h"

#include <math.h>

namespace Casual_Racing_League
{
    namespace Players
    {
        PLAYER player1;
        PLAYER player2;

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
            player1.collider.x = player1.position.x + sin(static_cast<double>(player1.rotation) * DEG2RAD) * (shipHeight / 2.5f);
            player1.collider.y = player1.position.y - cos(static_cast<double>(player1.rotation) * DEG2RAD) * (shipHeight / 2.5f);
            player1.collider.z = 12;
            player1.position.x = 200;
            player1.position.y = 200;
            player1.acceleration = INIT_SPEED;
        }
        void InitPlayer2()
        {
            
            player2.playerLap = FIRST_LAP_NUM;
            player2.collider.x = player2.position.x + sin(static_cast<double>(player2.rotation) * DEG2RAD) * (shipHeight / 2.5f);
            player2.collider.y = player2.position.y - cos(static_cast<double>(player2.rotation) * DEG2RAD) * (shipHeight / 2.5f);
            player2.collider.z = 12;
            player2.position.x = 200;
            player2.position.y = 200;
            player2.acceleration = INIT_SPEED;
        }

        void WinCondition()
        {

        }

        void InputPlayer1()
        {
            if (IsKeyDown(KEY_A)) player1.rotation -= 5;
            if (IsKeyDown(KEY_D)) player1.rotation += 5;


            player1.speed.x = sin(static_cast<double>(player1.rotation) * DEG2RAD) * PLAYER_SPEED;
            player1.speed.y = cos(static_cast<double>(player1.rotation) * DEG2RAD) * PLAYER_SPEED;


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


            player2.speed.x = sin(static_cast<double>(player2.rotation) * DEG2RAD) * PLAYER_SPEED;
            player2.speed.y = cos(static_cast<double>(player2.rotation) * DEG2RAD) * PLAYER_SPEED;


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
            Vector2 v1 = { player1.position.x + sinf(player1.rotation * DEG2RAD) * (shipHeight), player1.position.y - cosf(player1.rotation * DEG2RAD) * (shipHeight) };
            Vector2 v2 = { player1.position.x - cosf(player1.rotation * DEG2RAD) * (PLAYER_BASE_SIZE / 2), player1.position.y - sinf(player1.rotation * DEG2RAD) * (PLAYER_BASE_SIZE / 2) };
            Vector2 v3 = { player1.position.x + cosf(player1.rotation * DEG2RAD) * (PLAYER_BASE_SIZE / 2), player1.position.y + sinf(player1.rotation * DEG2RAD) * (PLAYER_BASE_SIZE / 2) };
            DrawTriangle(v1, v2, v3, MAROON);
        }
        void DrawPlayer2()
        {
            Vector2 v1 = { player2.position.x + sinf(player2.rotation * DEG2RAD) * (shipHeight), player2.position.y - cosf(player2.rotation * DEG2RAD) * (shipHeight) };
            Vector2 v2 = { player2.position.x - cosf(player2.rotation * DEG2RAD) * (PLAYER_BASE_SIZE / 2), player2.position.y - sinf(player2.rotation * DEG2RAD) * (PLAYER_BASE_SIZE / 2) };
            Vector2 v3 = { player2.position.x + cosf(player2.rotation * DEG2RAD) * (PLAYER_BASE_SIZE / 2), player2.position.y + sinf(player1.rotation * DEG2RAD) * (PLAYER_BASE_SIZE / 2) };
            DrawTriangle(v1, v2, v3, BLUE);
        }
    }
}