//
// Created by benad on 9/23/2026.
//

#ifndef MAHJONG_HAND_H
#define MAHJONG_HAND_H
#include <vector>
#include "Tile.h"




class Hand {
private:
    std::vector<Tile> hand;
    int tiles[34]{};
public:
    Hand();
    Hand(std::vector<Tile> hand);
    bool addTile(const Tile& tile); // return true for successful
    bool removeTile(const Tile& tile); // return true for successful, false for failure
    const std::vector<Tile> getHand() const;
    bool isValid();
    bool isTenpai();
    void sort_tiles();
};


#endif //MAHJONG_HAND_H
