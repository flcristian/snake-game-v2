#ifndef TILE_SERVICE_H
#define TILE_SERVICE_H

#include <vector>

#include "tile.h"

namespace tile_service {
    class TileService {
    private:
        std::vector<Tile>* tiles;
        int sizeX;
        int sizeY;

        TileService(int screenWidth, int screenHeight, int tileSize) {
            sizeX = screenWidth / tileSize;
            sizeY = screenHeight / tileSize;
            
            tiles = new std::vector<Tile>(sizeX * sizeY);

            for(int i = 0; i < sizeX; i++) {
                for(int j = 0; j < sizeY; j++) {
                    tiles->emplace_back(i, j, tileSize);
                }
            }
        }

        ~TileService() {
            delete tiles;
        }
        
    public:
        // Accessors

        std::vector<Tile>* getTiles() { return tiles; }
        int getSizeX() { return sizeX; }
        int getSizeY() { return sizeY; }
        
        // Methods
        
        Tile FindTile(int posX, int posY) {
            for(Tile tile : *tiles) {
                if(tile.getX() == posX && tile.getY() == posY) {
                    return tile;
                }
            }
            return {};
        }
        
        // Singleton
        
        TileService(TileService const&) = delete;
        TileService(TileService&&) = delete; 
        TileService& operator=(TileService const&) = delete; 
        TileService& operator=(TileService &&) = delete; 
        
        static TileService& getInstance(int screenWidth, int screenHeight, int tileSize) {
            static TileService instance(screenWidth, screenHeight, tileSize); // Instantiated on first use.
            return instance;
        }
    };
}

#endif
