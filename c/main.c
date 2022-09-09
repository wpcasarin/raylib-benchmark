#include <stdlib.h>
#include "raylib.h"

const int screenWidth = 800;
const int screenHeight = 800;

int randomRange(int min, int max)
{
  return rand() % (max - min + 1) + min;
}

int main(void)
{
  InitWindow(screenWidth, screenHeight, "C bench");
  Image img = LoadImage("texture.png");
  Texture2D texture = LoadTextureFromImage(img);
  UnloadImage(img);
  while (!WindowShouldClose())
  {
    BeginDrawing();
    DrawFPS(700, 700);
    ClearBackground(BLACK);
    for (int i = 0; i < 5000; i++)
    {
      DrawTexture(texture, randomRange(0, 500), randomRange(0, 500), WHITE);
      // DrawTexture(texture, 100, 100, WHITE);
    }
    EndDrawing();
  }

  CloseWindow();

  return 0;
}