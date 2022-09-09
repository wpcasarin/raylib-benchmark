#/bin/bash

emcc -o game.html --embed-file ./assets main.c -Os -Wall ./libraylib.a -I. -I./libraylib.h -L. -L./libraylib.a -s USE_GLFW=3 --shell-file ./shell.html -DPLATFORM_WEB
