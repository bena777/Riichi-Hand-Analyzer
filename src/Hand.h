//
// Created by benad on 9/23/2026.
//

#ifndef MAHJONG_HAND_H
#define MAHJONG_HAND_H
#include <vector>
#include "Tile.h"




class Hand {
    std::vector<Tile> hand;
    Hand(std::vector<Tile> hand);
    bool addTile(const Tile& tile); // return true for successful
    bool removeTile(const Tile& tile); // return true for successful, false for failure
    bool isValid();
    bool isTenpai();
};


#endif //MAHJONG_HAND_H
