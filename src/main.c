#include "raylib.h"
#include <stdio.h>
#include <stdbool.h>
#include "flappy.h"
#include <stdlib.h>


int screenWidth = 800;
int screenHeight = 600;
int maxTubes = 100;
int score = 0;
char scoreLabel[] = "";
bool lost = false;



int main(void) {


    InitWindow(screenWidth, screenHeight, "Flappy Bird");
    SetTargetFPS(60);
    SetExitKey(KEY_NULL);
    
    int gameState = 0; // 0 = Pre-Game, 1 = Game, 2 = Post-Game


    Rectangle *pipe[maxTubes];
    Rectangle Pipe[maxTubes];
    Rectangle *pipeBottom[maxTubes];
    Rectangle PipeBottom[maxTubes];



    Player *flappy, Flappy;
    flappy = &Flappy;
    setValuePlayer(flappy);
    setValuePipe(pipe, Pipe, pipeBottom, PipeBottom);



    while (!WindowShouldClose()) {
        BeginDrawing();
        
        if (!lost && gameState == 1) {

        updatePlayerPosition(flappy, pipe);
        updatePipePosition(pipe, pipeBottom);


    

        for (int i = 0; i < maxTubes; i++) {
        if (CheckCollisionCircleRec((Vector2){ flappy->x, flappy->y}, flappy->radius, *pipe[i]) || CheckCollisionCircleRec((Vector2){ flappy->x, flappy->y}, flappy->radius, *pipeBottom[i])) {
            lost = true;
        }
    }

    }


        if (gameState == 0 && !lost) {
            DrawText("Press Enter to Start", screenWidth/2 - MeasureText("Press Enter to Start", 25)/2, screenHeight/2, 25, GREEN);
        }

        if (IsKeyPressed(KEY_ENTER) && gameState == 0) {
            gameState = 1;
            
        }




        
        ClearBackground(RAYWHITE);

        if (gameState == 1) {
        DrawCircle(flappy->x, flappy->y, flappy->radius, GREEN);


        for (int i = 0; i < maxTubes; i++) {
        DrawRectangleRec(*pipe[i], GREEN);
        DrawRectangleRec(*pipeBottom[i], GREEN);
    }

    }

        if (lost) {
            DrawText("You Lost!", screenWidth/2 - MeasureText("You Lost!", 20)/2, screenHeight/2, 20, BLACK);
            DrawText("Press Enter to Play Again", screenWidth/2 - MeasureText("Press Enter to Play Again", 20)/2, screenHeight/2 + 50, 20, BLACK);
            gameState = 2;
            score = 0;

        }

        if (lost && IsKeyPressed(KEY_ENTER) && gameState == 2) {
            gameState = 0;
            lost = false;
            setValuePlayer(flappy);
            setValuePipe(pipe, Pipe, pipeBottom, PipeBottom);            
        }



       


        EndDrawing();

    }


    CloseWindow();

    return 0;
}