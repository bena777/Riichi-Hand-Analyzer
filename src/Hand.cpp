//
// Created by benad on 9/23/2026.
//

#include "Hand.h"


Hand::Hand(std::vector<Tile> hand) {
    this->hand = hand;
}

bool Hand::addTile(const Tile& tile) {
    if(hand.size() >= 14){
        return false;
    }
    this->hand.push_back(tile);
    return true;
}

bool Hand::removeTile(const Tile &tile) {
    for(int i=0; i < this->hand.size(); i++){
        if(this->hand[i] == tile){
            this->hand.erase(this->hand.begin()+i);
            return true;
        }
    }
    return false;
}