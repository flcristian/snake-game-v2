#ifndef TILE_SERVICE_H
#define TILE_SERVICE_H

#include <vector>

#include "tile.h"

namespace tile_service {
    class TileService {
    private:
        std::vector<Tile>* tiles;

        TileService() {
            tiles = new std::vector<Tile>(SIZE_X * SIZE_Y);

            for(int i = 0; i < SIZE_X; i++) {
                for(int j = 0; j < SIZE_Y; j++) {
                    tiles->emplace_back(i, j);
                }
            }
        }

        ~TileService() {
            delete tiles;
        }
        
    public:
        // Accessors

        std::vector<Tile>* getTiles() { return tiles; }
        
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
        
        static TileService& getInstance() {
            static TileService instance;
            return instance;
        }
    };
}

#endif
