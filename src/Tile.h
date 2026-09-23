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
public:
    Tile(Suit suit, int value);
    Suit getSuit() const;
    int getValue() const;
    bool isHonor() const;
    bool isTerminal() const;
    bool isSimple() const;
    bool operator==(const Tile& other) const;

};


#endif //MAHJONG_TILE_H
