#ifndef TILE_H
#define TILE_H

#include <array>

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

        // Bottom left color
        colors[0] = getColor(START_RED / 255.0f, END_RED / 255.0f, posX, posY);
        colors[1] = getColor(START_GREEN / 255.0f, END_GREEN / 255.0f, posX, posY);
        colors[2] = getColor(START_BLUE / 255.0f, END_BLUE / 255.0f, posX, posY);
        colors[3] = 1.0f;

        // Bottom right color
        colors[4] = getColor(START_RED / 255.0f, END_RED / 255.0f, posX + 1, posY);
        colors[5] = getColor(START_GREEN / 255.0f, END_GREEN / 255.0f, posX + 1, posY);
        colors[6] = getColor(START_BLUE / 255.0f, END_BLUE / 255.0f, posX + 1, posY);
        colors[7] = 1.0f;

        // Top right color
        colors[8] = getColor(START_RED / 255.0f, END_RED / 255.0f, posX + 1, posY + 1);
        colors[9] = getColor(START_GREEN / 255.0f, END_GREEN / 255.0f, posX + 1, posY + 1);
        colors[10] = getColor(START_BLUE / 255.0f, END_BLUE / 255.0f, posX + 1, posY + 1);
        colors[11] = 1.0f;

        // Top left color
        colors[12] = getColor(START_RED / 255.0f, END_RED / 255.0f, posX, posY + 1);
        colors[13] = getColor(START_GREEN / 255.0f, END_GREEN / 255.0f, posX, posY + 1);
        colors[14] = getColor(START_BLUE / 255.0f, END_BLUE / 255.0f, posX, posY + 1);
        colors[15] = 1.0f;
    }
    
    // Accessors

    int getX() { return posX; }
    int getY() { return posY; }
    float* getVertices() { return vertices.data(); }
    float* getColors() { return colors.data(); }

private:
    // Gets the value for the red/green/blue color for the point at (i,j)
    float getColor(float startColor, float endColor, float i, float j) {
        int countI = SIZE_X * 2;
        int countJ = SIZE_Y * 2;
        return startColor + (i / countI) * (endColor - startColor) + (j / countJ) * (endColor - startColor);
    }
};

#endif //TILE_H
