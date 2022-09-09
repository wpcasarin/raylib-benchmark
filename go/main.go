package main

import (
	"math/rand"

	rl "github.com/gen2brain/raylib-go/raylib"
)

const SCREEN_WIDTH = 600
const SCREEN_HEIGHT = 600

func random_in_range(min int, max int) int {
	return rand.Intn((max - min + 1) + min)
}

func main() {
	rl.InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Go bench")
	texture := rl.LoadTexture("texture.png")

	for !rl.WindowShouldClose() {
		rl.BeginDrawing()
		rl.DrawFPS(500, 550)
		rl.ClearBackground(rl.Black)
		for i := 0; i < 5000; i++ {
			rl.DrawTexture(texture, int32(random_in_range(0, 400)), int32(random_in_range(0, 400)), rl.White)
			// rl.DrawTexture(texture, 100, 100, rl.White)
		}
		rl.EndDrawing()
	}

	rl.CloseWindow()
}
