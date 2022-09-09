use rand::Rng;
use raylib::prelude::*;

const SCREEN_WIDTH: i32 = 800;
const SCREEN_HEIGHT: i32 = 800;

fn main() {
    let (mut rl, thread) = raylib::init()
        .size(SCREEN_WIDTH, SCREEN_HEIGHT)
        .title("Rust bench")
        .build();

    let t = rl
        .load_texture(&thread, "static/texture.png")
        .expect("could not load image");

    while !rl.window_should_close() {
        let mut d = rl.begin_drawing(&thread);
        d.draw_fps(700, 700);
        d.clear_background(Color::BLACK);
        for _ in 0..5000 {
            d.draw_texture(
                &t,
                rand::thread_rng().gen_range(0..500),
                rand::thread_rng().gen_range(0..500),
                Color::WHITE,
            )
            // d.draw_texture(
            //     &t,
            //     100,
            //     100,
            //     Color::WHITE,
            // )
        }
    }
}
