#ifndef TILE_H
#define TILE_H

#include <array>

class Tile {
private:
    float posX;
    float posY;
    std::array<float, 12> vertices;

public:
    // Constructors
        
    Tile() {
        posX = -1;
        posY = -1;
        vertices = {};
    }

    Tile(int x, int y, int tileSize) {
        posX = x;
        posY = y;

        vertices[0] = posX * tileSize + 1; vertices[1] = posY * tileSize + 1, vertices[2] = 0.0,
        vertices[3] = (posX + 1) * tileSize - 1; vertices[4] = posY * tileSize + 1; vertices[5] = 0.0,
        vertices[6] = (posX + 1) * tileSize - 1; vertices[7] = (posY + 1) * tileSize - 1; vertices[8] = 0.0;
        vertices[9] = posX * tileSize + 1; vertices[10] = (posY + 1) * tileSize - 1; vertices[11] = 0.0;
    }
    
    // Accessors

    int getX() { return posX; }
    int getY() { return posY; }
    float* getVertices() { return vertices.data(); }
};

#endif //TILE_H
