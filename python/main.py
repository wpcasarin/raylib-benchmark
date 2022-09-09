import random
import sys

import pyray as rl
import raylib as rc
from raylib import colors

SCREEN_WIDTH = 800
SCREEN_HEIGHT = 800
FPS = 60


def pyversion():
    rl.init_window(SCREEN_WIDTH, SCREEN_HEIGHT, "Python Bench")
    texture = rl.load_texture("texture.png")
    while not rl.window_should_close():
        rl.begin_drawing()
        rl.draw_fps(700, 700)
        rl.clear_background(colors.BLACK)
        for i in range(5000):
            rl.draw_texture(texture, random.randint(0, 500),
                            random.randint(0, 500), (255, 255, 255, 255))
        rl.end_drawing()
    rl.close_window()
    sys.exit()


def cversion():
    rc.InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, b"TESTE")
    texture = rc.LoadTexture(b"texture.png")
    while not rc.WindowShouldClose():
        rc.BeginDrawing()
        rc.DrawFPS(700, 700)
        rc.ClearBackground(colors.BLACK)
        for i in range(5000):
            rc.DrawTexture(texture, random.randint(0, 500),
                           random.randint(0, 500), (255, 255, 255, 255))
            # rc.DrawTexture(texture, 100, 100, (255, 255, 255, 255))
        rc.EndDrawing()
    rc.CloseWindow()
    sys.exit()


if __name__ == "__main__":
    # pyversion()
    cversion()
