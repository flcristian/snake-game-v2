#ifndef TILE_H
#define TILE_H

#include <array>
#include <cstdlib>
#include <ctime>

class Tile {
    float posX;
    float posY;
    std::array<float, 12> vertices;
    std::array<float, 16> colors;

public:
    // Constructors
        
    Tile() {
        posX = -1;
        posY = -1;
        vertices = {};
    }

    Tile(int x, int y) {
        posX = x;
        posY = y;

        // Vertices
        vertices[0] = posX * TILE_SIZE + 1; vertices[1] = posY * TILE_SIZE + 1, vertices[2] = 0.0,
        vertices[3] = (posX + 1) * TILE_SIZE - 1; vertices[4] = posY * TILE_SIZE + 1; vertices[5] = 0.0,
        vertices[6] = (posX + 1) * TILE_SIZE - 1; vertices[7] = (posY + 1) * TILE_SIZE - 1; vertices[8] = 0.0;
        vertices[9] = posX * TILE_SIZE + 1; vertices[10] = (posY + 1) * TILE_SIZE - 1; vertices[11] = 0.0;

        // Colors
        setColors(0);
    }
    
    // Accessors

    int getX() { return posX; }
    int getY() { return posY; }
    float* getVertices() { return vertices.data(); }
    float* getColors(float time) {
        setColors(time);
        return colors.data();
    }

private:
    void setColors(float time) {
        // Bottom left color
        colors[0] = getColor(time, START_RED / 255.0f, END_RED / 255.0f, posX, posY);
        colors[1] = getColor(time, START_GREEN / 255.0f, END_GREEN / 255.0f, posX, posY);
        colors[2] = getColor(time, START_BLUE / 255.0f, END_BLUE / 255.0f, posX, posY);
        colors[3] = 1.0f;

        // Bottom right color
        colors[4] = getColor(time, START_RED / 255.0f, END_RED / 255.0f, posX + 1, posY);
        colors[5] = getColor(time, START_GREEN / 255.0f, END_GREEN / 255.0f, posX + 1, posY);
        colors[6] = getColor(time, START_BLUE / 255.0f, END_BLUE / 255.0f, posX + 1, posY);
        colors[7] = 1.0f;

        // Top right color
        colors[8] = getColor(time, START_RED / 255.0f, END_RED / 255.0f, posX + 1, posY + 1);
        colors[9] = getColor(time, START_GREEN / 255.0f, END_GREEN / 255.0f, posX + 1, posY + 1);
        colors[10] = getColor(time, START_BLUE / 255.0f, END_BLUE / 255.0f, posX + 1, posY + 1);
        colors[11] = 1.0f;

        // Top left color
        colors[12] = getColor(time, START_RED / 255.0f, END_RED / 255.0f, posX, posY + 1);
        colors[13] = getColor(time, START_GREEN / 255.0f, END_GREEN / 255.0f, posX, posY + 1);
        colors[14] = getColor(time, START_BLUE / 255.0f, END_BLUE / 255.0f, posX, posY + 1);
        colors[15] = 1.0f;
    }

    // Gets the value for the red/green/blue color for the point at (i,j)
    float getColor(float time, float startColor, float endColor, float i, float j) {
        std::srand(std::time(nullptr));
        int countI = SIZE_X * 2;
        int countJ = SIZE_Y * 2;

        float timeFactor = 0.0001f; // Change this to speed up or slow down the color change over time
        float t = time * timeFactor;
        float perlinNoise = 0.5f * (1 + sin(t));

        float result = startColor + (i / countI) * (endColor - startColor) + (j / countJ) * (endColor - startColor);
        return result + perlinNoise * (endColor - startColor);
    }
};

#endif //TILE_H
