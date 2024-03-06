cmake_minimum_required(VERSION 3.27)
project(snake_game_v2)

set(SCRIPTS_DIR "${PROJECT_SOURCE_DIR}/scripts")
set(HEADERS_DIR "${PROJECT_SOURCE_DIR}/headers")
set(LUA_DIR "C:/lua/")
set(GLEW_LIB_PATH "C:/opengl/glew/lib/Release/x64/")
set(GLFW_LIB_PATH "C:/opengl/glfw/lib-vc2022/")
set(GLEW_INCLUDE_PATH "C:/opengl/glew/include")
set(GLFW_INCLUDE_PATH "C:/opengl/glfw/include")

include_directories(${GLEW_INCLUDE_PATH} ${GLFW_INCLUDE_PATH})

add_library(
        lua STATIC
        ${LUA_DIR}/lapi.c
        ${LUA_DIR}/lauxlib.c
        ${LUA_DIR}/lbaselib.c
        ${LUA_DIR}/lcode.c
        ${LUA_DIR}/lcorolib.c
        ${LUA_DIR}/lctype.c
        ${LUA_DIR}/ldblib.c
        ${LUA_DIR}/ldebug.c
        ${LUA_DIR}/ldo.c
        ${LUA_DIR}/ldump.c
        ${LUA_DIR}/lfunc.c
        ${LUA_DIR}/lgc.c
        ${LUA_DIR}/linit.c
        ${LUA_DIR}/liolib.c
        ${LUA_DIR}/llex.c
        ${LUA_DIR}/lmathlib.c
        ${LUA_DIR}/lmem.c
        ${LUA_DIR}/loadlib.c
        ${LUA_DIR}/lobject.c
        ${LUA_DIR}/lopcodes.c
        ${LUA_DIR}/loslib.c
        ${LUA_DIR}/lparser.c
        ${LUA_DIR}/lstate.c
        ${LUA_DIR}/lstring.c
        ${LUA_DIR}/lstrlib.c
        ${LUA_DIR}/ltable.c
        ${LUA_DIR}/ltablib.c
        ${LUA_DIR}/ltm.c
        ${LUA_DIR}/lua.c
        ${LUA_DIR}/lundump.c
        ${LUA_DIR}/lutf8lib.c
        ${LUA_DIR}/lvm.c
        ${LUA_DIR}/lzio.c
)

find_library(GLEW_LIB glew32 ${GLEW_LIB_PATH})
find_library(GLFW_LIB glfw3 ${GLFW_LIB_PATH})

add_executable(
        snake_game_v2
        main.cpp
        headers/game-loop.h
        headers/includes.h
        headers/definitions.h
        headers/tiles/tile-service.h
        headers/functions.h
        headers/tiles/tile.h
)

target_link_libraries(snake_game_v2 ${GLEW_LIB} ${GLFW_LIB} opengl32 lua)

target_include_directories(snake_game_v2 PRIVATE ${LUA_DIR})