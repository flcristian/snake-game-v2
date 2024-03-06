#include "headers/game-loop.h"
#include "headers/tiles/tile-service.h"
#include "headers/tiles/tile.h"

int main()
{
    if (!glfwInit()) {
        return -1;
    }

    GLFWwindow *window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "OpenGL Project", nullptr, nullptr);

    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    
    glViewport(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    float time = 0;
    
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        tile_service::TileService& tileService = tile_service::TileService::getInstance();

        for(Tile tile : *tileService.getTiles()) {
            glEnableClientState(GL_VERTEX_ARRAY);
            glEnableClientState(GL_COLOR_ARRAY);
            
            glVertexPointer(3, GL_FLOAT, 0, tile.getVertices());
            glColorPointer(4, GL_FLOAT, 0, tile.getColors(time));
            glDrawArrays(GL_QUADS, 0, 4);
            
            glDisableClientState(GL_VERTEX_ARRAY);
            glDisableClientState(GL_COLOR_ARRAY);
            time++;
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
