#include <stdlib.h>
#include "raylib.h"

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

// Global Variables Definition
static const int screenWidth = 800;
static const int screenHeight = 800;

// Module functions declaration
void UpdateDrawFrame(Texture2D texture);
int randomRange(int min, int max);

// Entry point
int main(void)
{
    // Initialization
    InitWindow(screenWidth, screenHeight, "Webassembly Bench");
    Image img = LoadImage("/assets/texture.png");
    Texture2D texture = LoadTextureFromImage(img);
    // UnloadImage(img);
    // SetTargetFPS(60);

#if defined(PLATFORM_WEB)
    // emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
    emscripten_set_main_loop_arg((em_arg_callback_func)UpdateDrawFrame, (void *)&texture, 0, 1);
#else

    // Main game loop
    while (!WindowShouldClose())
    {
        UpdateDrawFrame(texture);
    }
#endif
    // De-Initialization
    CloseWindow();
    return 0;
}

void UpdateDrawFrame(Texture2D texture)
{
    // Update
    // TODO: Update your variables here

    // Draw
    BeginDrawing();
    ClearBackground(BLACK);
    DrawFPS(700, 700);
    for (int i = 0; i < 5000; i++)
    {
        DrawTexture(texture, randomRange(0, 500), randomRange(0, 500), WHITE);
        // DrawTexture(texture, 100, 100, WHITE);
    }
    EndDrawing();
}

int randomRange(int min, int max)
{
    return rand() % (max - min + 1) + min;
}