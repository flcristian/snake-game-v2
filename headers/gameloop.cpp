#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

#define SCREEN_WIDTH 900
#define SCREEN_HEIGHT 900

namespace game_loop {
    void StartGameLoop();
}