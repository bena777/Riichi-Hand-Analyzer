//
// Created by benad on 9/23/2026.
//

#ifndef MAHJONG_TILE_H
#define MAHJONG_TILE_H

enum class Suit{
    Man,
    Pin,
    Sou,
    Honor
};


class Tile {
private:
    Suit suit;
    int value;
    int index;
public:
    Tile(Suit suit, int value);
    Suit getSuit() const;
    int getValue() const;
    bool isHonor() const; // honors are represented as 1- east wind, 2- south wind, 3- west wind, 4- north wind, 5- white dragon, 6- green dragon, 7- red dragon
    bool isTerminal() const;
    bool isSimple() const;
    bool operator==(const Tile& other) const;
    bool operator<(const Tile& other) const;
    int getIndex() const; // index among the 34 tiles. 0-8 (man), 9-17 (pin), 18-26 (sou), 27-33 (honors)

};


#endif //MAHJONG_TILE_H
