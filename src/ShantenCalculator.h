//
// Created by benad on 9/23/2026.
//

#ifndef MAHJONG_SHANTENCALCULATOR_H
#define MAHJONG_SHANTENCALCULATOR_H
#include "Hand.h"
#include <vector>
#include <unordered_map>

class ShantenCalculator {
public:
    int calculate_standard(const Hand& hand) const;
    int calculate_chiitoitsu(const Hand& hand) const;
    int calculate_orphens(const Hand& hand) const;
    int standard_shanten(int melds, int isolated, int pairs);
    int dfs_shanten(Hand hand, int melds, int isolated, int pairs);
};


#endif //MAHJONG_SHANTENCALCULATOR_H
