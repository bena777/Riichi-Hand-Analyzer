//
// Created by benad on 9/23/2026.
//

#include "Hand.h"
#include <algorithm>

Hand::Hand(std::vector<Tile> hand) {
    this->hand = hand;
}

bool Hand::addTile(const Tile& tile) {
    if(hand.size() >= 14){
        return false;
    }
    this->hand.push_back(tile);
    this->tiles[tile.getIndex()]++;
    return true;
}

bool Hand::removeTile(const Tile &tile) {
    for(int i=0; i < this->hand.size(); i++){
        if(this->hand[i] == tile){
            this->hand.erase(this->hand.begin()+i);
            this->tiles[tile.getIndex()]--;
            return true;
        }
    }
    return false;
}

const std::vector<Tile> Hand::getHand() const {
    return this->hand;
}

void Hand::sort_tiles(){
    std::sort(this->hand.begin(),this->hand.end());
}