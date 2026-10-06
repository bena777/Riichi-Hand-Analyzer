//
// Created by benad on 9/23/2026.
//
#include "ShantenCalculator.h"

int ShantenCalculator::calculate_standard(const Hand &hand) const {
    Hand temp_hand = hand;
    temp_hand.sort_tiles();
    int shanten = 8;

}


int ShantenCalculator::dfs_shanten(Hand hand, int melds, int taatsu, int pairs) {
    hand.sort_tiles();
    int best = 8;
    std::vector<Tile> hand_vec = hand.getHand();
    if(hand_vec.empty()){
        return standard_shanten(melds,taatsu,pairs);
    }
    Tile first = hand_vec[0];
    Hand hand_2 = hand;
    if(hand_vec.size() >= 3 && hand_vec[1].getSuit() == first.getSuit() && hand_vec[2].getSuit() == first.getSuit()){ // recursive case of sequence OR triplet existing
        if((hand_vec[1].getValue() == first.getValue()+1 && hand_vec[2].getValue() == first.getValue()+2)
            || (hand_vec[1] == first && hand_vec[2] == first)){
            hand_2.removeTile(hand_vec[0]);
            hand_2.removeTile(hand_vec[1]);
            hand_2.removeTile(hand_vec[2]);
            best = std::min(best,this->dfs_shanten(hand_2,melds+1,taatsu,pairs));
            hand_2 = hand;
        }
    }
    if(hand_vec.size() >= 2 && hand_vec[1] == first){ // recursive case of pair existing
        hand_2.removeTile(hand_vec[0]);
        hand_2.removeTile(hand_vec[1]);
        best = std::min(best,this->dfs_shanten(hand_2,melds,taatsu,pairs+1));
        hand_2 = hand;
    }
    if(hand_vec.size() >= 2 && hand_vec[1].getSuit() == first.getSuit() && hand_vec[1].getValue() == first.getValue()+1){ // taatsu case, incomplete sequence (1-2), no gap
        hand_2.removeTile(hand_vec[0]);
        hand_2.removeTile(hand_vec[1]);
        best = std::min(best,this->dfs_shanten(hand_2,melds,taatsu+1,pairs));
        hand_2 = hand;
    }
    // taatsu case with gap, "skipping" over middle tile
    if (hand_vec.size() >= 3 && hand_vec[1].getSuit() == first.getSuit() && hand_vec[2].getSuit() == first.getSuit() && hand_vec[2].getValue() == first.getValue() + 2) {
        hand_2.removeTile(hand_vec[0]);
        hand_2.removeTile(hand_vec[2]);
        best = std::min(best,dfs_shanten(hand_2, melds, taatsu + 1, pairs));
        hand_2 = hand;
    }
    hand_2.removeTile(first); // final case that always executes of simply not using the first tile in anything
    best = std::min(best,this->dfs_shanten(hand_2,melds,taatsu,pairs));
    return best;
}

int ShantenCalculator::standard_shanten(int melds, int taatsu, int pairs) {
    int shanten = 8 - (2*melds)-std::min(taatsu+pairs,4-melds);
    if(pairs >= 1 && (melds+taatsu+pairs) >= 5){
        shanten--;
    }
    return shanten;
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