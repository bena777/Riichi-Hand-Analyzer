//
// Created by benad on 9/23/2026.
//

#include "Tile.h"

Tile::Tile(Suit suit, int value) {
    this->suit = suit;
    this->value = value;
    if(this->suit == Suit::Man){
        this->index = this->value-1;
    } else if(this->suit == Suit::Pin){
        this->index = this->value+8;
    } else if(this->suit == Suit::Sou){
        this->index= this->value+17;
    } else{
        this->index = this->value+26;
    }
}

Suit Tile::getSuit() const {
    return this->suit;
}

int Tile::getValue() const {
    return this->value;
}

bool Tile::isHonor() const {
    if(this->suit == Suit::Honor){
        return true;
    }
    return false;
}

bool Tile::isTerminal() const {
    if((this->value == 1 || this->value == 9) && (this->suit != Suit::Honor)){
        return true;
    }
    return false;
}

bool Tile::isSimple() const {
    if(this->value == 1 || this->value == 9 || this->suit == Suit::Honor){
        return false;
    }
    return true;
}

int Tile::getIndex() const {
    return this->index;
}

bool Tile::operator==(const Tile &other) const {
    return this->suit == other.getSuit() && this->value == other.getValue();
}

bool Tile::operator<(const Tile &other) const {
    return this->index < other.index;
}