//
// Created by benad on 9/23/2026.
//
#include <unordered_map>
#include "ShantenCalculator.h"

int ShantenCalculator::calculate_standard(const Hand &hand) const {
}


int ShantenCalculator::calculate_chiitoitsu(const Hand &hand) const {
    int shanten = 6;
    int unique = 0;
    std::unordered_map<int,int> in_hand;
    for(const auto tile: hand.getHand()){
        int index = tile.getIndex();
        in_hand[index]++;
    }
    for(auto const& x: in_hand){
         unique++;
         if(x.second >=2){
             shanten--;
         }
    }
    return shanten+std::max(0,7-unique);
}

int ShantenCalculator::calculate_orphens(const Hand& hand) const {
    int shanten = 13;
    std::unordered_map<int, int> in_hand;
    bool pair = false;
    for (const auto& tile : hand.getHand()) {
        if (tile.isSimple())
            continue;
        int index = tile.getIndex();
        in_hand[index]++;
        if (in_hand[index] == 1) {
            shanten--;
        }
        if (in_hand[index] == 2) {
            pair = true;
        }
    }
    if (pair) {
        shanten--;
    }
    return shanten;
}